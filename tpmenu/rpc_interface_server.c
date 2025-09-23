#include <stdio.h>
#include <stdlib.h>
#include "rpc_interface.h"

int *addition_1_svc(struct params *args, struct svc_req *rqstp) {
    static int result;
    result = args->a + args->b;
    return &result;
}

int *multiplication_1_svc(struct params *args, struct svc_req *rqstp) {
    static int result;
    result = args->a * args->b;
    return &result;
}

int *soustraction_1_svc(struct params *args, struct svc_req *rqstp) {
    static int result;
    result = args->a - args->b;
    return &result;
}

int *absolu_1_svc(int *n, struct svc_req *rqstp) {
    static int result;
    result = (*n < 0) ? -(*n) : *n;
    return &result;
}

int main() {
    printf("Serveur RPC démarré...\n");
    svc_run();
    return 1;
}
