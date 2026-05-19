/*
Counting the frequency of number in an array.
*/

#include <stdio.h>
int main()
{
    // Array declaration and Initialization
    int a[10] = {1,2,2,3,4,2,5,2,6,2};
    int input_number;
    
    printf("\n\nCounting Frequency of number in array :\n\n");
    printf("Enter the number to find how many times it appears :\t");
    scanf("%d", &input_number);
    
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        if(a[i] == input_number)
        {
            count += 1;
        }
    }
    
    if (count != 0)
    {
        printf("\n%d appears %d times", input_number, count);
    }
    else
    {
        printf("\n%d is not found in array.\n", input_number);
    }
    
    return 0;
}