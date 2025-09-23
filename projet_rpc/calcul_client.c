#include "calcul.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    int *result;
    char *host = "localhost"; // Le serveur est sur la même machine

    // Créer le client RPC
    clnt = clnt_create(host, CALCUL_PROG, CALCUL_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        return 1;
    }

    // Demander à l'utilisateur de saisir un nombre pour le factoriel
    int num1;
    printf("Entrez un nombre pour calculer son factoriel : ");
    scanf("%d", &num1);

    // Appeler la fonction factorielle
    result = factorial_1(&num1, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "Erreur lors de l'appel de la fonction factorielle");
    } else {
        printf("Le factoriel de %d est %d\n", num1, *result);
    }

    // Demander à l'utilisateur de saisir deux nombres pour l'addition
    int num2, num3;
    printf("Entrez deux nombres pour calculer leur somme : ");
    scanf("%d %d", &num2, &num3);

    // Appeler la fonction addition
    struct addition_args args = {num2, num3};
    result = addition_1(&args, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "Erreur lors de l'appel de la fonction addition");
    } else {
        printf("La somme de %d et %d est %d\n", num2, num3, *result);
    }

    // Fermer le client RPC
    clnt_destroy(clnt);
    return 0;
}
