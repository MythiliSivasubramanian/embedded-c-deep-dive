/*
    Pattern Printing 

    Topics Covered:
    1. Right Half Pyramid
   
*/

#include <stdio.h>

int main()
{
    int rows;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);



    // 1. Right Half Pyramid
    printf("\n\n1. Right Half Pyramid\n\n");

    /*
        stars = i
    */

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    
    return 0;
    
}

