/*
Function basics in Embedded C

This example demonstrates:
- function declaration (prototype)
- function definition
- function calling
- parameters and arguments
- return values
- void functions
*/

#include <stdio.h>

// Function declarations (prototypes)
int add(int a, int b);
int multiply(int a, int b);
void print_divider(void);
void greet_user(const char *name);

int main(void)
{
    int x = 4;
    int y = 7;

    printf("Embedded C Functions Example\n");
    printf("===============================\n");

    greet_user("Student");
    print_divider();

    // Call a function that returns a value
    int sum = add(x, y);
    printf("add(%d, %d) = %d\n", x, y, sum);

    // Call another function with parameters
    int product = multiply(x, y);
    printf("multiply(%d, %d) = %d\n", x, y, product);

    print_divider();

    printf("Main function finished.\n");
    return 0;
}

// Function definitions

int add(int a, int b)
{
    // 'a' and 'b' are function parameters
    return a + b; // return value is used by the caller
}

int multiply(int a, int b)
{
    return a * b;
}

void print_divider(void)
{
    printf("-------------------------------\n");
}

void greet_user(const char *name)
{
    printf("Hello, %s!\n", name);
    printf("This is a simple function flow example.\n");
}
