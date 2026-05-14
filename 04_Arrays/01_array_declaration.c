/*
Arrays Foundations in C

1. Array declaration
2. Runtime input using loops
3. Safe array traversal
4. Important notes:
   a. Uninitialized elements
   b. Out-of-bounds access (undefined behavior)

IMPORTANT CONCEPTS:

1. Uninitialized Elements:
   - If an array element is not assigned a value, then it contains undefined (garbage) data.
   - Example: a[3], a[4] if not initialized.

2. Out-of-Bounds Access:
   - Accessing index outside valid range causes undefined behavior.
   - Example:
       int a[5];
       Valid indices: 0 to 4
       Invalid: a[5], a[6] 

   - This can lead to crashes or memory corruption, especially in embedded systems.

Always ensure loops stay within array bounds.
*/

#include <stdio.h>

int main()
{
    int a[5];

    // Input section
    printf("Enter 5 elements of the array:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &a[i]);
    }

    // Output section
    printf("\nArray elements are:\n");

    for(int j = 0; j < 5; j++)
    {
        printf("a[%d] = %d\n", j, a[j]);
    }

    return 0;
}