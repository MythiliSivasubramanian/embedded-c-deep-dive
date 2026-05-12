/*
Basic triangle patterns using nested loops.
1. Right anfle triangle with numbers.

    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    
*/

#include <stdio.h>

int main()
{
    int total_rows = 5;
    int row,column;
    
    // Outer for loop controls the total number of rows(5)
    for(row = 1; row <= total_rows; row++)
    {
        
        // Inner loop controls iterations of numbers on each row
        for(column = 1; column <= row; column++)
        {
            printf("%d ",column);
        }
        
        printf("\n");
    }
    
    return 0;
    
}