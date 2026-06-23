#include <stdio.h>
int main()
{
    int array[3] = {1,2,3};
    
    for(int i = 0; i < 3; i++)
    {
        printf("\nIndex : %d  Value : %d  Memory : %p\n", i, array[i], &array[i]);
    }
    
    
    printf("\nMemory is %p\n\n", array);
    printf("\nMemory is %p\n\n", &array);
    return 0;
}