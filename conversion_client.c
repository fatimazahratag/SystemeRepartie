#include "conversion.h"
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n=== Convertisseur d'unités ===\n");
    printf("1. Kilomètres vers Miles\n");
    printf("2. Celsius vers Fahrenheit\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    float *result;
    int choice;
    conversion_args arg;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s host\n", argv[0]);
        exit(1);
    }

    clnt = clnt_create(argv[1], CONVERSION_PROG, CONVERSION_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 0) break;

        printf("Entrez la valeur à convertir : ");
        scanf("%f", &arg.value);

        switch(choice) {
            case 1:
                result = km_to_miles_1(&arg, clnt);
                if (result != NULL)
                    printf("Résultat: %.2f miles\n", *result);
                else
                    printf("Erreur lors de la conversion\n");
                break;
            case 2:
                result = celsius_to_fahrenheit_1(&arg, clnt);
                if (result != NULL)
                    printf("Résultat: %.2f°F\n", *result);
                else
                    printf("Erreur lors de la conversion\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    }

    clnt_destroy(clnt);
    return 0;
}
