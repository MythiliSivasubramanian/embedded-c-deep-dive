#include <stdio.h>

/*
Array Traversal Patterns in C

1. Forward traversal
2. Reverse traversal
3. Traversal using array size
4. Traversal of selected elements
5. Safe traversal rules

- Traversal means visiting array elements one by one
- Valid index for an array of size 5 is 0 to 4
- Never go outside the array boundary
*/

int main(void)
{
    int marks[5] = {78, 85, 92, 67, 88};
    int size = sizeof(marks) / sizeof(marks[0]);

    printf("Original array values:\n");
    for(int i = 0; i < size; i++)
    {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    /*
    1. Forward traversal
       Start from index 0 and move to the last index
    */
    printf("\n1. Forward traversal:\n");
    for(int i = 0; i < size; i++)
    {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    /*
    2. Reverse traversal
       Start from last index and move toward index 0
    */
    printf("\n2. Reverse traversal:\n");
    for(int i = size - 1; i >= 0; i--)
    {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    /*
    3. Traversal using array size variable
       This makes the loop easier to change later
    */
    printf("\n3. Traversal using size variable:\n");
    for(int i = 0; i < size; i++)
    {
        printf("Element at position %d is %d\n", i, marks[i]);
    }

    /*
    4. Traversal of selected elements
       Visit only even index positions: 0, 2, 4
    */
    printf("\n4. Traversal of even index positions:\n");
    for(int i = 0; i < size; i = i + 2)
    {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    /*
    5. Traversal of a part of the array
       Visit from index 1 to index 3
    */
    printf("\n5. Partial traversal from index 1 to index 3:\n");
    for(int i = 1; i <= 3; i++)
    {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    printf("\nBasic Test Cases:\n");

    if(size == 5)
        printf("Test 1 Passed: array size is correct\n");
    else
        printf("Test 1 Failed\n");

    if(marks[0] == 78 && marks[4] == 88)
        printf("Test 2 Passed: first and last elements are correct\n");
    else
        printf("Test 2 Failed\n");

    if(marks[2] == 92)
        printf("Test 3 Passed: middle element is correct\n");
    else
        printf("Test 3 Failed\n");

    printf("\nDebug Notes:\n");

    printf("Debug 1: Forward traversal uses i = 0 to i < size\n");
    printf("Debug 2: Reverse traversal starts from size - 1\n");
    printf("Debug 3: sizeof(marks) / sizeof(marks[0]) gives number of elements\n");
    printf("Debug 4: i = i + 2 skips every alternate index\n");
    printf("Debug 5: Always keep loop condition inside valid range\n");

    /*
    Wrong examples:

    for(int i = 0; i <= size; i++)
    {
        printf("%d\n", marks[i]);   // Wrong because last valid index is size - 1
    }

    for(int i = -1; i < size; i++)
    {
        printf("%d\n", marks[i]);   // Wrong because negative index is invalid
    }
    */

    return 0;
}
