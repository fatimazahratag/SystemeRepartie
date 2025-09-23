#include "calcul.h"

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

int *quotient_1_svc(struct operation_args *argp, struct svc_req *rqstp) {
    static int result;
    if (argp->b != 0) {
        result = argp->a / argp->b;
    } else {
        result = 0; // Gestion division par zéro
    }
    return &result;
}

int *absolue_1_svc(int *argp, struct svc_req *rqstp) {
    static int result;
    result = (*argp < 0) ? -(*argp) : *argp;
    return &result;
}
