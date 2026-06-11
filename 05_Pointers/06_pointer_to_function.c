/*
Pointer to Function in C

1. Declare a function pointer
2. Assign a function address to the pointer
3. Call a function through the pointer
4. Use function pointers in arrays
*/

#include <stdio.h>

void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);

int main()
{
    printf("\n\nPointer to Function Example:\n");

    // Declare a function pointer
    void (*operation)(int, int);

    // Assign the pointer to the add function
    operation = add;
    operation(10, 5); // call add through pointer

    // Assign the pointer to the subtract function
    operation = subtract;
    operation(10, 5); // call subtract through pointer

    // Assign the pointer to the multiply function
    operation = multiply;
    operation(10, 5); // call multiply through pointer

    // Function pointer array for multiple operations
    void (*ops[3])(int, int) = { add, subtract, multiply };

    printf("\nFunction pointer array calls:\n");
    for (int i = 0; i < 3; i++)
    {
        ops[i](8, 3);
    }

    return 0;
}

void add(int a, int b)
{
    printf("add(%d, %d) = %d\n", a, b, a + b);
}

void subtract(int a, int b)
{
    printf("subtract(%d, %d) = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
    printf("multiply(%d, %d) = %d\n", a, b, a * b);
}
