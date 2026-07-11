#include <stdio.h>

struct book
{
    char *title;
    int pages;
};

int main()
{
    struct book b1 = {"C Basics", 250};
    struct book b2 = b1;

    printf("\nTitle is %s\n", b2.title);
    printf("\nPages is %d\n", b2.pages);

    return 0;
}
