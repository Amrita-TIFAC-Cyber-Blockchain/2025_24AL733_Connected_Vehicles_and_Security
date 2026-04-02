#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/lte-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/ipv4-flow-classifier.h"
#include <cstdlib> // Required for Zenity system calls

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("HighwayHandoverFailure");

// Global tracking for real-time reporting
Time g_lastPacketTime = Seconds(0);
bool g_isLosingPackets = false;
Ptr<Node> g_ueNode; // Pointer to get X-coordinate for logs and popups

// Trace sink for successful reception
void PacketReceivedSink(std::string context, Ptr<const Packet> p, const Address &ad)
{
    g_lastPacketTime = Simulator::Now();
    if (g_isLosingPackets) {
        std::cout << "\033[1;32m[" << g_lastPacketTime.GetSeconds() << "s] Receiving packets...\033[0m" << std::endl;
        g_isLosingPackets = false;
    }
    
    static double lastPrint = 0;
    if (g_lastPacketTime.GetSeconds() - lastPrint >= 1.0) {
        Ptr<MobilityModel> mob = g_ueNode->GetObject<MobilityModel>();
        int xPos = (int)mob->GetPosition().x;
        std::cout << "[" << g_lastPacketTime.GetSeconds() << "s] Receiving packets at x=" << xPos << "m" << std::endl;
        lastPrint = g_lastPacketTime.GetSeconds();
    }
}

// Check for reception gaps to trigger "Packet Loss" alerts and Zenity Popup
void CheckLoss()
{
    Time now = Simulator::Now();
    
    // Get current position for terminal and popup
    Ptr<MobilityModel> mob = g_ueNode->GetObject<MobilityModel>();
    int xPos = (int)mob->GetPosition().x;

    // 100ms gap indicates loss given the 10ms packet interval
    if (now - g_lastPacketTime > MilliSeconds(100) && now > Seconds(0.6)) {
        if (!g_isLosingPackets) {
            std::cout << "\033[1;31m[" << now.GetSeconds() << "s] Packet loss detected at x=" << xPos << "m!\033[0m" << std::endl;
            g_isLosingPackets = true;

            // TRIGGER LINUX POPUP
            // --warning: Yellow alert icon
            // --timeout=2: Closes itself after 2 seconds
            // &: Background execution so simulation clock doesn't stop
            std::string alertCmd = "zenity --warning --title='ns-3 Alert' --text='Packet Loss at " + std::to_string(xPos) + "m' --timeout=2 &";
            int result = std::system(alertCmd.c_str());
            (void)result; 
        } else {
             static double lastLossPrint = 0;
             if (now.GetSeconds() - lastLossPrint >= 0.5) {
                 std::cout << "\033[1;31m[" << now.GetSeconds() << "s] Packet loss ongoing at x=" << xPos << "m...\033[0m" << std::endl;
                 lastLossPrint = now.GetSeconds();
             }
        }
    }
    Simulator::Schedule(MilliSeconds(50), &CheckLoss);
}

