/* calcul_server.c */
#include "calcul.h"
#include <stdio.h>

int *addition_1_svc(operandes *op, struct svc_req *rqstp) {
    static int result;
    result = op->a + op->b;
    return &result;
}

int *soustraction_1_svc(operandes *op, struct svc_req *rqstp) {
    static int result;
    result = op->a - op->b;
    return &result;
}

int *multiplication_1_svc(operandes *op, struct svc_req *rqstp) {
    static int result;
    result = op->a * op->b;
    return &result;
}

int *quotient_1_svc(operandes *op, struct svc_req *rqstp) {
    static int result;
    if (op->b == 0) {
        printf("Division by zero error!\n");
        result = 0;
    } else {
        result = op->a / op->b;
    }
    return &result;
}

int *absolue_1_svc(int *a, struct svc_req *rqstp) {
    static int result;
    result = (*a < 0) ? -(*a) : *a;
    return &result;
}

int main() {
    register SVCXPRT *transp;

    pmap_unset(CALCUL_PROG, CALCUL_VERS);

    transp = svrpc_create(RPC_ANYSOCK, RPC_MAXDATASIZE);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create server transport.\n");
        exit(1);
    }

    svc_run();  // This will make the server wait for requests
    return 0;
}
