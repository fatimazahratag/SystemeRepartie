# SystemeRepartie
Projects for the Distributed Systems module, including client-server communication, RPC implementations, and multi-process calculations in C , ajava , and a tp of docker.
here is some of the results:
<img width="1920" height="909" alt="docker" src="https://github.com/user-attachments/assets/5a7a2c16-91bc-4499-ac3a-3e8d3bfa50c2" />
# Description:
This project demonstrates a simple distributed computation system. The client sends input values to the server, which calculates the factorial of a number and the sum of two numbers, then returns the results to the client.
<img width="230" height="23" alt="image" src="https://github.com/user-attachments/assets/fc16ac53-665e-4cc6-9179-6a7383cc6b29" />
<img width="289" height="48" alt="image" src="https://github.com/user-attachments/assets/ace04af7-7cd9-4301-9c98-80e7643138b6" />
# Projet rpc 
# Systeme Repartie Projects

This repository contains several **Distributed Systems (Système Réparti)** projects implemented in C and Java using **RPC** and **Sockets**.  

---

## Table of Contents

1. [Projet RPC – Factorial & Sum Calculator](#projet-rpc---factorial--sum-calculator)  
2. [Calcul RPC](#calcul-rpc)  
3. [RPC Menu](#rpc-menu)  
4. [TCP & UDP Client-Server Projects](#tcp--udp-client-server-projects)  
5. [File Transfer TCP Project](#file-transfer-tcp-project)  

---

## 1. Projet RPC – Factorial & Sum Calculator

### Description

This project demonstrates a simple **Remote Procedure Call (RPC)** application.  
It allows a client to:

- Compute the **factorial** of a number.
- Compute the **sum** of two numbers.

The server performs the calculations and sends the results back to the client.

### Files

- `calcul.x` – RPC interface definition.  
- `calcul_server.c` – Server implementation.  
- `calcul_client.c` – Client implementation.  
- `calcul_svc.c`, `calcul_clnt.c`, `calcul_xdr.c` – Generated files from `rpcgen`.  

### Requirements

- Linux (Ubuntu recommended)  
- `gcc` compiler  
- `libtirpc-dev` package  

Install dependencies:

```bash
sudo apt update
sudo apt install gcc libtirpc-dev
```

### Compile & Run

1. Generate RPC files:

```bash
rpcgen calcul.x
```

2. Compile server:

```bash
gcc -I/usr/include/tirpc -o calcul_server calcul_server.c calcul_svc.c calcul_xdr.c -ltirpc
```

3. Compile client:

```bash
gcc -I/usr/include/tirpc -o calcul_client calcul_client.c calcul_clnt.c calcul_xdr.c -ltirpc
```

4. Give execute permissions:

```bash
chmod +x calcul_server calcul_client
```

5. Run server:

```bash
./calcul_server
```

6. Run client (in a separate terminal):

```bash
./calcul_client localhost
```

7. Example output:

```
Entrez un nombre pour calculer son factoriel : 12
Le factoriel de 12 est 479001600
Entrez deux nombres pour calculer leur somme : 1000 291
La somme de 1000 et 291 est 1291
```

---

## 2. Calcul RPC

### Description

This project is a **generic RPC calculator** that allows multiple clients to connect to a server to perform different mathematical operations (sum, factorial, etc.).

### Files

- `calcul_client.c` – Client code  
- `calcul_server.c` – Server code  
- `calcul.x` – RPC definition file  
- `calcul_svc.c`, `calcul_clnt.c`, `calcul_xdr.c` – Generated via `rpcgen`  

### Usage

Follow the same steps as **Projet RPC**: generate RPC files, compile server/client, run server first, then client.

---

## 3. RPC Menu

### Description

A menu-driven RPC project allowing clients to select operations dynamically.  

### Files

- `rpcmenu/` – Contains source code for menu-driven RPC project.  

### Usage

- Navigate to `rpcmenu/`, generate RPC files if needed, compile, and run the server and client as explained above.

---

## 4. TCP & UDP Client-Server Projects

### Description

This folder contains classic **socket programming projects** in C and Java:

- `client.c` / `server.c` – Simple TCP client-server  
- `client_udp_multi.c` / `client_udp_multi` – UDP multi-client examples  

### Usage

- Compile using `gcc` for C programs, or `javac` for Java programs.  
- Run the server first, then the client, using the correct IP/hostname.

---

## 5. File Transfer TCP Project

### Description

A simple Java project demonstrating **file transfer over TCP sockets**.  
Allows a client to select a file and send it to the server.

### Files

- `Client.java` – Client implementation  
- `Server.java` – Server implementation  
- `received_files/` – Folder where received files are saved  

### Usage

1. Compile:

```bash
javac Server.java Client.java
```

2. Run server:

```bash
java Server
```

3. Run client:

```bash
java Client
```

- Enter the path to the file you want to send.  
- The server saves it in `received_files/` and logs the transfer.

---

## Notes

- Always run the **server before the client**.  
- Ensure all executables have the proper **execute permissions** (`chmod +x`).  
- Use `localhost` or `127.0.0.1` if running client and server on the same machine.  


<img width="326" height="65" alt="image" src="https://github.com/user-attachments/assets/83770ce6-af8d-4604-b65e-7d08cd16c46a" />

