#include "calcul.h"
#include <math.h>

int *addition_1_svc(struct operation_args *argp, struct svc_req *rqstp) {
    static int result;
    result = argp->a + argp->b;
    return &result;
}

int *soustraction_1_svc(struct operation_args *argp, struct svc_req *rqstp) {
    static int result;
    result = argp->a - argp->b;
    return &result;
}

int *multiplication_1_svc(struct operation_args *argp, struct svc_req *rqstp) {
    static int result;
    result = argp->a * argp->b;
    return &result;
}

float *quotient_1_svc(struct operation_args *argp, struct svc_req *rqstp) {
    static float result;
    if (argp->b == 0) {
        result = 0.0; // Éviter la division par zéro
    } else {
        result = (float)argp->a / argp->b;
    }
    return &result;
}

int *absolue_1_svc(int *argp, struct svc_req *rqstp) {
    static int result;
    result = abs(*argp);
    return &result;
}
