/*
Bubble Sorting in descending
 Buuble sort compares two adjacent elements and 
swaps if 1st element is smaller than 2nd element

*/

#include<stdio.h>
int main()
{
    // Array declaration and initialization
    int array[5] = {5,1,4,2,8};
    
    // Printing the array before sorting
    printf("\n\nPrinting array before sorting :\n");
    for(int element = 0; element < 5; element++)
    {
        printf("%d\t", array[element]);
    }
    
    
    /* Bubble sort in descending
    Buuble sort compares two adjacent elements and 
    swaps if 1st element is smaller than 2nd element
    */
   
    // Outer loop iterates based on the total number of elements
    for(int pass = 0; pass < 4; pass++)
    {
        // Inner loop compares 2 adjacent elements
        for(int i = 0; i < 4  - pass; i++)
        {
            // 2 adjacent elemenst comparision
            if(array[i] < array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    
    // Printing the array after sorting
    printf("\n\nPrinting array after sorting in descending :\n");
    for(int element = 0; element < 5; element++)
    {
        printf("%d\t", array[element]);
    }
    
    
    return 0;
    
}