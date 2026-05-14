/*
1. Centered Pyramid with stars:
Expected Output:
        *
       * *
      * * *
     * * * *
    * * * * *
    
2. Centered Pyramid with numbers
Expected Output:

        1
       1 2
      1 2 3
     1 2 3 4
    1 2 3 4 5
    
3. Inverted Pyramid with stars
Expected Output:

*********
 *******
  *****
   ***
    *

*/

#include <stdio.h>

int main()
{
    int total_rows = 5;
    int row, column;
    
    // Task 1 : Centered Pyramid with stars :
    printf("\n\nTask 1 : Centered Pyramid with stars :\n\n");
    
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
    
    // Task 2: Centered Pyramid with numbers
    printf("\n\n Task 2: Centered Pyramid with numbers : \n\n");
    
    // Outer loop controls the total number of rows
    for(row = 1; row <= total_rows; row++)
    {
        
        // 1st Inner loop controls iterations of spaces in each row
        for(column = 1; column <= total_rows - row; column++)
        {
            printf(" ");
        }
        
        // 2nd inner loop controls iterations of numbers on each row
        for(column = 1; column <= row; column++)
        {
            // Column numbers gets printed with space as suffix
            printf("%d ", column);
        }
        printf("\n");
    }
  
    // Inverted Pyramid with stars
    printf("\n\nTask 3: Inverted Pyramid with stars :\n\n");
    
    // Outer loop controls total nbumber of rows
    for(row = 1; row <= total_rows; row++)
    {
        // 1st inner loop controls number of leading spaces in each row
        for(column = 1; column <= row - 1; column++)
        {
            printf(" ");
        }
        
        // 2nd inner loop controls iterations of stars on each row
        
        for(column = 1; column <= 2 * (total_rows - row) + 1; column++)
        {
            printf("*");       
        }
        
        printf("\n");
        
    }
    
    return 0; // Upon successful execution
}
    
