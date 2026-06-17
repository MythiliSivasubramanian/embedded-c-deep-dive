/*
Array merge operations in C


 1. merging two sorted arrays into a third array
 2. merging two unsorted arrays into a third array
 3. combining arrays while preserving or sorting the result
 4. handling different array sizes

Important :
 - when merging sorted arrays, we can do it in O(n+m) time
 - when merging unsorted arrays, we can just combine or sort after
 - always ensure the destination array is large enough
 - in embedded systems, this is useful for combining sensor buffers or data logs
*/

#include <stdio.h>

int main()
{
    // Merging two sorted arrays
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[4] = {15, 25, 35, 45};
    int merged[9];  // size = size1 + size2
    int size1 = 5;
    int size2 = 4;
    int mergedSize = 0;

    printf("=== Merging Two Sorted Arrays ===\n\n");

    printf("Array 1: ");
    for (int i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // Two-pointer merge technique
    int i = 0;  // pointer for arr1
    int j = 0;  // pointer for arr2

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[mergedSize++] = arr1[i++];
        }
        else
        {
            merged[mergedSize++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1
    while (i < size1)
    {
        merged[mergedSize++] = arr1[i++];
    }

    // Copy remaining elements from arr2
    while (j < size2)
    {
        merged[mergedSize++] = arr2[j++];
    }

    printf("Merged sorted array: ");
    for (int k = 0; k < mergedSize; k++)
    {
        printf("%d ", merged[k]);
    }
    printf("\n\n");

    // Simple concatenation of two unsorted arrays
    int unsorted1[3] = {50, 10, 30};
    int unsorted2[3] = {25, 35, 15};
    int combined[6];

    printf("=== Merging Two Unsorted Arrays ===\n\n");

    printf("Unsorted Array 1: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", unsorted1[i]);
    }
    printf("\n");

    printf("Unsorted Array 2: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", unsorted2[i]);
    }
    printf("\n\n");

    // Copy unsorted1 to combined
    int combinedSize = 0;
    for (int i = 0; i < 3; i++)
    {
        combined[combinedSize++] = unsorted1[i];
    }

    // Copy unsorted2 to combined
    for (int i = 0; i < 3; i++)
    {
        combined[combinedSize++] = unsorted2[i];
    }

    printf("Combined array (unsorted): ");
    for (int i = 0; i < combinedSize; i++)
    {
        printf("%d ", combined[i]);
    }
    printf("\n\n");

    // Simple bubble sort on combined
    for (int i = 0; i < combinedSize - 1; i++)
    {
        for (int j = 0; j < combinedSize - 1 - i; j++)
        {
            if (combined[j] > combined[j + 1])
            {
                int temp = combined[j];
                combined[j] = combined[j + 1];
                combined[j + 1] = temp;
            }
        }
    }

    printf("Combined array (sorted): ");
    for (int i = 0; i < combinedSize; i++)
    {
        printf("%d ", combined[i]);
    }
    printf("\n");

    return 0;
}
