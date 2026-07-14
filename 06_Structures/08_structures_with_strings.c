#include <stdio.h>

struct car
{
    char brand[20];
    int year;
};

int main()
{
    struct car c1 = {"Toyota", 2020};

    printf("\nBrand is %s\n", c1.brand);
    printf("\nYear is %d\n", c1.year);

    return 0;
}
