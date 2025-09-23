#include "calcul.h"

int *factorial_1_svc(int *argp, struct svc_req *rqstp) {
    static int result = 1;
    int n = *argp;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return &result;
}

int *addition_1_svc(struct addition_args *argp, struct svc_req *rqstp) {
    static int result;
    result = argp->a + argp->b;
    return &result;
}
