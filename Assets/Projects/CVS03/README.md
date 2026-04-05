# 24AL733 - Connected Vehicles and Security 

## CVS03 - Role of 5G in Vehicle-to-Everything (V2X) Communication

![](https://img.shields.io/badge/Member-Ravindrakumar_Bhoi-gold) ![](https://img.shields.io/badge/Member-Shivang_Sood-gold) <br/> 
![](https://img.shields.io/badge/SDG--darkgreen) ![](https://img.shields.io/badge/SDG--darkgreen) <br/> 

![](https://img.shields.io/badge/Reviewed--brown) <br/>

### Problem Statement
<div align="justify">
5G networks rely on small cells with limited coverage range, typically a few hundred meters. To maintain seamless connectivity, a moving device must perform handovers—switching its connection from one small cell to the next—in mere milliseconds.
Consider a vehicle traveling at 120 km/h (approximately 33 m/s). At this speed, it covers the diameter of a typical small cell in just seconds. If the vehicle enters a coverage gap, known as a "dead zone," or encounters a delayed handover due to network congestion, overloaded signaling, or interference, the connection may drop abruptly. This can interrupt data-intensive applications like streaming, navigation, or emerging autonomous driving features, highlighting the challenges of providing reliable high-speed mobile coverage in dense 5G deployments.
</div>

-----

### Use Case 
<div align="justify">
If the vehicle is relying on Remote Driving (Tele-operation) or cloud-based AI for navigation, the connection drops. The vehicle essentially "goes blind" for 1–2 seconds. In a high-speed curve or intersection, this brief loss of control results in a departure from the lane or a collision with infrastructure. 
</div>

-----
### Hardware Requirements

| Available | Components    | Version |                     Purpose                                           |
|-----------|---------------|---------|-----------------------------------------------------------------------|
|  NA       |     NA        |   NA    |Project's main focus is on simulating the scenarios using NS-3 software|

-----

###  Software Requirements

| Available | Components    | Version                         | Purpose                               |
|-----------|---------------|-------------------------------- |---------------------------------------|
|   ✅      |      NS-3     |            3.44                 |ns-3 (Network Simulator 3) is a popular open-source, discrete-event network simulator designed for academic research and education.|
|   ✅      |    5G-LENA    |            4.1.1                |5G-LENA is an open-source 5G New Radio (NR) network simulator, designed as a pluggable module to ns-3.
-----
### Literature Review

1. Look Before Switch: Sensing-Assisted Handover in 5G NR V2I Network.
   * Authors: Fan Liu et al. (corresponding author: Fan Liu)
   * Source: arXiv preprint arXiv:2511.05195, November 2025
   * Focus: This work proposes a sensing-assisted handover framework using Integrated Sensing and Communication (ISAC) to address handover interruptions in high mobility 5G NR Vehicle-to-Infrastructure (V2I) scenarios, particularly for C-V2X applications where frequent handovers cause latency spikes and connectivity drops.
   * Contributions:
       * Integrates sensing data to predict and prepare handovers proactively ("look before switch").
       * Reduces average handover interruption time by over 50% (from ~43 ms baseline).
       * Evaluated in high-speed vehicular contexts, improving reliability for safety-critical V2X services compared to traditional DSRC or standard C-V2X.
    * Link: [Look Before Switch: Sensing-Assisted Handover in 5G NR V2I Network](https://arxiv.org/pdf/2511.05195)


2. Intelligent Handover Decision-Making for Vehicle-to-Everything (V2X) 5G Networks
   * Authors: Faiza Rashid, Ammar Al Harthi, et al.
   * Source: Telecom (MDPI), Volume 6, Issue 3, Article 47, July 2025
   * Focus: The paper introduces an enhanced handover optimization method for 5G V2X networks, tackling inefficiencies in high-mobility environments like dense urban or highway scenarios where traditional methods lead to frequent failures or ping-pong effects.
   * Contributions:
     * Employs Multi-Criteria Decision-Making (MCDM) with the Technique for Order of Preference by Similarity to Ideal Solution (TOPSIS) for context-aware decisions.
     * Improves handover success rate, reduces latency, and enhances scalability using real-world vehicular mobility traces.
     * Demonstrates better performance in high-speed UEs compared to baseline 5G handover schemes.
   * Link: [Intelligent Handover Decision-Making for Vehicle-to-Everything (V2X) 5G Networks](https://www.mdpi.com/2673-4001/6/3/47)


3. GCN-Based Throughput-Oriented Handover Management in Dense 5G Vehicular Networks
   * Authors: Not explicitly detailed in summary (funded by NSERC Discovery grants)
   * Source: arXiv preprint arXiv:2505.04894, May 2025
   * Focus: Addresses 5G's challenges in ultra-dense vehicular networks, including limited coverage, frequent handovers, and the "ping-pong effect" that causes instability in high-mobility scenarios.
   * Contributions:
       * Proposes a Graph Convolutional Network (GCN)-based approach for throughput-oriented handover decisions.
       * Optimizes handover targets to maximize user throughput while minimizing interruptions.
       * Validated with simulations showing reduced handover failures and improved stability in dense, high-speed vehicular deployments.
    * Link: [GCN-Based Throughput-Oriented Handover Management in Dense 5G Vehicular Networks](https://arxiv.org/abs/2505.04894)

4. LSHA: A Lightweight and Secure Handover Authentication Scheme Based on Wireless Key for 5G-V2X
   * Authors: Not explicitly listed in abstracts (IEEE VTC conference team)
   * Source: IEEE Vehicular Technology Conference (VTC2025-Spring), 2025
   * Focus: Proposes a lightweight handover authentication scheme using wireless key generation to secure 5G-V2X communications during frequent handovers in high-mobility vehicular scenarios, mitigating cybersecurity threats such as impersonation attacks, man-in-the-middle attacks, and desynchronization that can cause connection drops or increased latency.
   * Contributions:
       * Reduces transmitted data by 29% and communication delay by 31.8% compared to standard 5G handover authentication.
       * Enhances security without heavy computational overhead, suitable for resource-constrained vehicular devices.
       * Demonstrates robustness against common attacks while maintaining low-latency handovers in high-speed V2X environments.
   * Link: [LSHA: A Lightweight and Secure Handover Authentication Scheme Based on Wireless Key for 5G-V2X](https://ieeexplore.ieee.org/document/11174801)

5. Wall-Street: Smart Surface-Enabled 5G mmWave for Roadside Networking
   * Authors: Not explicitly detailed in summary (arXiv/cs.NI team)
   * Source: arXiv preprint arXiv:2405.06754v3, October 2025
   * Focus: Introduces a vehicle-mounted smart surface (reconfigurable intelligent surface) to mitigate frequent handovers, beam alignment issues, and signal blockages in high-speed 5G mmWave roadside networks, enabling more reliable connectivity for in-vehicle users at vehicular speeds.
   * Contributions:
       * Enables collective handover decisions for multiple users inside the vehicle and neighbor-cell search without data interruption.
       * Supports make-before-break handovers for zero or near-zero interruption time.
       * Implemented and tested in real testbeds (e.g., COSMOS), demonstrating reduced service interruptions in high-mobility driving scenarios.
   * Link: [Wall-Street: Smart Surface-Enabled 5G mmWave for Roadside Networking](https://arxiv.org/pdf/2405.06754)

6. Optimizing Handover Mechanism in Vehicular Networks Using Deep Learning and Optimization Techniques
   * Authors: A.C.P. K. Siriwardhana, Jingling Yuan, Zhishu Shen, et al.
   * Source: Computer Networks (ScienceDirect), Volume 270, October 2025, 111488
   * Focus: Proposes a novel handover management approach for 5G-enabled vehicular networks to handle high mobility and dynamic density, reducing latency and improving reliability for V2X applications in challenging high-speed scenarios.
   * Contributions:
       * Integrates K-means clustering, Deep Maxout Network (DMN), and Dung Beetle Optimizer (DBO) for intelligent handover decisions.
       * Enhances connectivity reliability and meets stringent low-latency requirements in 5G V2X.
       * Evaluated performance gains in high-mobility vehicular environments, showing reduced handover failures and better support for data-intensive services like streaming and autonomous features.
   * Link: [Optimizing Handover Mechanism in Vehicular Networks Using Deep Learning and Optimization Techniques](https://www.sciencedirect.com/science/article/pii/S1389128625004554)

-----
### Implementation Details
#### Installing/Building NS-3 with NR and 5G-LENA
##### 1. Prerequisites
```
 sudo apt update
 sudo apt install git cmake g++ python3 python3-dev pkg-config sqlite3 libsqlite3-dev
```

##### 2. Nevigate to NS-3 github repository
NS-3 Github repository https://github.com/nsnam/ns-3-dev-git

##### 3. Clone the repository
```
 git clone https://gitlab.com/nsnam/ns-3-dev.git
 cd ns-3-dev
```

##### 4. Clone 5G-LENA Module
Navigate to the contrib directory and clone the 5G-LENA repository.
```
 cd contrib
 git clone https://gitlab.com/cttc-lena/nr.git
 cd ..
```
Ensure the nr module version matches your ns-3 version. Versions listed in software requirements.

##### 5. Configure and Build:
Configure NS-3 to include the new module and build the project.
```
 ./ns3 configure --enable-examples --enable-tests
 ./ns3 build
```

##### 6. Verify Installation:
Run a 5G-LENA example to verify the installation.
```
 ./ns3 run cttc-nr-demo
```

#### How to run the code in NS-3
Create the file(.cc file) in scratch folder of ns-3. I am using fresh text editor.
```
 fresh scratch/5g-rlf-highway.cc
```
build and run. file extension is not needed while running the script.
```
./ns3 run scratch/5g-rlf-highway
```

#### Vairent of attack simulation script

The attack simulation has attack mode as:
* attack=none → No attack (just observe blind zone packet loss)
* attack=stop → Attacker stops the vehicle (default)
* attack=reverse → Attacker reverses the vehicle

How to run?
```
# 1. Default: Stop attack
./ns3 run "scratch/5g-rlf-highway-attack --attack=stop"

# 2. Reverse attack
./ns3 run "scratch/5g-rlf-highway-attack --attack=reverse"

# 3. No attack (just to observe blind zone)
./ns3 run "scratch/5g-rlf-highway-attack --attack=none"
```
### PyViz visualizer 
NS-3 PyViz is a live simulation visualizer for the ns-3 network simulator. 
* Function: Unlike offline tools, it provides real-time visualization of simulations to help debug mobility models and packet drops.
* Controls: It allows users to interactively drag nodes and view interface statistics during the simulation run.

How to run script in PyViz?
```
#by simply adding --vis argument at the end we can simulate the script in PyViz visualizer
#for e.g.

./ns3 run scratch/5g-rlf-highway --vis

./ns3 run "scratch/5g-rlf-highway-attack --attack=stop" --vis
```
### NetAnim
NetAnim is a Qt5-based, standalone tool for visualizing ns-3 simulations, creating offline animations from XML trace files. It displays network topologies, node mobility, and packet flows.

#### Quick setup of NetAnim
Prerequisits
```
sudo apt-get install qt5-default # For older Ubuntu
# OR for newer versions:
sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```
```
cd ns-allinone-3.x.x/netanim-3.xxx/
make clean
qmake NetAnim.pro # Use 'qmake-qt5' if 'qmake' points to Qt4
make
./NetAnim
```
import xml file in NetAnim GUI and simulate

-----
### Proposed Solution

The image describes *Dynamic Telemetry*, a specialized network optimization feature designed to improve handover reliability for high-speed users (like those in cars or trains) by adjusting signaling parameters in real-time.

In standard 4G/5G networks, the logic for switching from one cell to another is often "static," meaning it uses fixed timers and thresholds. This feature makes those triggers "elastic" based on how fast you are moving.

#### Key Components of Dynamic Telemetry
The text highlights three technical levers the network pulls to prevent *RLF (Radio Link Failure)*:

- *Doppler Shift Measurement:* As you move toward or away from a cell tower at 120 km/h, the frequency of the radio waves shifts. The network uses this shift to calculate your exact spatial velocity.

- *TTT (Time-to-Trigger) Compression:* Usually, a phone must prove that a new cell is better than the current one for a set period (e.g., 320ms) before switching. For a fast vehicle, 320ms is too long—you might already be out of range. Dynamic Telemetry compresses (shortens) this timer so the handover happens instantly.

- *Hysteresis Margin Adjustment:* This is the "buffer" required to prevent the phone from bouncing back and forth between two towers. By dynamically lowering this margin for fast-moving nodes, the network allows for a "snappier" transition to the stronger signal.

#### Why it Matters

Without this feature, a vehicle traveling at high speeds often experiences a "Too Late Handover." By the time the static logic decides to switch, the signal from the original tower has dropped so low that the handover command cannot be received, resulting in a dropped call or lost data session.
Dynamic Telemetry essentially "fast-forwards" the decision-making process to keep up with the physical speed of the device.

-----
#### Architecture Diagram

![Architecture](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/8e47c11d99969741890bab64e36f30cc30d345cc/Assets/Projects/CVS03/images/Architecture.jpeg)

###### Layered Architecture

![Layered_architecture](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/8e47c11d99969741890bab64e36f30cc30d345cc/Assets/Projects/CVS03/images/Layered_architecture.png)

-----
#### Usecases

##### Autonomous and Connected Vehicles (V2X)

This is the most critical use case. Self-driving cars rely on V2X (Vehicle-to-Everything) communication to "see" around corners.

##### The Need
A car moving at 120 km/h covers 33 meters every second. If it loses connection for just 0.5 seconds during a handover, it misses 16 meters of real-time sensor data from the infrastructure (like a warning about a stalled car ahead).

##### The Use
Dynamic Telemetry ensures the "control plane" never drops, allowing the car to receive constant safety updates and coordinate lane merges in real-time.

-----

#### Deliverables

| Deliverable Type | Example | Purpose 
| :--- | :--- | :--- |
| **Logic** | Compressed TTT Algorithms | Speeds up the "Decision to Switch" |
| **Data** | Doppler-to-Velocity Mapping | Provides the "Context" for the switch |
| **Proof** | RLF Reduction Report | Proves the "Reliability" of the solution |
| **Code** | gNodeB Firmware Patch | The "Implementation" of the solution 

------
### Mapping the Project to Relevant Sustainable Development Goals (SDGs)

The Indian government (NITI Aayog) has emphasized that *5G* is not just a consumer play but a foundational utility. Your project specifically maps to:
* PM Gati Shakti:* The National Master Plan for multi-modal connectivity requires various transport systems to "talk" to each other in real-time.
* Indigenous 5G/6G Stack:* By developing solutions like Dynamic Telemetry, India reduces reliance on foreign intellectual property, aligning with the "Make in India" initiative.
* Safety & Security:* High-speed handover reliability is a prerequisite for the mass deployment of CCTV and emergency response systems in public transport.


| SDG                    | Alignment                                                                                                      |
|:-----------------------|:---------------------------------------------------------------------------------------------------------------|
| SDG 9 (Infrastructure) |By optimizing 5G handovers for high-velocity nodes                                                              |
| SDG 11 (Smart Cities)  |ensuring that India’s 2026 digital infrastructure is resilient, safe, and inclusive of high-speed mobility users|

-----
### Collaboration 
| Team | Module & Scope | Contribution |
|:----:|:--------------------------|:-------------|
|  NA  |          NA               |   NA         |
-----

### References
[1] Look Before Switch: Sensing-Assisted Handover in 5G NR V2I Network https://arxiv.org/pdf/2511.05195 <br>
[2] Intelligent Handover Decision-Making for Vehicle-to-Everything (V2X) 5G Networks https://www.mdpi.com/2673-4001/6/3/47 <br>
[3] GCN-Based Throughput-Oriented Handover Management in Dense 5G Vehicular Networks https://arxiv.org/abs/2505.04894 <br>
[4] LSHA: A Lightweight and Secure Handover Authentication Scheme Based on Wireless Key for 5G-V2X https://ieeexplore.ieee.org/document/11174801 <br>
[5] Wall-Street: Smart Surface-Enabled 5G mmWave for Roadside Networking https://arxiv.org/pdf/2405.06754 <br>
[6] Optimizing Handover Mechanism in Vehicular Networks Using Deep Learning and Optimization Techniques https://www.sciencedirect.com/science/article/pii/S1389128625004554 <br>
[7] Installing 5G-Lena 3GPP-NR module on ns-3.36 under Debian OS https://www.projectguideline.com/installing-5g-lena-3gpp-nr-module-on-ns-3-36-under-debian-os/ <br>
[8] Open Simulations (OpenSim) https://www.cttc.cat/open-simulations-opensim/ <br>
[9] 5G-LENA https://github.com/QiuYukang/5G-LENA <br>

