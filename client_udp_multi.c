#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6000
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    // Use the IP address of Machine 1 (replace with actual IP)
    server_addr.sin_addr.s_addr = inet_addr("192.168.200.5"); // Replace with your Machine 1 IP address

    while (1) {
        printf("You (client): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send message to server
        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));

        // Receive response from server
        int n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, NULL, NULL);
        buffer[n] = '\0';
        printf("Server: %s\n", buffer);

        // Exit if user types "exit"
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}
