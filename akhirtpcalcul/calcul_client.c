/* calcul_client.c */
#include "calcul.h"
#include <stdio.h>

void call_rpc(char *host, int a, int b) {
    CLIENT *clnt;
    operandes op;
    int *result;

    op.a = a;
    op.b = b;

    clnt = clnt_create(host, CALCUL_PROG, CALCUL_VERS, "udp");
    if (clnt == NULL) {
        fprintf(stderr, "Could not create client.\n");
        exit(1);
    }

    result = addition_1(&op, clnt);
    if (result == NULL) {
        fprintf(stderr, "RPC failed!\n");
    } else {
        printf("Result of addition: %d\n", *result);
    }

    // Add other operations similarly
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <a> <b>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    call_rpc(host, a, b);

    return 0;
}
