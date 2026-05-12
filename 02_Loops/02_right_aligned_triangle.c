/*
Basic triangle pattern programs using nested loops

1. Right aligned Triangle (Stars without spaces)
2. Right aligned Triangle (stars with spaces in between)


*/

#include <stdio.h>

int main()
{
    
    // 1. Right aligned Triangle (Stars without spaces)
    
    // Fixed total number of rows = 5
    int total_rows = 5;
    int row,column;
    
    printf("\n\n1. Right aligned Triangle :\n\n\tStars without Spaces : \n\n");
    // Outer for loop controls the total number of rows
    for(row = 1; row <= total_rows; row++)
    {
        
        // Inner for loop control the iterations on each row
        // 1st inner for loop control number of spaces on each row (controls LEFT padding)
        // spaces = total number rows - current row number
        for(column = 1; column <= total_rows - row; column++)
        {
            printf(" ");
        }
        
        // 2nd for loop controls the numbers of iterartions of stars on each row
        for(column = 1; column <= row; column++)
        {
            printf("*");
        }
        
        printf("\n");
     
    }
    
    
    // 2. Right aligned Triangle (stars with spaces in between)
    printf("\n\n\tStars with Spaces in between : \n\n");
    
    // Outer for loop controls the total number of rows (5)
    for(row = 1; row <= total_rows; row++)
    {
        
        // 1st Inner for loop controls the iterations of spaces in each row
        for(column = 1; column <= total_rows - row; column++)
        {
            printf("  ");
        }
        
        // 2nd for loop controls iterations of stars with space in each row.
        // 1 star = 1 star with space (2 chars)
        for(column = 1; column <= row; column++)
        {
            printf("* ");
        }
        
        printf("\n");
        
    }
    
    return 0; // upon sucessful execution
    
}

