struct operandes {
    int a;
    int b;
};

program CALCUL_PROG {
    version CALCUL_VERS {
        int addition(operandes) = 1;
        int soustraction(operandes) = 2;
        int multiplication(operandes) = 3;
        int quotient(operandes) = 4;
        int absolue(int) = 5;
    } = 1;
} = 0x20000001;

