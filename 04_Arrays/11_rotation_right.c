/*
Rotating right by one position:
Predefined Array : 
int array = {1,2,3,4,5};
Expected Output :
int array = {5,1,2,3,4};
*/


#include <stdio.h>
#define SIZE 5
int main()

{
    // Array declaration and initialization
    int array[SIZE] = {1,2,3,4,5};
    
    
    // Printing elements of array
    printf("\n\nPrinting elements of Original array : \n");
        
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
    printf("\n\nPrinting elements of array after Rotating right by one position : \n");
    for(int z = 0; z < SIZE; z++)
    {
        printf("%d\t", array[z]);
    }
    
    return 0;
}