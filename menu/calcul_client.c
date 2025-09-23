#include "calcul.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    int *result_int;
    float *result_float;
    char *host = "localhost"; 

    clnt = clnt_create(host, CALCUL_PROG, CALCUL_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        return 1;
    }

    int choix, num1, num2;
    while (1) {
        printf("\nMenu :\n");
        printf("1. Addition\n2. Soustraction\n3. Multiplication\n4. Quotient\n5. Valeur Absolue\n6. Quitter\n");
        printf("Choisissez une opération : ");
        scanf("%d", &choix);

        if (choix == 6) break;

        if (choix == 5) {
            printf("Entrez un nombre : ");
            scanf("%d", &num1);
        } else {
            printf("Entrez deux nombres : ");
            scanf("%d %d", &num1, &num2);
        }

        struct operation_args args = {num1, num2};

        switch (choix) {
            case 1:
                result_int = addition_1(&args, clnt);
                if (result_int) printf("Résultat : %d\n", *result_int);
                break;
            case 2:
                result_int = soustraction_1(&args, clnt);
                if (result_int) printf("Résultat : %d\n", *result_int);
                break;
            case 3:
                result_int = multiplication_1(&args, clnt);
                if (result_int) printf("Résultat : %d\n", *result_int);
                break;
            case 4:
                result_float = quotient_1(&args, clnt);
                if (result_float) printf("Résultat : %.2f\n", *result_float);
                break;
            case 5:
                result_int = absolue_1(&num1, clnt);
                if (result_int) printf("Résultat : %d\n", *result_int);
                break;
            default:
                printf("Choix invalide\n");
        }
    }

    clnt_destroy(clnt);
    return 0;
}
