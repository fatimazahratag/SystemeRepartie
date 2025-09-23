struct params {
    int a;
    int b;
};

program RPC_INTERFACE {
    version RPC_INTERFACE_V1 {
        int addition(params) = 1;
        int multiplication(params) = 2;
        int soustraction(params) = 3;
        int absolu(int) = 4;
    } = 1;
} = 0x20000001;

