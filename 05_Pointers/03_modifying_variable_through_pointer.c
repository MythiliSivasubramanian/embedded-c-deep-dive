/*

Modiying a variable using pointer in a function.

Given the temperature of a system as 25, update its temparature by adding 3 through a function 
Print temperature before function call
Call function
Print temperature after function call

*/

#include <stdio.h>

void modify_temperature(int *ptr);

int main()
{
    
    printf("\n\nModiying a variable in a function using pointer\n");

    // Predefined temeparture
    int temperature = 25;
    printf("\nBefore function call :\n");
    printf("\tOriginal temperature : %d\n", temperature);
    printf("\tAddress of variable temperature : %p\n\n", (void *)&temperature);
    
    // Function call
    modify_temperature(&temperature);
    
    // Printing after function call
    printf("\nAfter function call :\n");
    printf("\tNew temperature : %d\n", temperature);
    printf("\tAddress of variable temperature : %p\n\n", (void *)&temperature);
    
    return 0;
}

void modify_temperature(int *ptr)
{
    *ptr = *ptr + 2;
    
}