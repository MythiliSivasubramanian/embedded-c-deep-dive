/*
Different ways of accessing array elementS:

Given a predefined array int data[5] = {10,20,30,40,50};
    1. Traversal using indicies.
    2. Traversal using pointers + increment operators only.
    3. Traversal using address arithmetic 
    
MY NOTES (IMPORTANT DIFFERENCES):

1. Traversal using indicies : data[i]
   - Easiest and most readable
   - Used in normal programming and algorithms
   - Compiler internally converts it to pointer form

2. Traversal using pointers + increment operators only. *ptr with ptr++
   - Real pointer movement through memory
   - Used in embedded systems (buffers, drivers)
   - Fast and close to hardware

3. Traversal using address arithmetic  *(data + i)
   - Shows how arrays work internally
   - Useful for understanding pointers 
   - Same as data[i], just different form
   
*/

#include <stdio.h>
#define SIZE 5


int main()
{
    // Array declaration and definition
    int data[SIZE] = {10,20,30,40,50};
    
    printf("\n\nPredefined array (data) is :\t");
    
    // Reading the elements of the array
    for(int element_index = 0; element_index < SIZE; element_index++)
    {
        printf("%d ", data[element_index]);
    }
    
    // Address of 1st element of data assigned to ptr
    int *ptr = data;
    
    // Traversing the array using pointers and increment operators
    printf("\n\nTraversing the array using pointers and increment operators :\n");

    for (int element = 0; element < SIZE; element++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }
   
    
    // Accessing the values of array using address arithmetic (without using indicies)
    printf("\n\nAccessing the values of array using adress arithmetic  ane pointers (without using indicies :\n");
    for(int element_no = 0; element_no < SIZE; element_no++)
    {
        printf("%d\n", *(data + element_no));
    }
    
    
    return 0;
}