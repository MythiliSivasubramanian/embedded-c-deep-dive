/*

Basic triangle pattern programs using nested loops
    1. Stars with fixed number of rows (5) and columns(2)
    2. Increasing Triangle
    3. Decreasing Triangle
    
*/


#include <stdio.h>

int main()
{
    int total_rows = 5; // fixed total number of rows (5)
    int rows, columns;
    
    // Stars with fixed number of rows and columns. Rows = 5 ; Columns = 2
    printf("\n\n1. Stars with fixed number of rows (5) and columns(2) :\n\n");

    // Outer for loop controls total number of rows (5)
    for(rows = 1; rows <= total_rows; rows++)
    {
        // Inner loop controls columns(content on each row)
        for(columns = 1; columns <= 2; columns++)
        {
            printf("* ");
        }
        
        printf("\n");        
    }


    // Increasing Triangle 
    // Total number of rows = 5

    printf("\n\n2. Increasing Triangle :\n\n");

        
    // Outer for loop controls the total number rows = 5
    for(rows = 1; rows <= total_rows; rows++)
    {
        // Inner loop controls columns(content on each row)
        // number of stars in each row == current row number (rows)
        for(columns = 1; columns <= rows; columns++)
            {
                printf("* ");
            }
        
        printf("\n");
    }
    
    // 3. Decreasing Triangle
    // Total number of rows = 5
    
    // Method 1:
    printf("\n\n3. Decreasing Triangle :\n\n\tMethod 1: \n\n");
    
    // Outer for loop controls the total number of rows. 
    for(rows = 1; rows <= total_rows; rows++)
    {
        //inner for loop control how many each times it prints in each row
        
        // columns >= rows : Loop runs from total_rows down to current row number
        for(columns = total_rows; columns >= rows; columns--)
        {
            printf("* ");
        }
        
        printf("\n");
    }
    
    // 3. Decreasing Triangle
    // Total number of rows = 5
    
    // Method 2:
    printf("\n\n\tMethod 2: \n\n");
    
    // Outer for loop controls the total number of rows
    for (rows = 1; rows <= total_rows; rows++)
    {
        
        // Inner for loop controls the number of items on each row
        for(columns = 1; columns <= total_rows - rows + 1; columns++)
        {
            printf("* ");
        }
        
        printf("\n");
    }

    
    return 0; // on successful execution
    
}
