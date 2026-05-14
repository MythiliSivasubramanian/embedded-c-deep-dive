/*
Basic triangle patterns using nested loops.
1. Right angle triangle with same row numbers.

    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    
2. Right angle triangle with repeated different row numbers

    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
    
3. Print the below

        *
       **
      ***
     ****
    *****
  
*/

#include <stdio.h>

int main()
{
    int total_rows = 5;
    int row,column;
    
    printf("\n\nBasic triangles with numbers using nested loops\n\n");
    printf("\n\n1. Right angle triangle with same row numbers :\n\n");
    
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
    
    // 2. Right angle triangle with repeated different row numbers
    printf("\n\n2. Right angle triangle with repeated different row numbers :\n\n");
    
    // Outer loop controls the total number of rows
    for(row = 1; row <= total_rows; row++)
    {
        // Inner loops controls how many time the row number is printed
        for(column = 1; column <= row; column++)
        {
            // The row numbers needs to be row'th times repeated
            printf("%d ", row);
        }
        
        printf("\n");
    }
    
    
    
    // Task 3
    printf("\n\nTask 3 : \n\n");
    
    // Outer loop controls the total number of rows
    for(row = 1; row <= total_rows; row++)
    {
        
        // 1st inner loop controls iterations of spaces on each row
        for(column = 1; column <= total_rows - row; column++)
        {
            printf(" ");
        }
        
        // 2nd inner loop controls iterations of stars on each row
        for(column = 1; column <= row; column++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0; // Upon sucessfull execution
    
    
}