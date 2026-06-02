/*
Given:
int data[7] = {25, 10, 45, 5, 60, 30, 15};

Write a program that:
    1. Prints the array
    2. Find  and print the maximum value
    3. Find and print the minimum value
    4. Print range (maximum value - minimum value)
    
*/

#include <stdio.h>

// Function declaration or function prototype
void print_array(int data[], int size);
int find_max(int data[], int size);
int find_min(int data[], int size);

int main()
{
    // Array declaration and initialization
    int data[7] = {25, 10, 45, 5, 60, 30, 15};
    
    // Function call : print_array()
    printf("\n\nPrinting elements of array : ");
    print_array(data, 7);
    
    // Function call : find_max()
    printf("\n\nFinding the element with maximum value :\n");
    int maximum = find_max(data, 7);
    printf("Maximum value : %d", maximum);
    
    // Function call: find_min()
    printf("\n\nFinding the element with minimum value :\n");
    int minimum = find_min(data, 7);
    printf("Minimum value : %d\n\n", minimum);
    
    // printing range (Max value - min value)
    printf("Range (Max value - min value) is : %d\n\n", (maximum - minimum));
    
    return 0;
}

// Function definition
// Task 1. Printing elements of array
void print_array(int data[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}

// Task 2. Finding maximum value
int find_max(int data[], int size)
{
    int max = data[0];
    for(int element = 1; element < size; element++)
    {
        if (data[element] > max)
        {
            max = data[element];
        }
    }
    return max;
    
}

// Task 3. Finding minimum value
int find_min(int data[], int size)
{
    int min = data[0];
    for(int element = 1; element < size; element++)
    {
        if(data[element] < min)
        {
            min = data[element];
        }
    }
    return min;
}
