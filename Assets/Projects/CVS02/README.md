# 24AL733 - Connected Vehicles and Security 

## CVS02 - CAN FD vs Traditional CAN: Vulnerability Analysis

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
CAN Model:

<img width="800" height="413" alt="image" src="https://github.com/user-attachments/assets/6a09693b-74db-42df-b553-7a4a1bf017c2" />
<br>
<br>
CAN FD Model:
<br>
<br>
<img width="1591" height="813" alt="image" src="https://github.com/user-attachments/assets/ec1525aa-753a-486b-944b-8188aa2968ae" />


#### Usecases
1. ADAS communication
2. Diagnostics and logging
3. Powertrain control
4. Body control modules
5. Modern vehicle architectures


#### Deliverables
CAN Results :

1. Brake State
<img width="1599" height="811" alt="image" src="https://github.com/user-attachments/assets/0fc98f10-fe61-4a04-814e-6f750a0166ef" />
<br>

2. Brake Replay Attack

<br>

In this setup, a legitimate ECU transmits a speed value of 60 km/h at a lower frequency, while a rogue node injects a spoofed message with the same ID at a much higher frequency, carrying a value of 200 km/h. Due to the absence of authentication in CAN, the receiving nodes accept both messages, but the higher transmission rate of the attacker causes the spoofed value to dominate. This is clearly visible in the Trace, Data, and Graphics panels, where the system primarily reflects the malicious value.
<br>

<img width="1599" height="820" alt="image" src="https://github.com/user-attachments/assets/a35139b3-edc9-4af1-9687-fd90c578bf80" />

3.Log

Due to the 8-byte payload limitation of Classical CAN, only lightweight security mechanisms such as a small MAC and counter-based 
freshness can be implemented. These enable detection and logical rejection of attacks, but not protocol-level prevention.

<br>

Classical CAN lacks native security; we implemented application-layer authentication and replay protection, achieving detection and logical prevention, but not physical blocking of malicious messages

<br>

<img width="1592" height="804" alt="image" src="https://github.com/user-attachments/assets/602a1e5b-4d05-43f6-b9e5-5dfdef89a1e9" />

CAN FD Results :

1. Brake State and Replay Attack

<img width="1599" height="809" alt="image" src="https://github.com/user-attachments/assets/7549ebc6-1e03-4670-ba43-12fc07b7de2c" />

<br>

2.Log

<br>

<img width="1599" height="813" alt="image" src="https://github.com/user-attachments/assets/3da07376-d607-4121-94b9-0ab62eaf90e5" />



------
### Mapping the Project to Relevant Sustainable Development Goals (SDGs)

| SDG   | Alignment  |
|:---------------|:-----|


### Collaboration 
| Team | Module & Scope | Contribution |
|:----:|:--------------------------|:-------------|

-----

### References










