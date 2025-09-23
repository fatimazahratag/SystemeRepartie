struct operation_args {
    int a;
    int b;
};

program CALCUL_PROG {
    version CALCUL_VERS {
        int addition(operation_args) = 1;
        int soustraction(operation_args) = 2;
        int multiplication(operation_args) = 3;
        int quotient(operation_args) = 4;
        int absolue(int) = 5;
    } = 1;
} = 0x20000001;
