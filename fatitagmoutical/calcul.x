/*
 * calcul.x - RPC definition file for the calculator
 */

struct operand {
    int a;
    int b;
};

program CALCULATOR {
    version CALCULATOR_V1 {
        int ADD(operand) = 1;
        int SUBTRACT(operand) = 2;
        int MULTIPLY(operand) = 3;
        int DIVIDE(operand) = 4;
        int ABSOLUTE(operand) = 5;
    } = 1;
} = 0x20000001;
