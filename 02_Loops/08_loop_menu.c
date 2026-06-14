/*
    Loop Menu Practice

    Topics Covered:
    1. Menu-driven loop
    2. for loop
    3. while loop
    4. input validation
*/

#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\nLoop Menu Example\n");
        printf("1. Print even numbers from 2 to 10\n");
        printf("2. Print odd numbers from 1 to 9\n");
        printf("3. Calculate sum of first n numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEven numbers from 2 to 10:\n");
                for (int i = 2; i <= 10; i += 2)
                {
                    printf("%d ", i);
                }
                printf("\n");
                break;

            case 2:
                printf("\nOdd numbers from 1 to 9:\n");
                {
                    int i = 1;
                    while (i <= 9)
                    {
                        printf("%d ", i);
                        i += 2;
                    }
                }
                printf("\n");
                break;

            case 3:
                printf("\nEnter n: ");
                int n;
                scanf("%d", &n);
                {
                    int sum = 0;
                    for (int i = 1; i <= n; i++)
                    {
                        sum += i;
                    }
                    printf("Sum of first %d numbers is %d\n", n, sum);
                }
                break;

            case 4:
                printf("\nExiting the loop menu.\n");
                break;

            default:
                printf("\nInvalid selection. Please choose 1-4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
