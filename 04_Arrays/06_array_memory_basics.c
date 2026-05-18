/*

Array Memory basics:
1. Array a[5] elements can be printed using 
    a. Basic Indexing a[0],a[1],..
    b. Pointer arithmetic : a[1] == *(a + 1)
    
2. Array and its address:
    a. &a[0] == a (both prints the same address)
       Both &a[0] and a points to the address of the 1st element in array
       &a points to the address of entire array
       
       &a[0], a : type int *
       &a : type int (*) a[5]
       
    b. Pointer arithmetic expressions:
       a + 1 : moves to address of 1st element of a + ( 1 * 4(if type int)
       &a + 1 : moves one entire array ahead. size = 5 × sizeof(int)
       
*/

#include <stdio.h>
int main()
{
    // Array declaration and initialization
    int a[5] = {1,2,3,4,5};
    
    // Printing elements of array using Indexing
    printf("\n\nPrinting the elements of array : \n");
    for(int i = 0; i <= 4; i++)
    {
        printf("Index a[%d] = %d\n", i, a[i]); // a[i] == *(a + i)
    }
    
    // Printing address of each element of array
    printf("\n\nPrinting address of each element of array\n");
    for (int j = 0; j <= 4; j++)
    {
        printf("Address of index a[%d] with value %d is %p\n", j, a[j], &a[j]);
    }
    
    // Printing Addresses 
    printf("\nAddress of element at index 0 (&a[0]) : %p\n", &a[0]);
    printf("\n\t(a) : %p\n", a);
    printf("\nAddress of element at index 1 (a + 1) : %p\n", a + 1);
    printf("\n\t(&a[1]) : %p\n", &a[1]);
    printf("\nAddress of entire array &a : %p\n", &a);
    printf("\nEntire array  + 1 is &a + 1 : %p\n", &a + 1);

    // Printing elements of array using Pointer arithmetic expressions
    printf("\n\nPrinting elements of array using Pointer arithmetic expressions\n");
    for (int z = 0; z < 5; z++)
    {
        printf("Index %d = %d\n", z, *(a + z)); // *(a + z) == a[z]
        // a + 1 moves by size of int
        // *(a + z) reads value at address
    }
    
    return 0;
    
}