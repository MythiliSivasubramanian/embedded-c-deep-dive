#include <stdio.h>

int main()
{
    int age;
    float price;
    char grade;
    char name[20];

    printf("Enter age: ");
    scanf("%d", &age);
    // %d skips leading whitespace automatically

    printf("Enter price: ");
    scanf("%f", &price);
    // %f skips leading whitespace automatically

    printf("Enter grade: ");
    scanf(" %c", &grade);   // space skips leftover whitespace
    // without space %c reads the next availble character including the whitespace.

    printf("Enter name: ");
    scanf("%19s", name);
    // %s skips leading whitespace and reads until first whitespace

    printf("\n--- Output ---\n");
    printf("Age   : %d\n", age);
    printf("Price : %.2f\n", price);
    printf("Grade : %c\n", grade);
    printf("Name  : %s\n", name);

    return 0;
}