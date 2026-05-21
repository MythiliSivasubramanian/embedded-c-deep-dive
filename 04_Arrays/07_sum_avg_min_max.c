/*
1. Sum of array elements :
        a. Using loops and indexing
        b. Using loops and pointer arithmetic
2. Average of array elements
        a. Average = Sum / sizeof(array)
3. Max and Min Value
    
*/


#include <stdio.h>
#define size 5
int main()
{
    int a[size] = {1,2,3,4,5};
    int sum = 0;
    
    // 1. Finding sum of array elements 
    // Method 1 : using indexing
    
    printf("\n\n1. Sum of all elements :\n");
    for (int i = 0; i <= size - 1; i++)
    {
        sum += a[i];
    }
    printf("\n\tMethod 1: Using loops and indexing : %d\n", sum);
    
    // 1. Method 2 : Finding sum using Pointer Arithmetic
    int total = 0;
    
    for(int j = 0; j <= size - 1; j++)
    {
        total += *(a + j);
    }
    printf("\n\tMethod 2: Using loops and pointer arithmentic: %d\n", total);
    
    // 2. Finding average of elements
    int count = sizeof(a) / sizeof(a[0]) 
    int average = total / count;
    printf("\n\n2. Average of elements : %d\n", average);
    
    // 3. Finding max and min value in array
    int max = a[0];
    int min = a[0];
    
    for (int k = 0; k <= size - 1; k++)
    {
        if(a[k] > max)
        {
            max = a[k];
        }
        if(a[k] < min)
        {
            min = a[k];
        }

    }
    printf("\n\n3. Element with maximum  and minimum value :\n");
    printf("\n\tMax : %d", max);
    printf("\n\tMin : %d\n", min);

    return 0;
    
}