#include <stdio.h>

struct details
{
    char *name;
    int emp_id;
    int salary;
    char designation[10];
};

int main()
{
    struct details emp = {.name = "Asha", .emp_id = 101, .salary = 40000, .designation = "Manager"};

    struct details *ptr = &emp;

    printf("\nName is %s, Address %p\n", ptr->name, &ptr->name);
    printf("\nemp_id is %d, Address %p\n", ptr->emp_id, &ptr->emp_id);
    printf("\nSalary is %d, Address %p\n", ptr->salary, &ptr->salary);
    printf("\nDesignation is %s, Address %p\n", ptr->designation, &ptr->designation);

    return 0;
}
