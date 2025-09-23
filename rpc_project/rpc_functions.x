program RPC_PROG {
    version RPC_VERS {
        int factoriel(int) = 1;
        int addition(struct { int a; int b; }) = 2;
    } = 1;
} = 0x20000001;
