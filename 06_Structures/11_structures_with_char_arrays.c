#include <stdio.h>

struct person
{
    char name[20];
    int age;
};

int main()
{
    struct person p1 = {"Kavi", 22};

    printf("\nName is %s\n", p1.name);
    printf("\nAge is %d\n", p1.age);

    return 0;
}
