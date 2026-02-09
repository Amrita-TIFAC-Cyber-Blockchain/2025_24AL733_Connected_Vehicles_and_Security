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

| Available | Components    | Version |                     Purpose                                          |
|-----------|---------------|---------|----------------------------------------------------------------------|
|  NA       |     NA        |   NA    |Project's main focus is on simulating the scenarios using Omnet++ IDE.|

-----

###  Software Requirements

| Available | Components    | Version                         | Purpose                               |
|-----------|---------------|-------------------------------- |---------------------------------------|
|   ✅      |      Omnet++  |            5.6.2                |**OMNeT++** is an extensible, modular, component-based **C++** simulation library and framework, primarily used for building network simulators.|
|   ✅      |      Inet     |            4.2.2                |**INET Framework** is the standard open-source model library for **OMNeT++**. It provides ready-to-use, detailed implementations of a wide range of communication network protocols and components.|
|   ✅      |      Veins    |            5.2                  |**Veins** is an open-source framework for the detailed simulation of vehicular ad-hoc networks (**VANETs**).  It acts as a bridge between two specialized simulators to create a realistic environment for testing Intelligent Transportation Systems (ITS).|
|   ✅      |      Simu-5G  |            1.1.0                |**Simu5G** is an open-source simulation library for **OMNeT++** and **INET**, providing the 5G evolution of the well-known **SimuLTE** 4G simulator.|
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
### Proposed Solution

#### Architecture Diagram

#### Usecases

#### Deliverables

------
### Mapping the Project to Relevant Sustainable Development Goals (SDGs)

| SDG   | Alignment  |
|:---------------|:-----|


### Collaboration 
| Team | Module & Scope | Contribution |
|:----:|:--------------------------|:-------------|

-----

### References
