#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int main()
{
    /* single function pointer */
    int (*fp)(int, int) = add; // points to add

    printf("\nFunction pointers example:\n");
    printf("add(2,3) via pointer = %d\n", fp(2, 3));

    fp = mul; // now points to mul
    printf("mul(2,3) via pointer = %d\n", fp(2, 3));

    /* array of function pointers */
    int (*ops[])(int, int) = { add, mul };
    for (int i = 0; i < 2; i++)
    {
        printf("ops[%d] address: %p  result(4,5) = %d\n", i, (void *)ops[i], ops[i](4, 5));
    }

    /* using pointer arithmetic with function pointers */
    int (**pops)(int, int) = ops; // pointer to first element of ops
    printf("\nCall via pointer arithmetic: %d\n", (*(pops + 1))(6, 7));

    return 0;
}
