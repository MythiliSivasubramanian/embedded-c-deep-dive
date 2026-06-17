/*
Array insert/delete practice in C

 1. insert a new element at a specific position
 2. delete an element from a specific position
 3. keep array bounds safe while shifting elements

Important:
 - Arrays have fixed size in C
 - Insertion requires shifting elements to the right
 - Deletion requires shifting elements to the left
 - Always keep valid element count separate from array capacity
 - Out-of-bounds access is undefined behavior and must be avoided
*/

#include <stdio.h>

int main()
{
    int a[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int capacity = 10;
    int insertPos, deletePos;
    int value;

    printf("Initial array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // Insert element at a specific position
    insertPos = 2; // insert before current element at index 2
    value = 25;

    if (size < capacity && insertPos >= 0 && insertPos <= size)
    {
        for (int i = size; i > insertPos; i--)
        {
            a[i] = a[i - 1];
        }

        a[insertPos] = value;
        size++;

        printf("After insertion of %d at index %d: ", value, insertPos);
        for (int i = 0; i < size; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("Insertion failed: invalid position or no space.\n\n");
    }

    // Delete element from a specific position
    deletePos = 4; // remove current element at index 4

    if (size > 0 && deletePos >= 0 && deletePos < size)
    {
        for (int i = deletePos; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }

        size--; // do not clear the old slot, just reduce logical size

        printf("After deletion at index %d: ", deletePos);
        for (int i = 0; i < size; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("Deletion failed: invalid position or empty array.\n\n");
    }

    // Final array state
    printf("Final array size = %d\n", size);
    printf("Final array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
