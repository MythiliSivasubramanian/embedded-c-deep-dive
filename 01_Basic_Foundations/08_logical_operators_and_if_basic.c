/*

Logical Operators:  
Basic If condition

*/


#include <stdio.h>

// Logical AND
int main() 
{
    int temp = 35;
    int humidity = 70;

    // && logical operator,  & bitwise operator
    if (temp > 30 && humidity > 60) 
    {
        printf("Fan ON\n");
    }

    return 0;
}   

// Logical OR
int motion = 0;
int button = 1;

if (motion == 1 || button == 1) 
{
    printf("Light ON\n");
}

// Logical NOT
int door_closed = 0;

if (!door_closed) 
{
    printf("Alarm ON\n");
}