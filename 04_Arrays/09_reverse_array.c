#include <stdio.h>
#define size 10
int main()
{
    int a[size] = {10,20,30,40,50,60,70,80,90,100};
    
    // Printing elements (before reversing)
    printf("\n\nPrinting elements of array \n\n\tBefore reversing :\n\n");
    
    for(int i = 0; i <= size - 1; i++)
    {
        printf("Index %d : %d\n", i, a[i]);
    }    
    
    
    // Reversing the array in place
    int start = 0;
    int end = size - 1; // Array index starts at 0. Hence end is size - 1
    int temp;
    
    while(start < end) // loop ends when mid value is reached ( start == end)
    {
        temp = a[start]; 
        a[start] = a[end];
        a[end] = temp;
        
        start++;
        end--;
        
    }
    
    printf("\n\nfter reversing :\n\n");
    for(int j = 0; j <= size - 1; j++)
    {
        printf("Index %d : %d\n", j, a[j]);
    }   
    
    return 0;
}