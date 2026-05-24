/*
Bubble Sort in Ascending Order

This program demonstrates:
1. Printing the array before sorting
2. Sorting using bubble sort
3. Printing the array after sorting


*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int numbers[SIZE] = {5, 1, 4, 2, 8};

    printf("Array before sorting:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }

    printf("\n");

    for(int pass = 0; pass < SIZE - 1; pass++)
    {
        // Bubble sort repeatedly compares adjacent elements
        // and swaps them if they are in the wrong order.
        for(int j = 0; j < SIZE - 1 - pass; j++)
        // after each pass, the largest unsorted element moves to its correct position at the end.
        // Hence SIZE - pass - 1
        {
            if(numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("\nArray after sorting in ascending order:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t", numbers[i]);
    }

    printf("\n");

    return 0;
}
