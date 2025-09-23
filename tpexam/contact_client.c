// contact_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>
#include "contact.h"

#define CONTACT_PROG 0x31234567
#define CONTACT_VER 1

void menu(CLIENT *clnt);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    CLIENT *clnt = clnt_create(argv[1], CONTACT_PROG, CONTACT_VER, "udp");
    if (clnt == NULL) {
        fprintf(stderr, "Couldn't establish connection.\n");
        exit(1);
    }

    menu(clnt);

    clnt_destroy(clnt);
    return 0;
}

void menu(CLIENT *clnt) {
    int option;
    char nom[100];
    char numero[20];
    struct contact c;
    char *result;
    struct contact_list *contacts;

    while (1) {
        printf("\nMenu du carnet de contacts\n");
        printf("1: Ajouter un contact\n");
        printf("2: Rechercher un contact\n");
        printf("3: Supprimer un contact\n");
        printf("4: Afficher tous les contacts\n");
        printf("0: Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Entrez le nom: ");
                scanf("%99s", c.nom);
                printf("Entrez le numéro: ");
                scanf("%19s", c.numero);
                if (ajouterContact_1(&c, clnt) != NULL && *ajouterContact_1(&c, clnt) == 1) {
                    printf("Contact ajouté avec succès.\n");
                } else {
                    printf("Erreur: Ajout échoué.\n");
                }
                break;
            case 2:
                printf("Entrez le nom: ");
                scanf("%99s", nom);
                result = (char *)rechercherContact_1(&nom, clnt);
                if (strcmp(result, "Non trouvé") == 0) {
                    printf("Contact non trouvé.\n");
                } else {
                    printf("Numéro: %s\n", result);
                }
                break;
            case 3:
                printf("Entrez le nom: ");
                scanf("%99s", nom);
                if (supprimerContact_1(&nom, clnt) != NULL && *supprimerContact_1(&nom, clnt) == 1) {
                    printf("Contact supprimé avec succès.\n");
                } else {
                    printf("Erreur: Suppression échouée.\n");
                }
                break;
            case 4:
                contacts = afficherContacts_1(NULL, clnt);
                printf("Contacts:\n");
                for (int i = 0; i < contacts->contacts_len; i++) {
                    printf("%s %s\n", contacts->contacts_val[i].nom, contacts->contacts_val[i].numero);
                }
                break;
            case 0:
                clnt_destroy(clnt);
                exit(0);
            default:
                printf("Option invalide.\n");
        }
    }
}
