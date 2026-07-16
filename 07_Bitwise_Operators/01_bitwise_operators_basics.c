#include <stdio.h>

int main()
{
    int a = 10; // 1010
    int b = 6;  // 0110

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~a = %d\n", ~a);

    return 0;
}
