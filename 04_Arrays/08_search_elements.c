/*
1. Searching an element in an array
    a. Linear Search

*/

#include <stdio.h>
int main()
{
    int a[5] = {10,20,30,40,50};
    int search_number;
    int found = 0;
    
    printf("\n\n1. Element searching :\n");
    printf("\nEnter the number to search in the array :\t");
    scanf("%d", &search_number);
    
    // Compare search_number with all elements of array. 
    // When found, update found as 1 , print message and break loop
    for(int i = 0; i <= 4; i++)
    {
        if(search_number == a[i])
        {
            found = 1;
            printf("\nNumber %d is at Index %d\n", search_number, i);
            break;
        }

    }
    
    // Print based on the value of found
    if (found == 0)
    {
        printf("\n%d is not in array", search_number);
    }
    
    return 0;
}
