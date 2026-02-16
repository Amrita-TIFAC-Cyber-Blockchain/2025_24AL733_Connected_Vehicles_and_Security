# 24AL733 - Connected Vehicles and Security 

## CVS01 - Privacy Concerns and Mitigation in Connected Vehicles

![](https://img.shields.io/badge/Member--gold) ![](https://img.shields.io/badge/Member--gold) <br/> 
![](https://img.shields.io/badge/SDG--darkgreen) ![](https://img.shields.io/badge/SDG--darkgreen) <br/> 

![](https://img.shields.io/badge/Reviewed--brown) <br/>

### Problem Statement
Connected vehicles broadcast periodic safety messages to enable collision detection and avoidance. These messages contain essential parameters such as vehicle location, speed, direction, and timestamp, allowing nearby vehicles to compute relative distance and predict potential crash risks in real time.
While continuous broadcasting improves road safety, it also introduces a significant privacy risk. Because safety messages are transmitted openly over wireless channels, an unauthorized passive observer can collect and correlate successive identifiers and location updates over time. Even when temporary identifiers (pseudonyms) are used, if they remain static for extended durations, an attacker can reconstruct vehicle trajectories and infer travel behavior without the user’s knowledge or consent.
Existing privacy-preserving approaches, including RSU-assisted pseudonym coordination, dynamic mix-zone strategies, and cryptographic authentication frameworks, aim to reduce tracking risks. However, these solutions often depend on roadside infrastructure, complex coordination mechanisms, or computationally intensive cryptographic operations, making them difficult to deploy efficiently in resource-constrained real-world environments.
At the same time, connected vehicle systems must preserve accountability. Vehicles involved in accidents or legal incidents must remain traceable to authorized authorities under legitimate conditions. Many existing approaches do not clearly illustrate how privacy preservation and lawful traceability can coexist in a simple and transparent manner.
Therefore, the problem addressed in this work is:
How can unauthorized passive tracking during collision detection message broadcasting be mitigated using a lightweight pseudonym-change mechanism, while preserving conditional traceability for authorized authorities and without relying on infrastructure-heavy or cryptography-intensive solutions.
   
-----
### Hardware Requirements

| ✅ Available | Components | Purpose |
|:---------:|---------------|:-----------------------------------------------------------------------------------------------|
No specialized hardware is required. 
The project is implemented using software-based simulation tools (e.g., Python). 
Platform: Standard Laptop (8GB RAM recommended).

###  Software Requirements

| ✅ Available | Components                         | Purpose                                                                 |
|-------------|------------------------------------|-------------------------------------------------------------------------|
Operating System Windows 10/11
SUMO           Open-source traffic simulator Used to generate realistic vehicle mobility traces Provides real-time vehicle position, speed, and route data (Integrated with Python using TraCI API)
Programming Environment Safety message generation Passive tracking attack simulation Pseudonym change implementation Privacy metric evaluation
Python Libraries TraCI – Interface between SUMO and Python NumPy – Numerical operations Pandas – Data logging and analysisMatplotlib / Seaborn – Visualization of tracking results Scikit-learn (optional) – For computing advanced linkability metrics
Development Tools VSCode
Data Handling CSV files for logging safety messages Python scripts for post-simulation analysis

Visualization of results
-----
### [Literature Survey](./R1/README.md) 
Paper :Anonymity Assurance Using Efficient Pseudonym Consumption in Internet of Vehicles – Sensors 2023
Method Used:
Proposes Efficient Pseudonym Consumption Protocol (EPCP). Vehicles share BSMs only with nearby vehicles moving in similar direction and estimated location. Pseudonym change alerts are optimized to reduce unnecessary consumption.
Results:
Simulations show reduced pseudonym consumption, lower BSM loss rate, and improved traceability resistance compared to baseline schemes.
Limitation:
Requires estimation of vehicle trajectory and context-based coordination. Focuses on pseudonym efficiency rather than demonstrating real tracking attack reconstruction.
Gap Identified:
Does not experimentally show how passive tracking occurs or quantify tracking success before/after pseudonym change in a lightweight scenario.

Paper: RFPM: A RSU-aided framework for pseudonym management to preserve location privacy in IoV – Security & Privacy 
Method Used:
RSU-assisted PKI-based pseudonym management framework. RSUs collect, shuffle, and redistribute pseudonyms. Evaluated in PREXT simulator using metrics such as traceability, anonymity set, confusion matrix, entropy.
Results:
Shows improved privacy metrics compared to existing mix-zone and mix-context schemes. Provides formal privacy gain analysis.
Limitation:
Relies heavily on RSU infrastructure and VPKI coordination. Infrastructure cost and scalability not fully addressed.
Gap Identified:
Does not provide infrastructure-light or standalone vehicle-based mitigation suitable for simplified deployments.

Paper:Cybersecurity and Privacy Protection in VANETs – Advances in Internet of Things
Method Used:
Survey-based analysis of pseudonymization schemes (DLP, K-anonymity, Mix-Zone, AMOEBA, RSP). Emphasizes regulatory compliance (GDPR, LGPD) and privacy-by-design approaches.
Results:
Conceptual comparison of privacy schemes and regulatory implications. Highlights legal necessity of pseudonymization.
Limitation:
No simulation-based evaluation. No attack modeling. Focus is regulatory and conceptual rather than implementation.
Gap Identified:
Lacks experimental validation of tracking attacks and mitigation performance.

Paper:ADMZ – Adaptive Dynamic Mix-Zone Strategy (2023)
Method Used:
Dynamic mix-zone creation based on vehicle density and mobility patterns. Vehicles change pseudonyms inside adaptive zones.
Results:
Improves anonymity set size and reduces semantic linking probability under dense traffic.
Limitation:
Effective primarily in high-density areas. Performance degrades in sparse traffic. Requires coordination mechanism.
Gap Identified:
Does not address lightweight pseudonym change in low infrastructure or sparse environments.

Paper:A Pseudonym-Based Certificateless Privacy-Preserving Authentication Scheme for VANETs
Method Used:
Certificateless cryptographic authentication scheme to ensure anonymity and conditional traceability. Eliminates certificate management overhead of traditional PKI
Results:
Reduces computational overhead compared to certificate-based schemes while preserving message authenticity.
Limitation:
Focuses on authentication security rather than tracking attack mitigation analysis. Still cryptography-intensive.
Gap Identified:
Does not experimentally quantify passive tracking resistance via pseudonym strategy.

Paper: A Review of Pseudonym Change Strategies for Location Privacy
Method Used:
Systematic classification of mix-zone and mix-context pseudonym change techniques. Discusses syntactic vs semantic linking attacks.
Results:
Identifies strengths and weaknesses of silent period, cooperative change, density-based, and infrastructure-based strategies.
Limitation:
Review paper – no new framework or empirical evaluation.
Gap Identified:
Highlights absence of universally accepted lightweight, practical pseudonym change mechanism with measurable tracking mitigation.

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






