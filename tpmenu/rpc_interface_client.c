#include <stdio.h>
#include <stdlib.h>
#include "rpc_interface.h"

void print_menu() {
    printf("\n=== MENU ===\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Soustraction\n");
    printf("4. Valeur absolue\n");
    printf("5. Quitter\n");
    printf("Votre choix: ");
}

int main(int argc, char *argv[]) {
    CLIENT *client;
    int choix, n;
    struct params args;

    client = clnt_create("localhost", RPC_INTERFACE, RPC_INTERFACE_V1, "tcp");
    if (client == NULL) {
        printf("Erreur de connexion au serveur RPC.\n");
        return 1;
    }

    while (1) {
        print_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez deux nombres: ");
                scanf("%d %d", &args.a, &args.b);
                int *add_result = addition_1(&args, client);
                printf("Résultat: %d\n", *add_result);
                break;

            case 2:
                printf("Entrez deux nombres: ");
                scanf("%d %d", &args.a, &args.b);
                int *mul_result = multiplication_1(&args, client);
                printf("Résultat: %d\n", *mul_result);
                break;

            case 3:
                printf("Entrez deux nombres: ");
                scanf("%d %d", &args.a, &args.b);
                int *sub_result = soustraction_1(&args, client);
                printf("Résultat: %d\n", *sub_result);
                break;

            case 4:
                printf("Entrez un nombre: ");
                scanf("%d", &n);
                int *abs_result = absolu_1(&n, client);
                printf("Résultat: %d\n", *abs_result);
                break;

            case 5:
                printf("Fermeture du client...\n");
                clnt_destroy(client);
                return 0;

            default:
                printf("Choix invalide, réessayez.\n");
        }
    }

    return 0;
}
