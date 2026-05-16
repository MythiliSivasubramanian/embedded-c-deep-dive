#include <stdio.h>

/*
Array Declaration Variants in C

This file covers:
1. Different ways of array declaration
2. Different ways of array initialization
3. Basic test cases
4. Common debugging points

Important:
- Array index always starts from 0
- Accessing outside array size is undefined behavior
- Local array should be initialized before use
*/

int main(void)
{
    /*
    1. Array declaration first, values assigned later
    */
    int a[4];
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;

    /*
    2. Array declaration with full initialization
    */
    int b[5] = {1, 2, 3, 4, 5};

    /*
    3. Array declaration with partial initialization
       Remaining elements become 0
    */
    int c[5] = {11, 22};

    /*
    4. Array declaration without size
       Compiler counts the elements
    */
    int d[] = {100, 200, 300, 400};

    /*
    5. Array initialized with all zeros
    */
    int e[5] = {0};

    /*
    6. Character array
    */
    char grade[4] = {'A', 'B', 'C', 'D'};

    /*
    7. String style character array
       Compiler adds '\0' at the end
    */
    char name[] = "ARRAY";

    /*
    8. Two-dimensional array
    */
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("1. Array a values assigned later:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("\n2. Array b full initialization:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }

    printf("\n3. Array c partial initialization:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("c[%d] = %d\n", i, c[i]);
    }

    printf("\n4. Array d without giving size:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("d[%d] = %d\n", i, d[i]);
    }

    printf("\n5. Array e all zero values:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("e[%d] = %d\n", i, e[i]);
    }

    printf("\n6. Character array grade:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("grade[%d] = %c\n", i, grade[i]);
    }

    printf("\n7. String style char array:\n");
    printf("name = %s\n", name);

    printf("\n8. Two-dimensional array values:\n");
    for(int row = 0; row < 2; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            printf("matrix[%d][%d] = %d\n", row, col, matrix[row][col]);
        }
    }

    printf("\nBasic Test Cases:\n");

    if(a[0] == 10)
        printf("Test 1 Passed: a[0] is correct\n");
    else
        printf("Test 1 Failed\n");

    if(b[4] == 5)
        printf("Test 2 Passed: b[4] is correct\n");
    else
        printf("Test 2 Failed\n");

    if(c[2] == 0)
        printf("Test 3 Passed: remaining elements in c become 0\n");
    else
        printf("Test 3 Failed\n");

    if(d[3] == 400)
        printf("Test 4 Passed: d array size counted correctly\n");
    else
        printf("Test 4 Failed\n");

    if(e[4] == 0)
        printf("Test 5 Passed: e is zero initialized\n");
    else
        printf("Test 5 Failed\n");

    if(name[0] == 'A')
        printf("Test 6 Passed: string array first character is correct\n");
    else
        printf("Test 6 Failed\n");

    if(matrix[1][2] == 6)
        printf("Test 7 Passed: matrix value is correct\n");
    else
        printf("Test 7 Failed\n");

    printf("\nDebug Notes:\n");

    // Debug 1: Always use valid index only
    printf("Debug 1: For array a[4], valid index is 0 to 3\n");

    // Debug 2: Partial initialization fills remaining elements with 0
    printf("Debug 2: In array c, c[2], c[3], c[4] become 0\n");

    // Debug 3: Zero initialization is useful in embedded systems
    printf("Debug 3: int e[5] = {0}; makes all values zero\n");

    // Debug 4: Char array and string are not always same
    printf("Debug 4: grade is a char array, name is a string style char array\n");

    // Debug 5: Out-of-bounds examples are dangerous, so only shown in comments
    /*
    Wrong examples:
    a[4] = 50;        // Wrong because valid index is only 0 to 3
    b[5] = 60;        // Wrong because valid index is only 0 to 4
    */
    printf("Debug 5: Never access outside the array size\n");

    // Debug 6: Uninitialized array may contain garbage values
    printf("Debug 6: If we declare array and do not assign values, output may be garbage\n");

    return 0;
}
