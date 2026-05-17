#include <stdio.h>

/*
Array Size Calculation in C

1. Total size of an array in bytes
2. Size of one element
3. Number of elements in an array
4. Size calculation for different data types

- sizeof gives size in bytes
- Total number of elements = sizeof(array) / sizeof(array[0])
- This works correctly when used in the same scope as the array
*/

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};
    char grades[4] = {'A', 'B', 'C', 'D'};
    float values[3] = {1.5f, 2.5f, 3.5f};

    int numbers_total_size = sizeof(numbers);
    int numbers_one_element_size = sizeof(numbers[0]);
    int numbers_count = sizeof(numbers) / sizeof(numbers[0]);

    int grades_total_size = sizeof(grades);
    int grades_one_element_size = sizeof(grades[0]);
    int grades_count = sizeof(grades) / sizeof(grades[0]);

    int values_total_size = sizeof(values);
    int values_one_element_size = sizeof(values[0]);
    int values_count = sizeof(values) / sizeof(values[0]);

    printf("1. Integer array size details:\n");
    printf("Total size of numbers array      = %d bytes\n", numbers_total_size);
    printf("Size of one numbers element      = %d bytes\n", numbers_one_element_size);
    printf("Number of elements in numbers    = %d\n", numbers_count);

    printf("\n2. Character array size details:\n");
    printf("Total size of grades array       = %d bytes\n", grades_total_size);
    printf("Size of one grades element       = %d bytes\n", grades_one_element_size);
    printf("Number of elements in grades     = %d\n", grades_count);

    printf("\n3. Float array size details:\n");
    printf("Total size of values array       = %d bytes\n", values_total_size);
    printf("Size of one values element       = %d bytes\n", values_one_element_size);
    printf("Number of elements in values     = %d\n", values_count);

    /*
    Traversing array using calculated size
    */
    printf("\n4. Traversing numbers using calculated count:\n");
    for(int i = 0; i < numbers_count; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    /*
    Same formula with another array
    */
    printf("\n5. Traversing grades using calculated count:\n");
    for(int i = 0; i < grades_count; i++)
    {
        printf("grades[%d] = %c\n", i, grades[i]);
    }

    printf("\nBasic Test Cases:\n");

    if(numbers_count == 5)
        printf("Test 1 Passed: numbers array count is correct\n");
    else
        printf("Test 1 Failed\n");

    if(grades_count == 4)
        printf("Test 2 Passed: grades array count is correct\n");
    else
        printf("Test 2 Failed\n");

    if(values_count == 3)
        printf("Test 3 Passed: values array count is correct\n");
    else
        printf("Test 3 Failed\n");

    if(numbers_total_size == numbers_one_element_size * numbers_count)
        printf("Test 4 Passed: total size formula is correct for numbers\n");
    else
        printf("Test 4 Failed\n");

    printf("\nDebug Notes:\n");

    printf("Debug 1: sizeof(array) gives total bytes used by the full array\n");
    printf("Debug 2: sizeof(array[0]) gives bytes used by one element\n");
    printf("Debug 3: Dividing total size by one element size gives element count\n");
    printf("Debug 4: Different data types may have different element sizes\n");
    printf("Debug 5: Use calculated count in loops to avoid hardcoding values\n");

    /*
    Wrong ideas:

    int count = sizeof(numbers);
    // Wrong for element count. This gives total bytes, not number of elements.

    for(int i = 0; i <= numbers_count; i++)
    {
        printf("%d\n", numbers[i]);
        // Wrong because valid index is 0 to numbers_count - 1
    }
    */

    return 0;
}
