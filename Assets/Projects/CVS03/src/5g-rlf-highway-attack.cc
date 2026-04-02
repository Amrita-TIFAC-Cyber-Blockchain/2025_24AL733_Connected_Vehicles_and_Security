#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/lte-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/ipv4-flow-classifier.h"
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("HighwayBlindZoneAttack");

// Global variables
Time g_lastPacketTime = Seconds(0);
bool g_isLosingPackets = false;
bool g_attacked = false;
bool g_simulationStopped = false;
Ptr<Node> g_ueNode;
std::string g_attackType = "stop";
Time g_lossThreshold = MilliSeconds(150);   // NEW: configurable

// Packet reception trace
void PacketReceivedSink(std::string context, Ptr<const Packet> p, const Address &ad)
{
    g_lastPacketTime = Simulator::Now();

    if (g_isLosingPackets) {
        std::cout << "\033[1;32m[" << g_lastPacketTime.GetSeconds() << "s] Receiving packets again...\033[0m" << std::endl;
        g_isLosingPackets = false;
    }

    static double lastPrint = 0.0;
    if (!g_attacked && (g_lastPacketTime.GetSeconds() - lastPrint >= 1.0)) {
        Ptr<MobilityModel> mob = g_ueNode->GetObject<MobilityModel>();
        int xPos = (int)mob->GetPosition().x;
        std::cout << "\033[1;32m[" << g_lastPacketTime.GetSeconds() << "s] Receiving packets at x=" << xPos << "m\033[0m" << std::endl;
        lastPrint = g_lastPacketTime.GetSeconds();
    }
}

// Blind zone + Attack
void CheckLoss()
{
    if (g_simulationStopped) return;

    Time now = Simulator::Now();
    Ptr<MobilityModel> mob = g_ueNode->GetObject<MobilityModel>();
    double xPos = mob->GetPosition().x;

    if (now - g_lastPacketTime > g_lossThreshold && now > Seconds(0.6)) {
        if (!g_isLosingPackets) {
            std::cout << "\033[1;31m[" << now.GetSeconds() << "s] Packet loss detected at x=" 
                      << (int)xPos << "m ! (Blind zone entered)\033[0m" << std::endl;
            g_isLosingPackets = true;

            if (!g_attacked && g_attackType != "none") {
                g_attacked = true;

                Ptr<ConstantVelocityMobilityModel> velMob = g_ueNode->GetObject<ConstantVelocityMobilityModel>();
                Vector currVel = velMob->GetVelocity();
                double origSpeed = std::abs(currVel.x);

                std::string action = (g_attackType == "stop") ? "STOPPED" : "REVERSED DIRECTION";
                velMob->SetVelocity(Vector((g_attackType == "stop" ? 0.0 : -origSpeed), 0.0, 0.0));

                std::cout << "\033[1;31m[" << now.GetSeconds() << "s] *** ATTACKER STRIKES! Vehicle " 
                          << action << " at x=" << (int)xPos << "m ***\033[0m" << std::endl;

                std::string cmd = "zenity --error --title='🚨 BLIND ZONE ATTACK SUCCESS' "
                                  "--text='Position: " + std::to_string((int)xPos) 
                                  + "m\nVehicle " + action + "' --timeout=5 &";
                std::system(cmd.c_str());

                g_simulationStopped = true;
                Simulator::Schedule(Seconds(1.0), []() {
                    std::cout << "\n\033[1;33m=== SIMULATION STOPPED DUE TO SUCCESSFUL ATTACK ===\033[0m\n" << std::endl;
                    Simulator::Stop();
                });
            }
        }
    }
    Simulator::Schedule(MilliSeconds(80), &CheckLoss);
}

