#include "calcul.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s hostname num1 num2\n", argv[0]);
        return 1;
    }

    CLIENT *clnt;
    int *result;
    char *host = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    clnt = clnt_create(host, CALCUL_PROG, CALCUL_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        return 1;
    }

    result = factorial_1(&num1, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Factorial of %d is %d\n", num1, *result);
    }

    struct addition_args args = {num1, num2};
    result = addition_1(&args, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Sum of %d and %d is %d\n", num1, num2, *result);
    }

    clnt_destroy(clnt);
    return 0;
}
