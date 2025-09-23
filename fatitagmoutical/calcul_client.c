/* calcul_client.c */

#include <stdio.h>
#include <rpc/rpc.h>
#include "calcul.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    struct operands ops;
    int *result;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_host> <num1> <num2>\n", argv[0]);
        exit(1);
    }

    ops.num1 = atoi(argv[2]);
    ops.num2 = atoi(argv[3]);

    clnt = clnt_create(argv[1], CALCULATOR_PROG, CALCULATOR_VERS, "udp");
    if (clnt == NULL) {
        fprintf(stderr, "Unable to create client handle.\n");
        exit(1);
    }

    result = add_1(&ops, clnt);
    printf("Addition result: %d\n", *result);

    result = subtract_1(&ops, clnt);
    printf("Subtraction result: %d\n", *result);

    result = multiply_1(&ops, clnt);
    printf("Multiplication result: %d\n", *result);

    result = divide_1(&ops, clnt);
    if (result != NULL) {
        printf("Division result: %d\n", *result);
    }

    result = abs_value_1(&ops, clnt);
    printf("Absolute value result: %d\n", *result);

    clnt_destroy(clnt);
    return 0;
}
