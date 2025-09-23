struct params {
    int a;
    int b;
};

program CALCUL_PROG {
    version CALCUL_VERS {
        int addition(params) = 1;
        int multiplication(params) = 2;
        int soustraction(params) = 2;
        int absolu(int) = 1;
    } = 1;
} = 0x20000001;
