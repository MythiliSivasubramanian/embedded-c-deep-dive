#include <stdio.h>

struct product
{
    char *name;
    int price;
    int quantity;
};

int main()
{
    struct product p1 = {"Pen", 20, 5};

    printf("\nName is %s\n", p1.name);
    printf("\nPrice is %d\n", p1.price);
    printf("\nQuantity is %d\n", p1.quantity);

    return 0;
}
