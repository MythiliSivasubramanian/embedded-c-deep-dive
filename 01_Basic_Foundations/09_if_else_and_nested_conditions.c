// If else, else if ladder and Nested if examples.

#include <stdio.h>

// Basic If else 

int main() 
{
    int button = 1;

    if (button == 1) 
    {
        printf("LED ON\n");
    } 
    else 
    {
        printf("LED OFF\n");
    }

// else-if ladder
    int temp = 65;

    if (temp > 80) 
    {
        printf("CRITICAL\n");
    } 
    else if (temp > 60) 
    {
      
        printf("HIGH\n");
    } 
    else if (temp > 40) 
    {
        printf("NORMAL\n");
    } 
    else 
    {
        printf("LOW\n");
    }

// Nested if

    int system_ok = 1;

    if (temp > 60) 
    {
        if (system_ok) 
        {
            printf("FAN ON\n");
        }
    }

// Combined condition 
    if (temp > 60 && system_ok) 
    {
        printf("FAN ON (Optimized)\n");
    }

    return 0;
}
