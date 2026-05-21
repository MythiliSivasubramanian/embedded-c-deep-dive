/*
To find largest and Second Largest Element from an array
*/

#include <stdio.h>
int main()
{
    // Array declaration and initialization
    int a[7] = {10,40,20,90,50,90,30};
    
    int largest = a[0];
    int second_largest = -1;
    
    
    for(int i = 1; i < 7; i++)
    {
        if (a[i] > largest) 
        {
            second_largest = largest;      
            largest = a[i];                 
        }
        else if(a[i] > second_largest && a[i] != largest)    
        {
            second_largest = a[i];      
        }
        
        
    }
    if(second_largest == -1)
        {
            printf("\n\nNo second largest element\n\n");
        }
    else
        {
            printf("\n\nLargest element : %d\n", largest);
            printf("\n\nSecond largest : %d\n\n", second_largest);
        }
    
    return 0;
    
}
