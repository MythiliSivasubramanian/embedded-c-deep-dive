/*
1. Rotating right by one position:
    Predefined Array : 
        int array = {1,2,3,4,5};
    Expected Output :
        int array = {5,1,2,3,4};

2. Rotate right by K positions

*/


#include <stdio.h>
#define SIZE 5
int main()

{
    // Array declaration and initialization
    int array[SIZE] = {1,2,3,4,5};

    // 1. Rotating right by one position
    printf("\n\n\nTask 1. Rotating array right by one position");
    
    // Printing elements of array
    printf("\n\nArray before rotation : \n");
        
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t", array[i]);
    }
    
    // Temp variable to store the last element
    int temp = array[SIZE - 1];
    
    // Right to left shift
    for (int j = SIZE - 1 ; j > 0 ; j--)
    {
        array[j] = array[j - 1];
    }
    
    // Restore temp to first position
    array[0] = temp;
    
    // Printing array after rotation
    printf("\n\nArray after rotation :\n");
    for(int z = 0; z < SIZE; z++)
    {
        printf("%d\t", array[z]);
    }
    
    // 2.  Rotate right by K positions
    
    // Input for the number of positions to rotate
    int rotate_positions;
    
    printf("\n\n\nTask 2. Rotate array right by K positions ");
    
    printf("\n\nEnter the number of positions to be rotated (k): \t");
    scanf("%d", &rotate_positions);
    // When Array size == number of positions to be rotated, its one fiull cycle, which is same is 
    // original array. 
    rotate_positions = rotate_positions % SIZE;

    
    // Printing elements of array
    printf("\n\nArray before rotation : \n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t", array[i]);
    }
    
        
    for (int rotation = 1; rotation <= rotate_positions; rotation++)
    {
        // Temp variable to store the last element
        int temp = array[SIZE - 1];
    
        // Right to left shift
        for (int j = SIZE - 1 ; j > 0 ; j--)
            {
                array[j] = array[j - 1];
            }
    
        // Restore temp to first position
        array[0] = temp;
    }
    // Printing array after rotation
    printf("\n\nArray after rotation :\n");
    for(int z = 0; z < SIZE; z++)
    {
        printf("%d\t", array[z]);
    }
    
    return 0;
}