/*
ARRAYS AND POINTERS

  The array name represents the address of the first element.
  arr == &arr[0]
This relationship is the reason pointers and arrays aretightly connected in C.
*/


#include <stdio.h>

int main()
{


    int arr[5] = {10, 20, 30, 40, 50};

    /*
    Array Memory Layout (Example)
     
      Address      Value
      1000         10
      1004         20
      1008         30
      1012         40
      1016         50
     */

    printf("ARRAY BASICS\n\n");

    printf("arr        = %p\n", (void *)arr);
    printf("&arr[0]    = %p\n", (void *)&arr[0]);

    /*
      arr and &arr[0] print the same address.
     */

    printf("\n ARRAY INDEXING \n\n");

    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    printf("arr[2] = %d\n", arr[2]);
    printf("arr[3] = %d\n", arr[3]);
    printf("arr[4] = %d\n", arr[4]);

    /*
     Array indexing internally works using pointer arithmetic.
     */

    printf("\nPOINTER EXPRESSIONS \n");

    printf("*(arr + 0) = %d\n", *(arr + 0));
    printf("*(arr + 1) = %d\n", *(arr + 1));
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(arr + 3) = %d\n", *(arr + 3));
    printf("*(arr + 4) = %d\n", *(arr + 4));

    /*
     * These are equivalent:
     
     arr[0] == *(arr + 0)
      arr[1] == *(arr + 1)
      arr[2] == *(arr + 2)
      arr[3] == *(arr + 3)
      arr[4] == *(arr + 4)
     */

    printf("\nPOINTER TO ARRAY \n\n");

    int *p = arr;

    printf("p      = %p\n", (void *)p);
    printf("*p     = %d\n", *p);

    /*
     Since p stores the address of arr[0],
     dereferencing p gives the first element.
     */

    printf("\nPOINTER ARITHMETIC \n\n");

    printf("*(p + 0) = %d\n", *(p + 0));
    printf("*(p + 1) = %d\n", *(p + 1));
    printf("*(p + 2) = %d\n", *(p + 2));
    printf("*(p + 3) = %d\n", *(p + 3));
    printf("*(p + 4) = %d\n", *(p + 4));

    /*
     Pointer arithmetic moves by elements not by bytes.
    
     For an int pointer:
    
     p + 1 -> next integer
     p + 2 -> second integer ahead
     p + 3 -> third integer ahead
     */

    printf("\nMOVING THE POINTER \n\n");

    p = p + 3;

    printf("*p after p = p + 3 : %d\n", *p);

    /*
     p now points to arr[3]
     Value = 40
    */

    p = p - 2;

    printf("*p after p = p - 2 : %d\n", *p);

    /*
     p now points to arr[1]
     Value = 20
     */

    return 0;
}