int main(int argc, char* argv[])
{
    // Environment Configurations
    double distance = 1200.0; 
    double speed = 33.33;    // 120 km/h
    uint16_t txPower = 40;   
    double hysteresis = 5.0;
    uint32_t ttt = 256;      // ms
    std::string pathloss = "ns3::FriisPropagationLossModel";
    Time simTime = Seconds(25); 

    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    Config::SetDefault("ns3::LteEnbPhy::TxPower", DoubleValue(txPower));
    Config::SetDefault("ns3::LteHelper::UseIdealRrc", BooleanValue(false)); 

    Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
    Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper>();
    lteHelper->SetEpcHelper(epcHelper);

    lteHelper->SetAttribute("PathlossModel", StringValue(pathloss));

    // Handover settings
    lteHelper->SetHandoverAlgorithmType("ns3::A3RsrpHandoverAlgorithm");
    lteHelper->SetHandoverAlgorithmAttribute("Hysteresis", DoubleValue(hysteresis)); 
    lteHelper->SetHandoverAlgorithmAttribute("TimeToTrigger", TimeValue(MilliSeconds(ttt)));

    NodeContainer enbNodes, ueNodes;
    enbNodes.Create(2);
    ueNodes.Create(1);
    g_ueNode = ueNodes.Get(0); // Store for position tracking

    MobilityHelper mobility;
    Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator>();
    positionAlloc->Add(Vector(0, 0, 30));           
    positionAlloc->Add(Vector(distance, 0, 30));    
    mobility.SetPositionAllocator(positionAlloc);
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(enbNodes);

    mobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
    mobility.Install(ueNodes);
    g_ueNode->GetObject<ConstantVelocityMobilityModel>()->SetPosition(Vector(10, 0, 1.5));
    g_ueNode->GetObject<ConstantVelocityMobilityModel>()->SetVelocity(Vector(speed, 0, 0));

    NetDeviceContainer enbDevs = lteHelper->InstallEnbDevice(enbNodes);
    NetDeviceContainer ueDevs = lteHelper->InstallUeDevice(ueNodes);

    InternetStackHelper internet;
    internet.Install(ueNodes);
    Ipv4InterfaceContainer ueIp = epcHelper->AssignUeIpv4Address(ueDevs);
    lteHelper->Attach(ueDevs.Get(0), enbDevs.Get(0));

    uint16_t dlPort = 1234;
    UdpClientHelper client(ueIp.GetAddress(0), dlPort);
    client.SetAttribute("Interval", TimeValue(MilliSeconds(10))); 
    client.SetAttribute("MaxPackets", UintegerValue(1000000));
    ApplicationContainer clientApp = client.Install(epcHelper->GetPgwNode());
    
    PacketSinkHelper sink("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), dlPort));
    ApplicationContainer sinkApp = sink.Install(ueNodes.Get(0));

    sinkApp.Start(Seconds(0.1));
    clientApp.Start(Seconds(0.5));

    sinkApp.Get(0)->TraceConnect("Rx", "UE_App_Context", MakeCallback(&PacketReceivedSink));
    
    Simulator::Schedule(Seconds(0.6), &CheckLoss);

    FlowMonitorHelper flowmon;
    Ptr<FlowMonitor> monitor = flowmon.InstallAll();

    Simulator::Stop(simTime);
    Simulator::Run();

    // FINAL SUMMARY
    monitor->CheckForLostPackets();
    Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier>(flowmon.GetClassifier());
    std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats();

    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- TOWER (gNodeB) CONFIGURATIONS ---" << std::endl;
    std::cout << "  Tower Spacing:         " << distance << "m" << std::endl;
    std::cout << "  Transmission Power:    " << txPower << " dBm" << std::endl;
    std::cout << "  Pathloss Model:        " << pathloss << std::endl;
    std::cout << "  Handover Hysteresis:   " << hysteresis << " dB" << std::endl;
    std::cout << "  Time to Trigger (TTT): " << ttt << " ms" << std::endl;
    std::cout << "  Vehicle Speed:         120 km/h" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (auto const& [id, stat] : stats)
    {
        Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow(id); 
        if (t.destinationAddress == ueIp.GetAddress(0))
        {
            std::cout << "==========================================" << std::endl;
            std::cout << "\n--- FLOW STATISTICS ---" << std::endl;
            std::cout << "Flow ID " << id << " (" << t.sourceAddress << " -> " << t.destinationAddress << ")" << std::endl;
            std::cout << "  Packets Sent:     " << stat.txPackets << std::endl;
            std::cout << "  Packets Received: " << stat.rxPackets << std::endl;
            std::cout << "  LOST:     " << stat.lostPackets << std::endl;
            std::cout << "  Loss %:   " << (double)stat.lostPackets/stat.txPackets*100 << "%" << std::endl;
            std::cout << "==========================================" << std::endl;
        }
    }

    Simulator::Destroy();
    return 0;
}