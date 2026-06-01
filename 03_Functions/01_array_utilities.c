/*
C program that performs the following using an array:
int a[6] = {10, 20, 30, 40, 50, 60};
    1. Print all elements
    2. Find sum of all elements
    3. Find average
    4. Find maximum element
    5. Find minimum element

    
*/

#include <stdio.h>
#define SIZE 6

void printArray(int array[], int size);
int arraySum(int array[], int size);
int arrayLargest(int array[], int size);

int main()
{
    int array[SIZE] = {10, 20, 30, 40, 50, 60};
    int size = SIZE;
    
    // Task 1. Printing all elements using loop
    printf("\n\nTask 1. Printing all elements using loop :\n");
    printArray(array, size);
    
   
    
    // Task 2. Finding sum of all elements using loop
    printf("\n\nTask 2. Finding sum of all elements using loop :\n");
    int total = arraySum(array, size);
    printf("Sum is : %d", total);
    
    // Task 3. Finding average
    printf("\n\nTask 3. Finding average of the array : ");
    printf("\n\tSum is : %d, Size is : %d\n", total, SIZE);
    float average = (float)total / SIZE;
    printf("Average is : %.2f\n", average);
    
    
    // Task 4. Finding maximum element
    printf("\nTask 4. Finding maximum element in array using loop :");
    int large = int 
    printf("\nLargest element is : %d", largest);
    
    // Task 5. Finding smallest element using loop
    printf("\n\nTask 5. Finding smallest element in array using loop :");

    int smallest = array[0];
    for(int index = 0; index < SIZE; index++)
    {
        if (array[index] < smallest)
        {
            smallest = array[index];
        }
    }
    printf("\nSmallest element is : %d\n", smallest);
    
    return 0;
}

// Task 1
// Funtion to printing all items 
void printArray(int array[], int size)
{
    for(int index = 0; index < size; index++)
    {
        printf("Index %d -- %d\n", index, array[index]);
    }

}

// Task 2
// Funtion to printing all items 
int arraySum(int array[], int size)
{
    int sum = 0;
    for(int index = 0; index < SIZE; index++)
        {
            sum += array[index];
        }
    return sum;
}