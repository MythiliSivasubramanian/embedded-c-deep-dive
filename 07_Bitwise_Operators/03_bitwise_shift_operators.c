#include <stdio.h>

int main()
{
    unsigned int value = 8; // 1000

    printf("Original value = %u\n", value);
    printf("value << 1 = %u\n", value << 1);
    printf("value << 2 = %u\n", value << 2);
    printf("value >> 1 = %u\n", value >> 1);

    return 0;
}
