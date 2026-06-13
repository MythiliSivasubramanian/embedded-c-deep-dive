/*
Void Pointer in C

1. Use a void pointer for generic data storage
2. Assign addresses of different types to the same pointer
3. Cast void pointer before dereference
4. Understand why void pointers are useful in embedded code
*/

#include <stdio.h>

int main()
{
    int number = 100;
    float temperature = 36.5f;
    char letter = 'Z';

    void *ptr = NULL;

    printf("\n\nVoid Pointer Example:\n");

    // Store int address in void pointer
    ptr = &number;
    printf("int value = %d\n", *(int *)ptr);

    // Store float address in same void pointer
    ptr = &temperature;
    printf("float value = %.2f\n", *(float *)ptr);

    // Store char address in same void pointer
    ptr = &letter;
    printf("char value = %c\n", *(char *)ptr);

    // Use a void pointer to copy data by casting
    int copy = 0;
    ptr = &number;
    copy = *(int *)ptr; // cast to correct type before read
    printf("copied int value = %d\n", copy);

    return 0;
}
