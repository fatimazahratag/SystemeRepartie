/* calcul.h */

#ifndef _CALCUL_H_
#define _CALCUL_H_

struct operands {
    int num1;
    int num2;
};

#define CALCULATOR_PROG 0x20000001
#define CALCULATOR_VERS 1

/* Function prototypes */
int * add_1_svc(struct operands *, struct svc_req *);
int * subtract_1_svc(struct operands *, struct svc_req *);
int * multiply_1_svc(struct operands *, struct svc_req *);
int * divide_1_svc(struct operands *, struct svc_req *);
int * abs_value_1_svc(struct operands *, struct svc_req *);

#endif /* _CALCUL_H_ */

