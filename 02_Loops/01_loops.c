/*
Task 1: Print 1 to 10

Task 2: Print even numbers from 1 to 20

Task 3: Sum of first N numbers
N = 5 → 1+2+3+4+5 = 15

Task 4 : Reverse counting from 10 to 1

Task 5: Print numbers from 1 to 50
But:
multiples of 3 → print "Fizz"
multiples of 5 → print "Buzz"
both → "FizzBuzz"


*/


#include <stdio.h>

int main()

{
    
    // Task 1: Print 1 to 10
    printf("\n\nTask 1: Print 1 to 10 : \n\n");
    
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    
    // Task 2: Print even numbers from 1 to 20
    printf("\n\nTask 2: Print even numbers from 1 to 20 :\n\n");

    for(int num = 2; num <= 20; num += 2)
    {
        printf("%d\n",num);
    }
    
    // Task 3: Sum of first N numbers
    printf("\n\nTask 3: Sum of first N numbers : \n\n\tMethod 1 : ");
    
    // predefined variabe n 
    int n = 5;
    int sum = 0;
    
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    
    printf("Sum of first %d Numbers is : %d\n", n, sum);
    printf("\nMethod 1 cons : Loops costs more CPU cycles\n");
    
    printf("\n\tMethod 2 : using formula : \n");
    printf("Sum of 1st n numbers = n * (n + 1) / 2");
    
    int sum_n = n * (n + 1) / 2;
    printf("\nSum of first %d Numbers is : %d\n", n, sum_n);
    
    // Task 4 : Reverse counting from 10 to 1
    printf("\n\nTask 4 : Reverse counting from 10 to 1 :\n\n");
    
    for (int j = 10; j >= 1; j--)
    {
        printf("%d\n", j);
    }
    
    
 //Task 5: Print numbers from 1 to 50
 /*
 But:
    multiples of 3 → print "Fizz"
    multiples of 5 → print "Buzz"
    both → "FizzBuzz"
    
*/
printf("\nTask 5 : \nPrint numbers from 1 to 50 : \n\tmultiples of 3 print Fizz\n\tmultiples of 5 print Buzz\n\tboth : FizzBuzz\n\n");
for (int numbers = 1; numbers <= 50; numbers++)
{
    if (numbers % 3 == 0 && numbers % 5 == 0)
        printf("FizzBuzz");
    else if (numbers % 3 == 0)
        printf("Fizz\n");
    else if (numbers % 5 == 0)
        printf("Buzz\n");
    else 
        printf("%d\n", numbers);
}

return 0;

}