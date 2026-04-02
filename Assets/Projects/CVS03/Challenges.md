# Challenges faced during setup
## 1. “OSG Earth Module” {Build Error}
### Solution:
* Open the file configure.user in a text editor (it's in your main OMNeT++ folder).
* Disable OSG Earth 3D Maps
* Find the line that says WITH_OSGEARTH=yes.
* Change it to WITH_OSGEARTH=no
* Save the file and run ./configure again.

## 2. “Missing NED file”- Version mismatch of SIMU5G.
![ned_error](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/1e0b824d6cfdbcc64d0ac753a570e698fab4aa10/Assets/Projects/CVS03/missing_ned.png)
### Solution:
* Due to version mismatch of SIMU5G.
* Expected Directory: Simu5g.simulations.NR .cars .Highway
* Happening Due to: Simu5g.simulations.nr .cars .Highway was in lower case for newer versions. So, we downgraded Simu5g version.

## 3. “Sumo version Error”- Unsupported with TraCI API version21.
![sumo_error](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/1e0b824d6cfdbcc64d0ac753a570e698fab4aa10/Assets/Projects/CVS03/sumo_version_error.png)
### Solution
* Downgraded SUMO version 1.10.0

## 4.” Linker is unable to find the INET Library”-SIMU5G project not linked to Veins_inet.
![liker_error](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/1e0b824d6cfdbcc64d0ac753a570e698fab4aa10/Assets/Projects/CVS03/inet_file_error.png)
### Solution
* By selecting the veins_inet the error got resolved.

![linker_solution](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/1e0b824d6cfdbcc64d0ac753a570e698fab4aa10/Assets/Projects/CVS03/inet_solution.png)

# We migrated to NS-3 due to a persistent, critical error in the OMNeT++ IDE that required an excessively complex workaround.
![network_resolver_error](https://github.com/Amrita-TIFAC-Cyber-Blockchain/2025_24AL733_Connected_Vehicles_and_Security/blob/2f4eab39cb356b6d7f4a22da6741d363ca013c1a/Assets/Projects/CVS03/Network_resolver_error.png)
