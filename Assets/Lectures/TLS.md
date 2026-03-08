# 24AL733 - Connected Vehicles and Security 
![](https://img.shields.io/badge/PG-blue) ![](https://img.shields.io/badge/Subject-CVS-blue) <br/>

## Transport Layer Security (TLS) 

Transport Layer Security (TLS) is a **cryptographic protocol** designed to provide communications security over a computer network, such as the Internet. 
TLS is a successor of deprecated Secure Socket Layer (SSL) protocol.
TLS is first defined in 1999 and the latest version of TLS that is in use is TLS 1.2 (2008) and TLS 1.3 (2018)

### TLS Handshake
- Client Hello: Browser sends its TLS version, supported encryption methods, and random number.
-  Server Hello: The server agrees on the TLS version & encryption method and sends its random number.
- Certificate Exchange: The server provides a digital certificate to prove its identity.
- Key Exchange: Both parties securely exchange parameters to generate the session key to encrypt the communication session.
- Handshake Completion: A secure connection is finalized.

[Click Here](https://aethersimlabs.com/simulations/ssl-tls-handshake-simulator/) to use TLS Handshake Simulator

### Cipher Suite

#### TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
- ECDHE – Ephemeral Diffie-Hellman → provides Forward Secrecy
- ECDSA – authentication using elliptic curve digital signature
- AES_128_GCM – AEAD encryption (fast and secure)
- SHA256 – hashing for handshake integrity

#### TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256
- ECDHE – forward secrecy
- ECDSA – elliptic curve authentication
- ChaCha20-Poly1305 – modern AEAD cipher optimized for mobile devices
- SHA256 – handshake hashing

* Faster on devices without AES hardware acceleration

#### TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
- ECDHE – forward secrecy
- RSA – server authentication
- AES_128_GCM – AEAD encryption
- SHA256 – hashing

#### TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256
- ECDHE – forward secrecy
- RSA – authentication
- ChaCha20-Poly1305 – AEAD encryption
- SHA256 – handshake hash

#### TLS_RSA_WITH_AES_128_CBC_SHA
- RSA – key exchange and authentication
- AES_128_CBC – CBC encryption mode
- SHA1 – hashing

#### TLS_RSA_WITH_AES_128_CBC_SHA256
- RSA key exchange
- AES_128_CBC encryption
- SHA256 hashing

#### TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
- ECDHE forward secrecy
- ECDSA authentication
- AES_128_CBC encryption

### Additional Information

| SSL /TLS   |   Published   |          Status    |    RFC     |  
|:----------:|:-------------:|:------------------:|:----------:|
| SSL 1.0    | Not Published |   Not Published    |    NA      | 
| SSL 2.0    |      1995     | Deprecated in 2011 |    NA      |
| SSL 3.0    |      1996     | Deprecated in 2015 | [RFC6101](https://www.rfc-editor.org/rfc/rfc6101) | 
| TLS 1.0    |      1999     | Deprecated in 2021 | [RFC2246](https://www.rfc-editor.org/rfc/rfc2246) | 
| TLS 1.1    |      2006     | Deprecated in 2021 | [RFC4346](https://www.rfc-editor.org/rfc/rfc4346) | 
| TLS 1.2    |      2008     |     Supported      | [RFC5246](https://www.rfc-editor.org/rfc/rfc5246) |
| TLS 1.3    |      2018     |   Latest Version   | [RFC8446](https://www.rfc-editor.org/rfc/rfc8446) |
