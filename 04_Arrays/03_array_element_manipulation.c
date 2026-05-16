#include <stdio.h>

/*
Array Element Manipulation in C

This file covers different ways of manipulating array elements:
1. Reading elements
2. Updating elements directly
3. Updating elements using loop
4. Incrementing elements
5. Decrementing elements
6. Multiplying elements
7. Dividing elements
8. Swapping elements
9. Reversing elements
10. Copying one array into another
11. Setting all elements to same value
12. Accessing and changing values using pointer style

Important:
- Valid index for array of size 5 is 0 to 4
- Never access outside the array size
*/

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int b[5];
    int temp;

    printf("Original array:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    1. Reading array elements
    */
    printf("\n1. Reading elements:\n");
    printf("First element  = %d\n", a[0]);
    printf("Second element = %d\n", a[1]);
    printf("Last element   = %d\n", a[4]);

    /*
    2. Updating elements directly using index
    */
    printf("\n2. Updating elements directly:\n");
    a[0] = 100;
    a[2] = 300;
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    3. Updating all elements using loop
    */
    printf("\n3. Updating elements using loop:\n");
    for(int i = 0; i < 5; i++)
    {
        a[i] = a[i] + 5;
    }
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    4. Incrementing every element
    */
    printf("\n4. Incrementing every element by 1:\n");
    for(int i = 0; i < 5; i++)
    {
        a[i]++;
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    5. Decrementing every element
    */
    printf("\n5. Decrementing every element by 1:\n");
    for(int i = 0; i < 5; i++)
    {
        a[i]--;
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    6. Multiplying every element
    */
    printf("\n6. Multiplying every element by 2:\n");
    for(int i = 0; i < 5; i++)
    {
        a[i] = a[i] * 2;
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    7. Dividing every element
    */
    printf("\n7. Dividing every element by 2:\n");
    for(int i = 0; i < 5; i++)
    {
        a[i] = a[i] / 2;
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    8. Swapping first and last element
    */
    printf("\n8. Swapping first and last element:\n");
    temp = a[0];
    a[0] = a[4];
    a[4] = temp;
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    9. Reversing the array
    */
    printf("\n9. Reversing the array:\n");
    for(int i = 0; i < 5 / 2; i++)
    {
        temp = a[i];
        a[i] = a[4 - i];
        a[4 - i] = temp;
    }
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    10. Copying one array into another
    */
    printf("\n10. Copying array a into array b:\n");
    for(int i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
    for(int i = 0; i < 5; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }

    /*
    11. Setting all elements to same value
    */
    printf("\n11. Setting all elements of b to 0:\n");
    for(int i = 0; i < 5; i++)
    {
        b[i] = 0;
    }
    for(int i = 0; i < 5; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }

    /*
    12. Manipulating array using pointer style
    */
    printf("\n12. Updating using pointer style:\n");
    *(a + 0) = 111;
    *(a + 1) = 222;
    *(a + 2) = *(a + 2) + 10;
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("\nBasic Test Cases:\n");

    if(a[0] == 111)
        printf("Test 1 Passed: pointer update worked for a[0]\n");
    else
        printf("Test 1 Failed\n");

    if(a[1] == 222)
        printf("Test 2 Passed: pointer update worked for a[1]\n");
    else
        printf("Test 2 Failed\n");

    if(b[0] == 0 && b[4] == 0)
        printf("Test 3 Passed: all elements of b are set to 0\n");
    else
        printf("Test 3 Failed\n");

    if(a[2] == 315 && a[4] == 55)
        printf("Test 4 Passed: reverse and later updates worked correctly\n");
    else
        printf("Test 4 Failed\n");

    printf("\nDebug Notes:\n");

    // Debug 1
    printf("Debug 1: Use only valid index from 0 to 4 for arrays of size 5\n");

    // Debug 2
    printf("Debug 2: While swapping, always use a temporary variable\n");

    // Debug 3
    printf("Debug 3: While reversing, loop only till size/2\n");

    // Debug 4
    printf("Debug 4: Copying one array to another needs loop element by element\n");

    // Debug 5
    printf("Debug 5: a[i] and *(a + i) both access the same element\n");

    // Debug 6
    printf("Debug 6: Division on integer array gives integer result only\n");

    /*
    Wrong examples. 

    a[5] = 100;      // Wrong. Out of bounds
    b[-1] = 10;      // Wrong. Negative index
    */

    return 0;
}
