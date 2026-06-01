/*

Task:
Given an predefined array(data[5], find 
    1. sum of all elements
    2. Average of elements
    3. multiply each element by 2 (modify original array in place)
    
    
This program explains
Arrays
Functions
Passing arrays to functions
Modifying arrays
Calculating sum + average

Concepts Covered
- Functions
- Pointers (implicit in arrays)
- Memory behavior of arrays

*/

#include <stdio.h>
#define SIZE 5

// Funtion prototype or Function declaration
void print_array(int data[], int size);
int array_sum(int data[], int size);
void multiply_elements(int data[], int size);



int main()
{
    int size = SIZE;
    // Array declaration and initialization
    int data[SIZE] = {10, 20, 30, 40, 50};
    
    // print_array function call
    printf("\nPrinting the elements of array :\n");
    print_array(data, size);
    
    // array_sum function call
    int total = array_sum(data, size);
    printf("\n\nSum of elements is : %d\n", total);
    
    // Task 2. Average of elements. Average = Sum / total no of elements of array
    int average = total / size;
    printf("\nAverage of elements is : %d\n", average);
    
    // multiply_elements function call
    printf("\nMultiplying elements of array by 2 :\n");
    multiply_elements(data, size);
      
    // print_array function call
    print_array(data, size);
    
    return 0;
}           

// Function definition
// Task 1 : Sum of all elements of array
int array_sum(int data[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    
    return sum;  
}

// Function definition
// Task 3. Multiply each elements of original array by 2
void multiply_elements(int data[], int size)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] * 2;
    }
}

void print_array(int data[], int size)
{
    for(int j = 0; j < size; j++)
    {
        printf("%d ", data[j]);
    }
}