#include <stdio.h>

struct laptop
{
    char *brand;
    int price;
};

int main()
{
    struct laptop l1 = {"Dell", 50000};
    struct laptop *ptr = &l1;

    printf("\nBrand is %s\n", ptr->brand);
    printf("\nPrice is %d\n", ptr->price);

    return 0;
}
