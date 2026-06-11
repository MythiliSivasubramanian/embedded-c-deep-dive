/*
Pointer to Pointer in C

1. Declare a pointer to pointer
2. Understand the address levels
3. Modify the original pointer through double indirection
4. Use pointers to pointers with strings
*/

#include <stdio.h>

int main()
{
    int value = 100;
    int *ptr = &value;          // pointer to int
    int **pptr = &ptr;         // pointer to pointer to int

    printf("\n\nPointer to Pointer Example:\n");
    printf("value         = %d\n", value);
    printf("&value        = %p\n", (void *)&value);
    printf("ptr           = %p\n", (void *)ptr);
    printf("*ptr          = %d\n", *ptr);
    printf("&ptr          = %p\n", (void *)&ptr);
    printf("pptr          = %p\n", (void *)pptr);
    printf("*pptr         = %p\n", (void *)*pptr);
    printf("**pptr        = %d\n\n", **pptr);

    // Modify the original value through the pointer to pointer
    **pptr = 200;
    printf("After modifying through **pptr:\n");
    printf("value         = %d\n", value);
    printf("*ptr          = %d\n", *ptr);
    printf("**pptr        = %d\n\n", **pptr);

    // Use pointer to pointer with a string literal pointer
    const char *message = "Embedded C is fun";
    const char **msg_ptr = &message;
    const char ***msg_pptr = &msg_ptr;

    printf("String pointer example:\n");
    printf("message       = %s\n", message);
    printf("msg_ptr       = %p\n", (void *)msg_ptr);
    printf("*msg_ptr      = %s\n", *msg_ptr);
    printf("msg_pptr      = %p\n", (void *)msg_pptr);
    printf("*msg_pptr     = %p\n", (void *)*msg_pptr);
    printf("**msg_pptr    = %s\n", **msg_pptr);

    return 0;
}
