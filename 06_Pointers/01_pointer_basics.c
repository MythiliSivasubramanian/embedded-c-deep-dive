/*
Pointer Basics in C

1. Pointer declaration and initialization
2. Address-of operator '&'
3. Dereference operator '*'
4. Pointer arithmetic with arrays
5. Modifying data through pointers
*/

#include <stdio.h>

int main()
{
    int value = 42;
    int *ptr = &value;

    printf("Value    : %d\n", value);
    printf("Address  : %p\n", (void *)&value);
    printf("Pointer  : %p\n", (void *)ptr);
    printf("Dereference: %d\n\n", *ptr);

    // Modify the value using the pointer
    *ptr = 99;
    printf("After update through pointer:\n");
    printf("value = %d\n", value);
    printf("*ptr  = %d\n\n", *ptr);

    // Pointer arithmetic with arrays
    int array[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = array; // same as &array[0]

    printf("Array values using pointer arithmetic:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("array[%d] = %d, address = %p\n", i, *(arr_ptr + i), (void *)(arr_ptr + i));
    }

    return 0;
}
