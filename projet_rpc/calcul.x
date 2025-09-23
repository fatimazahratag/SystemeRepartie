struct addition_args {
    int a;
    int b;
};

program CALCUL_PROG {
    version CALCUL_VERS {
        int factorial(int) = 1;
        int addition(addition_args) = 2;
    } = 1;
} = 0x20000001;

