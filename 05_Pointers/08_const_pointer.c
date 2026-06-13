/*
Const Pointer in C

1. Understand constant pointer vs pointer to constant
2. Use const to protect data or pointer target
3. Observe compile-time behavior for invalid writes
4. Apply const pointers in embedded data handling
*/

#include <stdio.h>

int main()
{
    int value = 25;
    int other = 50;
    const int constant_value = 100;

    // Pointer to constant data: target is const, pointer can move
    const int *ptr_to_const = &value;
    printf("ptr_to_const points to value = %d\n", *ptr_to_const);

    // Allowed: change pointer target
    ptr_to_const = &constant_value;
    printf("ptr_to_const now points to constant_value = %d\n", *ptr_to_const);

    // Not allowed: *ptr_to_const = 30; // compiler error

    // Constant pointer: pointer cannot move, target can change
    int *const const_ptr = &value;
    printf("const_ptr points to value = %d\n", *const_ptr);

    *const_ptr = 35; // allowed
    printf("value after update through const_ptr = %d\n", value);

    // Not allowed: const_ptr = &other; // compiler error

    // Constant pointer to constant data: neither pointer nor target can change
    const int *const const_ptr_to_const = &constant_value;
    printf("const_ptr_to_const points to constant_value = %d\n", *const_ptr_to_const);

    // Not allowed: *const_ptr_to_const = 110; // compiler error
    // Not allowed: const_ptr_to_const = &value; // compiler error

    return 0;
}
