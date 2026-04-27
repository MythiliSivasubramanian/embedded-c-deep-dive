#include <stdio.h>

int main()
{
    // Variable declaration
    int a = 10, b = 3;
    float x = 7.0, y = 2.0;

    printf("\nBASIC ARITHMETIC OPERATORS\n");

    // Addition
    printf("Addition (a + b)       : %d\n", a + b);

    // Subtraction
    printf("Subtraction (a - b)    : %d\n", a - b);

    // Multiplication
    printf("Multiplication (a * b) : %d\n", a * b);

    // Integer Division
    printf("Integer Division (a / b): %d\n", a / b);
    // NOTE: decimal part is removed in int division

    // Modulus (remainder)
    printf("Modulus (a %% b)        : %d\n", a % b);

    printf("\nFLOAT DIVISION\n");

    // Float division (normal case)
    printf("Float Division (x / y)  : %f\n", x / y);

    // Mixed division (int / int stored in float)
    float wrong_avg = 5 / 2;
    printf("Wrong Avg (5 / 2)       : %f\n", wrong_avg);
    // 5/2 = 2 (integer division first)

    // Correct float division
    float correct_avg = 5.0 / 2;
    printf("Correct Avg (5.0 / 2)   : %f\n", correct_avg);

    // Type casting
    float cast_avg = (float)5 / 2;
    printf("Cast Avg ((float)5 / 2) : %f\n", cast_avg);

    printf("\nMODULUS TEST CASES\n");

    printf("10 %% 3 = %d\n", 10 % 3);
    printf("7  %% 2 = %d\n", 7 % 2);
    printf("20 %% 4 = %d\n", 20 % 4);

    printf("\nTAKEAWAYS\n");
    printf("1. / with int → integer division\n");
    printf("2. / with float → decimal result\n");
    printf("3. %% works only with integers\n");
    printf("4. Type casting forces float division\n");

    return 0;
}