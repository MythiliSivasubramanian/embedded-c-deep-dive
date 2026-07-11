#include <stdio.h>

struct address
{
    char city[20];
    int pin_code;
};

struct employee
{
    char *name;
    int emp_id;
    struct address add;
};

int main()
{
    struct employee emp = {"Johnny", 12345, {"Melbourne", 900001}};

    printf("\nName is %s\n", emp.name);
    printf("\nemp_id is %d\n", emp.emp_id);
    printf("\nCity is %s\n", emp.add.city);
    printf("\nPin code is %d\n", emp.add.pin_code);

    return 0;
}
