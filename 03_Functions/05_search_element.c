/*
Given an array
int data[7] = {25, 10, 45, 5, 60, 30, 15};

Get and input number from user and find if the element is in array.
If element is found, print its index
If element not found, print -1
*/

#include <stdio.h>

// Function prototype or function declaration
void print_array(int data[], int size);
int search_element(int data[], int size, int search_value);



int main()
{
    // Array declaration and initialization
    int data[7] = {25, 10, 45, 5, 60, 30, 15};
    
    // Function call: print_array()
    printf("\n\nPrinting elements of array :\n");
    print_array(data, 7);
    
    // Get input (search element) from user
    printf("\n\nEnter the number to search in array : ");
    int search_value;
    scanf("%d", &search_value);
    
    // Function call : search_element()
    int element_index = search_element(data, 7, search_value);

    
    // print index if search value is found else print -1
    if(element_index != -1)
    {
        printf("%d is found in array. Its index is %d\n", search_value, element_index);
    }
    else
    {
        printf("\n\n%d is not found. Result is : -1\n\n", search_value);
    }
    
    
    
    return 0;
}

// Function definition
// Task 1 . Printing elements of array
void print_array(int data[], int size)
{
    for(int element = 0; element < size; element++)
    {
        printf("%d ", data[element]);
    }
}

// Task 2. Search element 
int search_element(int data[], int size, int search_value)
{
    for(int index = 0; index < size; index++)
    {
        if(data[index] == search_value)
        {
            return index;
        }
    }
   
    return -1;

}