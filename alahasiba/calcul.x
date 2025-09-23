program CALCULATOR_PROG {
    version CALCULATOR_VERS {
        int ADD(struct operands) = 1;
        int SUBTRACT(struct operands) = 2;
        int MULTIPLY(struct operands) = 3;
        int DIVIDE(struct operands) = 4;
        int ABS_VALUE(struct operands) = 5;
    } = 1;
} = 0x20000001;
