/*
Pointer Arithmetic in C

1. Increment and decrement pointers
2. Moving through arrays using pointers
3. Accessing elements via pointer offsets
4. Difference between pointers
*/

#include <stdio.h>

int main()
{
    int data[6] = {5, 10, 15, 20, 25, 30};
    int *p = data; // points to the first element

    printf("\n\nPointer arithmetic with array elements:\n");
    for(int i = 0; i < 6; i++)
    {
        printf("data[%d] = %d, address = %p\n", i, *(p + i), (void *)(p + i));
    }

    printf("\nAdvance pointer by 2 positions:\n");
    p += 2; // now points to data[2]
    printf("Current element = %d\n", *p);
    printf("Current address = %p\n", (void *)p);

    printf("\nMove pointer backward by 1 position:\n");
    p--;
    printf("Current element = %d\n", *p);
    printf("Current address = %p\n", (void *)p);

    // Compare pointer positions
    int *start = data;
    int *end = data + 5;
    printf("\nPointer difference between end and start: %ld\n", end - start);

    return 0;
}
