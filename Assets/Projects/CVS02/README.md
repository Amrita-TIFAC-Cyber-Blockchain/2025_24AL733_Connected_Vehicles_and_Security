# 24AL733 - Connected Vehicles and Security 

## CVS01 - 

![](https://img.shields.io/badge/Member--gold) ![](https://img.shields.io/badge/Member--gold) <br/> 
![](https://img.shields.io/badge/SDG--darkgreen) ![](https://img.shields.io/badge/SDG--darkgreen) <br/> 

![](https://img.shields.io/badge/Reviewed--brown) <br/>

### Problem Statement
Modern vehicles rely on in-vehicle communication networks to enable real-time data exchange between multiple Electronic Control Units (ECUs). The Controller Area Network (CAN) protocol has been widely adopted due to its reliability and deterministic timing. However, the increasing number of ECUs and data-intensive vehicle functions have exposed bandwidth and latency limitations in traditional CAN-based networks.

To address these limitations, CAN with Flexible Data Rate (CAN FD) was introduced, offering higher payload capacity and improved communication performance. While existing studies demonstrate significant performance improvements with CAN FD, both CAN and CAN FD lack native security mechanisms such as authentication, encryption, and access control.

As a result, in-vehicle networks remain vulnerable to cyber-attacks such as message spoofing, replay attacks, and denial-of-service, even in CAN FD-based architectures. Most existing solutions address security using external mechanisms like intrusion detection systems or secure gateways, rather than inherent protocol-level protections.

The core problem addressed in this project is to analyze and compare the security vulnerabilities of traditional CAN and CAN FD, and to determine whether CAN FD provides any inherent security improvement or simply enhances communication performance while inheriting the same vulnerabilities.
   
-----
### Hardware Requirements

| ✅ Available | Components | Purpose |
|:---------:|---------------|:-----------------------------------------------------------------------------------------------|
  NA        | Not Applicable| This project's focus is on simulation of security capabilities and vulnerabilities of CAN and CAN FD.|

###  Software Requirements

| ✅ Available | Components                         | Purpose                                                                 |
|-------------|------------------------------------|-------------------------------------------------------------------------|
   ✅         |      Vector CANOe                 |   Used to understand and analyze CAN and CAN FD network behavior, frame structure, bus load, and communication                                                         characteristics based on simulation and literature-supported scenarios.|
   ✅         |      MATLAB Simulink              |   Used for conceptual modeling and visualization of CAN and CAN FD communication flow and for supporting                                                               comparative analysis based on reported performance metrics in literature.|
-----
### [Literature Survey](./R1/README.md) 
Paper 1: Addressing Vulnerabilities in CAN-FD: An Exploration and Security Enhancement Approach

Authors: Naseeruddin Lodge, Nahush Tambe, Fareena Saqib

This paper studies the security weaknesses present in both traditional CAN and CAN FD communication protocols. The authors point out that although CAN FD improves data rate and payload size, it does not introduce any built-in security features such as authentication or encryption. The paper discusses several attack scenarios including message injection, replay attacks, bus flooding, and denial-of-service attacks. It also reviews different security enhancement methods such as cryptographic techniques, physical unclonable functions, and blockchain-based solutions. However, most of these approaches require additional hardware support or increase system complexity. The authors conclude that CAN FD mainly improves communication performance while inheriting the same security limitations as classical CAN. This work clearly highlights the need to analyze CAN FD from a security perspective rather than viewing it only as a performance upgrade.


Paper 2: Fingerprinting Electronic Control Units for Vehicle Intrusion Detection

Authors: Kyong-Tak Cho, Kang G. Shin

This paper focuses on intrusion detection in CAN-based vehicle networks by proposing a clock-based ECU fingerprinting approach. The authors explain that CAN messages do not include sender identification, which makes the network vulnerable to spoofing attacks. To address this, they propose a detection method based on message timing behavior to identify abnormal ECU activity. Although the paper mainly considers traditional CAN, the identified vulnerability is also applicable to CAN FD since both protocols share the same communication principles. The proposed solution detects attacks only after they occur and does not prevent them at the protocol level. This study emphasizes the lack of inherent security in CAN-based systems and supports the argument that CAN FD also depends on external security mechanisms.


Paper 3: The CAN FD Network Performance Analysis Using CANoe

Authors: Bomu Cheon, Jae Wook Jeon

This paper presents a performance analysis of CAN FD using the Vector CANoe simulation tool. The authors compare CAN FD with traditional CAN by evaluating parameters such as bus load, response time, and real-time performance under different traffic conditions. The results show that CAN FD performs better than CAN, especially in high-load scenarios, due to its higher data rate and larger payload size. However, the paper focuses entirely on communication efficiency and timing behavior. Security aspects such as vulnerability to cyber-attacks or message manipulation are not discussed. This highlights a limitation in existing research, where CAN FD is evaluated mainly for performance without considering security implications.


Paper 4: Comparative Analysis of CAN-FD and 10BASE-T1S Ethernet for Time-Critical Automotive Applications

Authors: Christina Hein, Kirsten Matheus, Joachim Berlak

This paper compares CAN FD with Automotive Ethernet (10BASE-T1S) for use in time-critical automotive applications. The study analyzes latency, determinism, and communication efficiency under different network conditions. The authors show that while CAN FD improves upon traditional CAN, Ethernet-based solutions offer greater scalability and future potential. Security aspects are not analyzed in detail, and the focus remains on performance and real-time characteristics. The comparison suggests that CAN FD is mainly an intermediate solution rather than a complete replacement for future in-vehicle networks. This paper indirectly supports the need to understand CAN FD’s limitations, including its security vulnerabilities.


Paper 5: Immunity of CAN, CAN FD and Automotive Ethernet to Crosstalk from Power Electronic Systems

Authors: Carina Austermann, Stephan Frei

This paper evaluates the robustness of CAN, CAN FD, and Automotive Ethernet against electromagnetic interference caused by power electronic systems. The authors conduct experimental tests to analyze signal quality and noise immunity. CAN FD shows improved performance in certain conditions due to enhanced error detection mechanisms. However, the study is limited to physical-layer disturbances and does not consider cybersecurity threats. Attacks such as spoofing or denial-of-service are outside the scope of this work. The paper demonstrates that improved physical reliability does not necessarily result in improved security, which is an important distinction for connected vehicle systems.


Paper 6: CAN FD Controller for In-Vehicle System

Authors: Jung Woo Shin, Jung Hwan Oh, Sang Muk Lee, Seung Eun Lee

This paper discusses the design and implementation of a CAN FD controller suitable for automotive applications. The authors describe the controller architecture, frame structure modifications, and compatibility with existing CAN systems. The main focus is on improving communication efficiency and controller performance. Security mechanisms such as encryption or authentication are not addressed. This indicates that CAN FD development has primarily targeted performance improvement, while security has been left to higher-level solutions. The paper supports the motivation of this project by showing that CAN FD does not inherently resolve security concerns present in traditional CAN.

------

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










