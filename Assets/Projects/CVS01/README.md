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

The proposed mitigation operates as an edge-computed software simulation. While no specialized roadside hardware (RSUs) or automotive On-Board Units (OBUs) are physically required to execute the testbed, the simulation environment relies heavily on concurrent processing. The TraCI Python controller, the SUMO physics engine, and the Streamlit data analytics dashboard run simultaneously, making multi-core processing and fast memory I/O highly beneficial.

| Component | Minimum Specification | Recommended Specification | Engineering Justification |
| :--- | :--- | :--- | :--- |
| **Processor (CPU)** | Intel Core i5 / AMD Ryzen 5 (Quad-Core) | Intel Core i7 / AMD Ryzen 7 (8+ Cores) | Multi-threading is highly beneficial for running the SUMO physics engine and the background `attacker.py` heuristic tracking script concurrently without frame drops. |
| **Memory (RAM)** | 8 GB | 16 GB | 8GB is sufficient for a 100-vehicle grid. 16GB ensures fluid rendering of the Streamlit dashboard while processing large Pandas dataframes (`trajectories.json`) in memory. |
| **Storage** | 5 GB Free Space (HDD) | 10 GB Free Space (NVMe / SSD) | SSDs drastically reduce file I/O latency, which is critical when `runner.py` exports real-time simulation telemetry and `dashboard.py` parses it for live visualization. |
| **Graphics (GPU)** | Integrated Graphics | Dedicated GPU (2GB+ VRAM) | Heavy cryptographic/CUDA computing is not required, but adequate graphics processing ensures the SUMO-GUI renders the dense 5x5 grid and dynamic color-coded privacy states smoothly during presentations. |
| **Platform** | Windows 10 / Ubuntu 20.04 / macOS | Windows 11 / Ubuntu 22.04 | Eclipse SUMO and TraCI libraries are fully cross-platform compatible. Linux or Windows Subsystem for Linux (WSL) is recommended for optimal subprocess execution. |

-----

### Software Requirements

The project relies on a decoupled software architecture, separating the heavy physical simulation backend from the interactive data analytics frontend.

| Component | Technology / Library | Engineering Justification |
| :--- | :--- | :--- |
| **Core Physics Engine** | **Eclipse SUMO** (Simulation of Urban MObility) | Provides microscopic, continuous physical traffic modeling. Enforces real-world kinematic constraints (acceleration, spatial boundaries) required to test the attacker's spatial-temporal heuristic. |
| **Control Interface** | **TraCI** (Traffic Control Interface) | The essential TCP-based client/server architecture that bridges the Python execution engine (`runner.py`) with the SUMO backend, allowing frame-by-frame manipulation of vehicle colors and BSM broadcasts. |
| **Programming Environment** | **Python 3.8+** | Serves as the primary execution environment for the On-Board Unit (OBU) logic, the adversary model (`attacker.py`), and the strict empirical grader (`visualizer.py`). |
| **Data Analytics & UI** | **Streamlit**, **Matplotlib**, & **Pandas** | `Streamlit` provides a decoupled, interactive web server for the presentation layer. `Matplotlib` mathematically plots the 2D geometric tracking arrays and trajectory overlays. |
| **Data Handling** | **JSON** (`metrics.json`, `trajectories.json`) | Replaces traditional CSV logging with lightweight JSON artifacts. This ensures fast, non-blocking I/O exchange between the heavy simulation backend and the frontend dashboard. |
| **Development Tools** | **VS Code** / PyCharm | Standard IDEs for managing the repository, executing terminal commands, and debugging the TraCI step-loops. |

-----
### Visualization of results


The project utilizes a dual-layered visualization approach to demonstrate both real-time algorithmic execution and post-simulation empirical metrics.

1. Real-Time Physical Simulation (SUMO & TraCI GUI)During the live execution of runner.py, the simulation provides immediate visual feedback of the privacy states of all vehicles on the 5x5 urban grid:Dynamic Color-Coding: Vehicles dynamically change colors via TraCI commands to represent their current vulnerability:Green (Default): The vehicle is broadcasting normally and is highly vulnerable to spatial-temporal tracking.Yellow (Pending Swap): The vehicle has initiated a pseudonym change but is actively searching for $\ge 2$ neighbors to form a Mix-Zone.Red (Radio Silence): The vehicle has successfully swapped its identifier and temporarily disabled BSM broadcasts to evade the attacker's prediction radius.On-Screen Display (OSD): A live overlay renders the active Scenario Name, Mitigation Logic, and Color Legend directly onto the simulation map.
  
