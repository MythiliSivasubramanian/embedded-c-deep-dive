/*
Function return values and parameter flow


- passing values to functions
- returning values from functions
- using function results in the main program
- function flow from caller to callee and back
*/

#include <stdio.h>

int add_numbers(int a, int b);
int subtract_numbers(int a, int b);
int multiply_numbers(int a, int b);
int divide_numbers(int a, int b);

int main(void)
{
    int x = 20;
    int y = 5;

    printf("Function return and parameter flow\n");

    int sum = add_numbers(x, y);
    printf("sum = %d\n", sum);

    int diff = subtract_numbers(x, y);
    printf("difference = %d\n", diff);

    int product = multiply_numbers(x, y);
    printf("product = %d\n", product);

    int quotient = divide_numbers(x, y);
    printf("quotient = %d\n", quotient);

    printf("\nMain function completed.\n");
    return 0;
}

int add_numbers(int a, int b)
{
    return a + b;
}

int subtract_numbers(int a, int b)
{
    return a - b;
}

int multiply_numbers(int a, int b)
{
    return a * b;
}

int divide_numbers(int a, int b)
{
    return a / b;
}
