# 24AL733 - Connected Vehicles and Security 

## CVS01 - 

![](https://img.shields.io/badge/Member--gold) ![](https://img.shields.io/badge/Member--gold) <br/> 
![](https://img.shields.io/badge/SDG--darkgreen) ![](https://img.shields.io/badge/SDG--darkgreen) <br/> 

![](https://img.shields.io/badge/Reviewed--brown) <br/>

### **Problem Statement: Lightweight Intrusion Detection System (IDS) for CAN FD Networks**

Modern vehicles increasingly rely on Controller Area Network with Flexible Data Rate (CAN FD) for high-speed and larger payload communication between Electronic Control Units (ECUs). While CAN FD improves bandwidth and efficiency compared to classical CAN, it inherits critical security limitations:

No encryption
No authentication
Broadcast-based communication
No sender verification

These vulnerabilities expose in-vehicle networks to attacks such as:

Message spoofing
Replay attacks
Denial-of-Service (DoS)
Fuzzing attacks

Existing IDS solutions often rely on:
Heavy machine learning models
Cloud-based computation
High memory and processing resources

However, automotive ECUs are resource-constrained systems, typically featuring:

Limited RAM (tens to hundreds of KB)
Limited Flash memory
Real-time constraints
Low-cost MCU platforms

Therefore, deploying computationally expensive IDS mechanisms on production ECUs is impractical.

### **Literature Survey**

<img width="1402" height="727" alt="image" src="https://github.com/user-attachments/assets/03f8bba7-9213-4ad4-8bbd-1bc71cac1059" />
<img width="1051" height="590" alt="image" src="https://github.com/user-attachments/assets/f714bb56-e5a1-4572-b88d-d68b06c96ef3" />

