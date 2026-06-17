/*
Finding pairs in an array that sum to a target value


 1. finding pairs that add up to a specific sum
 2. using a two-pointer approach on sorted arrays
 3. using nested loops for unsorted arrays
 4. counting total pairs or printing pairs
 5. avoiding duplicate pairs

Important :
 - brute force approach is O(n^2)
 - sorted array with two pointers is O(n log n) with sorting overhead
 - in embedded systems, this is useful for signal processing and data analysis
 - careful with duplicate handling to avoid counting the same pair twice
*/

#include <stdio.h>

int main()
{
    int arr[8] = {10, 20, 30, 40, 50, 15, 25, 35};
    int size = 8;
    int targetSum = 50;

    printf("=== Finding Pairs with Target Sum (Brute Force) ===\n\n");

    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Target Sum: %d\n\n", targetSum);

    printf("Pairs found:\n");
    int pairCount = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == targetSum)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
                pairCount++;
            }
        }
    }

    printf("\nTotal pairs: %d\n\n", pairCount);

    // Two-pointer approach on sorted array
    printf("=== Two-Pointer Approach (After Sorting) ===\n\n");

    // Simple bubble sort for demonstration
    int sortedArr[8];
    for (int i = 0; i < size; i++)
    {
        sortedArr[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (sortedArr[j] > sortedArr[j + 1])
            {
                int temp = sortedArr[j];
                sortedArr[j] = sortedArr[j + 1];
                sortedArr[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sortedArr[i]);
    }
    printf("\n\n");

    printf("Pairs found using two pointers:\n");
    int left = 0;
    int right = size - 1;
    int twoPointerCount = 0;

    while (left < right)
    {
        int sum = sortedArr[left] + sortedArr[right];

        if (sum == targetSum)
        {
            printf("(%d, %d)\n", sortedArr[left], sortedArr[right]);
            twoPointerCount++;
            left++;
            right--;
        }
        else if (sum < targetSum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    printf("\nTotal pairs (two-pointer): %d\n\n", twoPointerCount);

    // Demonstrate with different target sum to avoid duplicates
    int targetSum2 = 60;

    printf("=== Finding Pairs with Target Sum: %d ===\n\n", targetSum2);

    printf("Pairs found:\n");
    int pairCount2 = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == targetSum2)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
                pairCount2++;
            }
        }
    }

    printf("\nTotal pairs: %d\n", pairCount2);

    return 0;
}
