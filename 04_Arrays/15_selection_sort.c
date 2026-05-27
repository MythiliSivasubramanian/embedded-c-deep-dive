/*
Selection Sort in Ascending Order

This program demonstrates:
1. Printing the array before sorting
2. Sorting using selection sort
3. Printing the array after sorting

Selection sort selects the smallest element from the unsorted
portion and places it at the beginning, repeating until sorted.

*/

#include <stdio.h>

#define SIZE 6

int main(void)
{
    int numbers[SIZE] = {29, 10, 14, 37, 13, 2};

    printf("Array before sorting:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }

    printf("\n");

    for (int i = 0; i < SIZE - 1; i++)
    {
        int min_idx = i;
        // Find index of minimum element in the remaining unsorted array
        for (int j = i + 1; j < SIZE; j++)
        {
            if (numbers[j] < numbers[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap if a smaller element was found
        if (min_idx != i)
        {
            int temp = numbers[i];
            numbers[i] = numbers[min_idx];
            numbers[min_idx] = temp;
        }
    }

    printf("\nArray after sorting in ascending order:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }

    printf("\n");

    return 0;
}