int main(int argc, char* argv[])
{
    double distance = 1200.0;
    double speed = 33.33;
    uint16_t txPower = 40;
    double hysteresis = 3.0;      // Lowered a bit for better handover response
    uint32_t ttt = 160;           // Lowered for faster handover
    std::string pathloss = "ns3::FriisPropagationLossModel";

    CommandLine cmd(__FILE__);
    cmd.AddValue("attack",    "Attack mode: none | stop | reverse", g_attackType);
    cmd.AddValue("distance",  "Distance between eNBs (m)", distance);
    cmd.AddValue("speed",     "Vehicle speed (m/s)", speed);
    cmd.AddValue("txpower",   "eNB Tx Power (dBm)", txPower);
    cmd.AddValue("loss",      "Packet loss detection threshold (ms)", g_lossThreshold);
    cmd.Parse(argc, argv);

    if (g_attackType != "none" && g_attackType != "stop" && g_attackType != "reverse")
        g_attackType = "stop";

    std::cout << "\n=== 5G Highway Blind Zone Attack Simulation ===" << std::endl;
    std::cout << "   Attack Mode      : " << g_attackType << std::endl;
    std::cout << "   Tower Spacing    : " << distance << " m" << std::endl;
    std::cout << "   Tx Power         : " << txPower << " dBm" << std::endl;
    std::cout << "   Vehicle Speed    : " << speed * 3.6 << " km/h" << std::endl;
    std::cout << "   Loss Threshold   : " << g_lossThreshold.GetMilliSeconds() << " ms\n" << std::endl;

    Config::SetDefault("ns3::LteEnbPhy::TxPower", DoubleValue(txPower));
    Config::SetDefault("ns3::LteHelper::UseIdealRrc", BooleanValue(false));

    Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
    Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper>();
    lteHelper->SetEpcHelper(epcHelper);
    lteHelper->SetAttribute("PathlossModel", StringValue(pathloss));

    lteHelper->SetHandoverAlgorithmType("ns3::A3RsrpHandoverAlgorithm");
    lteHelper->SetHandoverAlgorithmAttribute("Hysteresis", DoubleValue(hysteresis));
    lteHelper->SetHandoverAlgorithmAttribute("TimeToTrigger", TimeValue(MilliSeconds(ttt)));

    NodeContainer enbNodes(2), ueNodes(1);
    g_ueNode = ueNodes.Get(0);

    MobilityHelper mobility;
    Ptr<ListPositionAllocator> posAlloc = CreateObject<ListPositionAllocator>();
    posAlloc->Add(Vector(0, 0, 30));
    posAlloc->Add(Vector(distance, 0, 30));
    mobility.SetPositionAllocator(posAlloc);
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

    sinkApp.Get(0)->TraceConnect("Rx", "", MakeCallback(&PacketReceivedSink));
    Simulator::Schedule(Seconds(0.6), &CheckLoss);

    FlowMonitorHelper flowmon;
    Ptr<FlowMonitor> monitor = flowmon.InstallAll();

    Simulator::Stop(Seconds(30));
    Simulator::Run();

    // Final Summary (same as before)
    monitor->CheckForLostPackets();
    Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier>(flowmon.GetClassifier());
    auto stats = monitor->GetFlowStats();

    std::cout << "\n==========================================" << std::endl;
    std::cout << "--- SIMULATION SUMMARY ---" << std::endl;
    std::cout << "  Tower Spacing : " << distance << " m" << std::endl;
    std::cout << "  Tx Power      : " << txPower << " dBm" << std::endl;
    std::cout << "  Vehicle Speed : " << speed * 3.6 << " km/h" << std::endl;
    std::cout << "  Attack Mode   : " << g_attackType << std::endl;
    std::cout << "  Attack Result : " << (g_attacked ? "SUCCESS" : "No attack") << std::endl;
    std::cout << "==========================================" << std::endl;

    for (auto& [id, stat] : stats) {
        if (auto t = classifier->FindFlow(id); t.destinationAddress == ueIp.GetAddress(0)) {
            std::cout << "  Packets Sent     : " << stat.txPackets << std::endl;
            std::cout << "  Packets Received : " << stat.rxPackets << std::endl;
            std::cout << "  Packets Lost     : " << stat.lostPackets << std::endl;
            std::cout << "  Loss %           : " << (stat.txPackets ? 100.0 * stat.lostPackets / stat.txPackets : 0) << "%" << std::endl;
        }
    }

    Simulator::Destroy();
    return 0;
}