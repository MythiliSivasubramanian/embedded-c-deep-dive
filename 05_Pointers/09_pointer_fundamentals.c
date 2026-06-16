/*
    POINTER FUNDAMENTALS
     
     1. Address Operator (&)
     2. Pointer Declaration
     3. Dereference Operator (*)
     4 Reading Through a Pointer
     5. Modifying Data Through a Pointer
     6. Pointer Reassignment
*/

#include <stdio.h>

int main()
{


    printf("POINTER FUNDAMENTALS\n\n");

    int x = 10;

    /* Pointer storing address of x */
    int *p = &x;

    printf("1. Basic Pointer\n");
    printf("x   = %d\n", x);
    printf("&x  = %p\n", (void *)&x);
    printf("p   = %p\n", (void *)p);
    printf("*p  = %d\n\n", *p);

    /*
     * x   value stored in x
     * &x  address of x
     * p   address stored in pointer
     * *p  value at that address
     */

    /* 2. Modify Variable Through Pointer */

    *p = 20;

    printf("2: Modify Through Pointer\n");
    printf("x   = %d\n", x);
    printf("*p  = %d\n\n", *p);

    /*
     * *p = 20;
     *
     * Pointer p contains address of x.
     * Therefore x becomes 20.
     */

    /* 3: Pointer and Variable Share Memory */

    x = 30;

    printf("3: Shared Memory\n");
    printf("x   = %d\n", x);
    printf("*p  = %d\n\n", *p);

    /*
     * Changing x directly also changes
     * what *p sees because both refer
     * to the same memory location.
     */

    /* 4: Pointer Reassignment */

    int y = 50;

    p = &y;

    printf("4: Pointer Reassignment\n");
    printf("y   = %d\n", y);
    printf("p   = %p\n", (void *)p);
    printf("*p  = %d\n\n", *p);

    /*
     * p now points to y instead of x.
     *
     * Before:
     * p - x
     *
     * After:
     * p - y
     */

    /* 5: Modify y Through Pointer */

    *p = 100;

    printf("5: Modify New Target\n");
    printf("x   = %d\n", x);
    printf("y   = %d\n", y);
    printf("*p  = %d\n\n", *p);

    /*
     * Since p points to y,
     * *p = 100 changes y.
     */

    return 0;
}