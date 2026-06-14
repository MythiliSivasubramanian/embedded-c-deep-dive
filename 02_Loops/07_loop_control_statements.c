/*
    Loop Control Practice

    Topics Covered:
    1. while loop
    2. do-while loop
    3. break and continue
    4. input validation with loops
*/

#include <stdio.h>

int main()
{
    int count = 1;

    // Task 1: while loop from 1 to 5
    printf("\nTask 1: while loop from 1 to 5\n\n");

    while (count <= 5)
    {
        printf("%d\n", count);
        count++;
    }

    // Task 2: do-while loop until user enters 0
    printf("\nTask 2: do-while loop until user enters 0\n\n");

    int value;
    do
    {
        printf("Enter a number (0 to stop): ");
        scanf("%d", &value);
        printf("You entered: %d\n", value);
    } while (value != 0);

    // Task 3: break and continue example
    printf("\nTask 3: break and continue example\n\n");

    for (int i = 1; i <= 10; i++)
    {
        if (i == 7)
        {
            printf("Reached %d, breaking out of the loop\n", i);
            break;
        }

        if (i % 2 == 0)
        {
            continue;
        }

        printf("Odd number: %d\n", i);
    }

    return 0;
}
