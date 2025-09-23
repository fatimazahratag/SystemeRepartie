
#include <stdio.h>
#include <rpc/rpc.h>
#include "calcul.h"

int * add_1_svc(struct operands *args, struct svc_req *rqstp) {
    static int result;
    result = args->num1 + args->num2;
    return &result;
}

int * subtract_1_svc(struct operands *args, struct svc_req *rqstp) {
    static int result;
    result = args->num1 - args->num2;
    return &result;
}

int * multiply_1_svc(struct operands *args, struct svc_req *rqstp) {
    static int result;
    result = args->num1 * args->num2;
    return &result;
}

int * divide_1_svc(struct operands *args, struct svc_req *rqstp) {
    static int result;
    if (args->num2 == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        return NULL;
    }
    result = args->num1 / args->num2;
    return &result;
}

int * abs_value_1_svc(struct operands *args, struct svc_req *rqstp) {
    static int result;
    result = abs(args->num1);
    return &result;
}

int main() {
    register SVCXPRT *transp;
    
    pmap_unset(CALCULATOR_PROG, CALCULATOR_VERS);
    transp = svcudp_create(RPC_ANYSOCK);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create UDP transport.\n");
        exit(1);
    }
    if (!svc_register(transp, CALCULATOR_PROG, CALCULATOR_VERS, calcul_1, IPPROTO_UDP)) {
        fprintf(stderr, "Unable to register (CALCULATOR_PROG, CALCULATOR_VERS).\n");
        exit(1);
    }
    svc_run();
    return 0;
}