2. Interactive Analytical Dashboard (dashboard.py)To prove the efficacy of the algorithms, a decoupled Streamlit web application parses the generated JSON artifacts (metrics.json and trajectories.json) into interactive academic visualizations:Quantitative Bar Charts: Dynamically compares the Tracking Success Rate (%) and Linkability (%) across all four scenarios (Baseline, Naive, Smart, Hybrid), visually proving the degradation of the attacker's capabilities from ~100% down to $<20\%$.Spatial Trajectory Overlays (The Visual Proof): Uses Matplotlib to plot the 2D $X, Y$ coordinate path of a sample vehicle. It overlays the Ground Truth Path (Solid Blue Line) against the Attacker's Reconstructed Track (Dashed Red Line).This interactive map proves exactly where the Hybrid evasion algorithm mathematically breaks the spatial-temporal link, forcing the red line to drop the blue line.

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
Our proposed solution is an empirical synthesis of Dynamic Mix-Zones and Velocity-Adaptive Silent Periods, optimized for real-world physics while intentionally avoiding the latency of heavy cryptography and the high costs of Roadside Units (RSUs).The mitigation progressively evolves through four tested scenarios:

V1 - Baseline (No Privacy): Static identifiers are broadcast continuously. (Yields ~100% Attacker Tracking).

V2 - Naive Approach (Blind Swaps): Time-based swaps every 3 seconds. The attacker easily predicts the trajectory using a spatial-temporal heuristic (Distance <= Speed * 1.5 + 10.0).

V3 - Smart Mitigation (Mix-Zones + Silence): Vehicles only swap pseudonyms when near >= 2 neighbors, followed by a random 3–6s period of radio silence to break the attacker's prediction cone.

V4 - Hybrid Mitigation (The Ultimate Solution): Introduces a Cooperative Handshake where groups of vehicles swap pseudonyms synchronously at the exact same simulation step. This is paired with Velocity-Adaptive Silence (Silence = 1000.0 / max(0.1, Speed)), dynamically ensuring fast vehicles return to the safety network quickly while slow vehicles take the time needed to safely escape the tracking radius.

Consent, Selective Disclosure & Information Sharing Model

Vehicle information is not fully shared at all times. Disclosure strictly depends on context, necessity, and consent:
| Scenario | Information Shared | Accessible By |
| :--- | :--- | :--- |
| **Normal Driving** | Temporary pseudonym + basic safety data (Location, Speed, Heading) | Public / Nearby Vehicles |
| **Traffic Safety Event** | Pseudonym + real-time position & speed | Public / Nearby Vehicles |
| **Emergency / Legal Case** | Authorized identity resolution via `trusted_backend` | Law Enforcement / Traffic Authority |
| **Vehicle Theft Investigation** | Full traceability via backend authority | Law Enforcement / Traffic Authority |


### System Architecture Diagram

The system operates on a decoupled, closed-loop software architecture. This design strictly separates the heavy microscopic physics simulation (backend) from the interactive data analytics environment (frontend) to ensure system stability.

| Architectural Block | Module / Component | Description & Function |
| :--- | :--- | :--- |
| **1. Simulation Backend** | `network_gen.py` & **SUMO** | Generates the dense 5x5 urban grid, configures traffic spawn rates, and handles continuous microscopic physical traffic modeling. |
| **2. Middleware Interface** | **TraCI API** | The TCP-based bridge connecting the simulator to Python. It extracts live vehicle telemetry and injects color-coding and routing commands frame-by-frame. |
| **3. Core Execution Engine** | `runner.py` | The central orchestrator acting as the On-Board Unit (OBU) logic. It evaluates neighbor densities and executes the pseudonym evasion algorithms (Mix-Zones & Silence). |
| **4. Adversary Model** | `attacker.py` | The passive observer running concurrently. It sniffs unencrypted broadcasts and utilizes an $O(1)$ spatial-temporal heuristic to mathematically reconstruct trajectories. |
| **5. Evaluation Engine** | `visualizer.py` | The independent grader. It mathematically evaluates the attacker's success, strictly penalizing dropped tracking frames to generate honest metrics. |
| **6. Data Exchange Layer** | `metrics.json` & `trajectories.json` | Static data artifacts that act as the bridge between backend and frontend, ensuring fast, non-blocking I/O exchange without crashing the physics engine. |
| **7. Interactive Presentation** | `dashboard.py` (Streamlit) | The decoupled frontend web UI. It parses the JSON artifacts to dynamically render comparative tracking drop-off charts and 2D trajectory overlays. |


