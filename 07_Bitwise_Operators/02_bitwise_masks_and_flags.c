#include <stdio.h>

int main()
{
    unsigned int flags = 0;
    unsigned int LED = 1 << 0;
    unsigned int MOTOR = 1 << 1;
    unsigned int SENSOR = 1 << 2;

    flags |= LED;
    flags |= SENSOR;

    printf("Flags = %u\n", flags);

    if (flags & LED)
    {
        printf("LED is ON\n");
    }

    if (flags & MOTOR)
    {
        printf("MOTOR is ON\n");
    }
    else
    {
        printf("MOTOR is OFF\n");
    }

    flags &= ~SENSOR;
    printf("After clearing SENSOR: %u\n", flags);

    return 0;
}
