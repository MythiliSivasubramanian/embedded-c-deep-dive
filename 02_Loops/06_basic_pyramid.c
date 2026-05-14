/*
1. Expected Output:
        *
       * *
      * * *
     * * * *
    * * * * *
    
*/

#include <stdio.h>

int main()
{
    int total_rows = 5;
    int row, column;
    
    printf("\n\nTask 1 :\n\n");
    
    // Outer for loop controls the total number of rows
    for(row = 1; row <= total_rows; row++)
    {
        
        // 1st inner loop controls iterations of Spaces on each row
        for(column = 1; column <= total_rows - row; column++)
        {
            printf(" ");
        }
        
        // 2nd inner loop controls iterations of stars on each row
        for(column = 1; column <= row; column++)
        {
                // Space after each star 
                printf("* ");
        }
        
        printf("\n");
    }
    
    return 0; // Upon successful execution
}
    
