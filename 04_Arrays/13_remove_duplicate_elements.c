/*
Removing Duplicate elements in an array without creating new array
predefined array:
int a[10] = {1,2,2,3,4,2,5,5,6,6};
expected output:
1 2 3 4 5 6

*/


#include <stdio.h>

int main()
{
    // Array declaration and initialization
    int a[] = {1, 2, 2, 3};
    int size = 4;
    
    // Remove duplicates by shifting elements left when found
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(a[i] == a[j])
            {
                // Shift elements to the left to remove duplicate
                for(int k = j; k < size - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                size--;
                j--;  // Recheck the current position after shift
            }
        }
    }
    
    // Print the array with unique elements
    for(int i = 0; i < size; i++) 
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    
    return 0;
}