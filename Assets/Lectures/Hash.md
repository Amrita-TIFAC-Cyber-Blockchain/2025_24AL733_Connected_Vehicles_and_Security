# 24AL733 - Connected Vehicles and Security 
![](https://img.shields.io/badge/PG-blue) ![](https://img.shields.io/badge/Subject-CVS-blue) <br/>

## Hashing Algorithm
![](https://img.shields.io/badge/Date-27_Dec_2024-blue)

#### Definition
A hashing algorithm is a one-way mathematical function that takes arbitary length input and provides fixed-length output known as hash value. 

A **cryptographic hash function (CHF)** is a hash algorithm (a map of an arbitrary binary string to a binary string with a fixed size of n bits) that has special properties desirable for a cryptographic application. The most widely used family of hashing algorithms are _Message Digest (MD)_ and _Secure Hash Algorithm (SHA)_.

#### Characteristics of Cryptographic Hash Function
- **Deterministic:** A hash function will always produce the same output for the same input.
- **Fast computation:** Hash functions are designed to process data quickly.
- **Avalanche effect:** A small change in the input data should result in a significantly different hash.
- **Collision resistance:** A hash function should be designed to make it difficult to find two different inputs that produce the same hash value.

#### MD and SHA
##### Message Digest 
- MD2 (128 bits) [1989 - 2011]
- MD4 (128 bits) [1990 - 2011]
- MD5 (128 bits) [1992 - 2011]: pre-computed MD5 (known as md5sum) checksum is used to compare the downloaded files.
- MD6 (Variable, 0<d≤512 bits) [2008]
  
##### Secure Hash Algorithm
- SHA0 (160-bits) [1993]
- SHA1 (160-bits) [1995 - 2011] 
- SHA2 (SHA-256 and SHA-512) [2001 - Present]
- SHA3 (SHA3-256 and SHA3-512) [2016 - Present] 
  
[Click Here](https://www.pelock.com/products/hash-calculator) to generate hash value based on different algorithms.