<img width="1054" height="565" alt="image" src="https://github.com/user-attachments/assets/27ed6283-5509-4418-ad92-f77587f173d8" />


#### Usecases

#### 1. Privacy Risk Scenario (The Threat)
* **Action:** An unauthorized passive observer sniffs unencrypted BSM broadcasts over time.
* **Impact:** Because vehicles use static or poorly obfuscated pseudonyms, the observer utilizes a physics-based search cone to link the identifiers together, reconstructing the driver's full commute (e.g., Home to Workplace) without ever breaking cryptography.

#### 2. Expected Behavior with Mitigation (Normal Operation)
* **Action:** Vehicles autonomously form Mix-Zones at intersections and execute synchronized, velocity-adaptive pseudonym swaps.
* **Impact:** The observer's spatial-temporal heuristic is mathematically shattered. Public tracking drops to <20%. At the same time, nearby vehicles continue to receive necessary collision-avoidance data seamlessly.

#### 3. Authorized Authority Resolution (Accountability)
* **Action:** A traffic incident occurs, requiring the identity of a specific vehicle involved in a hit-and-run.
* **Impact:** Law enforcement queries the `trusted_backend` ledger. The system successfully maps the localized, time-bound temporary pseudonym back to the vehicle's permanent VIN/Owner identity.

#### Deliverables

1. **`network_gen.py`**: Automated infrastructure and traffic generator script.
2. **`runner.py`**: The core execution engine and TraCI step-controller.
3. **`attacker.py`**: The spatial-temporal adversary heuristic model.
4. **`visualizer.py`**: Empirical metric calculator (Tracking Success & Linkability).
5. **`dashboard.py`**: Interactive Streamlit presentation application.
6. **Simulation Artifacts**: `metrics.json` and `trajectories.json` generated dynamically to prove tracking degradation.
7. **Presentation Decks**: Academic slide decks detailing the engineering logic, mathematical formulas, and literature gap analysis.
------
### Mapping the Project to Relevant Sustainable Development Goals (SDGs)

| SDG | Alignment & Contribution |
| :--- | :--- |
| **SDG 9: Industry, Innovation, and Infrastructure** | Proposes an innovative, decentralized software architecture for VANETs that operates effectively without the need to build expensive, hardware-heavy Roadside Units (RSUs). |
| **SDG 11: Sustainable Cities and Communities** | Enhances the safety and security of future smart cities by protecting citizens from unauthorized surveillance and trajectory profiling while maintaining the BSM safety network. |
| **SDG 16: Peace, Justice, and Strong Institutions** | Establishes a "Conditional Traceability" consent model. Protects individual privacy by default while providing strong institutional tools for lawful vehicle tracing during accidents or legal investigations. |


### Collaboration 
| Team Member | Module & Scope Contribution |
| :--- | :--- |
| **Aditya Kumar** | M.Tech AEL - Implementation of the TraCI execution engine, spatial-temporal attacker heuristic, velocity-adaptive privacy algorithm and data visualization dashboard architecture s. |
| **Kalirajan M** | M.Tech AEL - Simulation environment setup and evaluation metric generation |

-----

### References
1. *A Review of Pseudonym Change Strategies for Location Privacy Preservation Schemes in Vehicular Networks* (2025)
2. *Cybersecurity and Privacy Protection in VANETs* (2023)
3. *Anonymity Assurance Using Efficient Pseudonym Consumption in IoV* (2023)
4. *ADMZ: Adaptive Dynamic Mix Zone Pseudonym Change Strategy for Location Privacy* (2025)
5. *RFPM: A RSU-Aided Framework for Pseudonym Management to Preserve Location Privacy* (2023)
6. *A Pseudonym-Based Certificateless Privacy-Preserving Authentication Scheme for VANETs* (2022)







