#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Créer le socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configurer l'adresse du serveur
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15"); // Remplace par l'IP du serveur

    // Se connecter au serveur
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Envoyer un message
    char *message = "Bonjour, serveur !";
    send(sock, message, strlen(message), 0);
    
    // Lire la réponse du serveur
    read(sock, buffer, sizeof(buffer));
    printf("Réponse du serveur: %s\n", buffer);

    // Fermer le socket
    close(sock);

    return 0;
}
