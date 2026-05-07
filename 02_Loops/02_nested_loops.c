/*
Nested Loops
    1. Right Half Pyramid pattern
    2. Inverted Right Half Pyramid Pattern

*/


#include <stdio.h>
int main()
{
    int rows;
    printf("\n\nPattern printing\n\n");
    printf("\nEnter no of rows : ");
    scanf("%d", &rows);
    
    
    // 1. Right Half Pyramid pattern
    printf("\n\n1. Right Half Pyramid pattern\n\n");

    int i, j;
    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
    printf("\n");
    }
    
    
    // 2. Inverted Right Half Pyramid Pattern
    printf("\n\n2. Inverted Right Half Pyramid Pattern\n\n");
    
    int a, b;
    for(a = 1; a <= rows; a++)
    {
        for(b = rows; b >= a; b--)
        {
            printf("*");
        }
        printf("\n");
    }
    
