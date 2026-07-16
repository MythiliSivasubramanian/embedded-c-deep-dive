#include <stdio.h>

struct employee
{
    char *name;
    int emp_id;
    int salary;
};

int main()
{
    struct employee emp = {"Siva", 101, 35000};

    printf("\nName is %s\n", emp.name);
    printf("\nemp_id is %d\n", emp.emp_id);
    printf("\nSalary is %d\n", emp.salary);

    return 0;
}
