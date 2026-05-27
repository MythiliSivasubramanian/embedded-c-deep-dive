/*
Insertion Sort in Ascending Order

This program demonstrates:
1. Printing the array before sorting
2. Sorting using insertion sort
3. Printing the array after sorting

Insertion sort builds the sorted array one element at a time
by inserting each new element into its correct position.

*/

#include <stdio.h>

#define SIZE 7

int main(void)
{
    int numbers[SIZE] = {12, 11, 13, 5, 6, 7, 1};

    printf("Array before sorting:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");

    for (int i = 1; i < SIZE; i++)
    {
        int key = numbers[i];
        int j = i - 1;

        // Move elements of numbers[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }

    printf("\nArray after sorting in ascending order:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");

    return 0;
}
