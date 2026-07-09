#include <stdio.h>

struct details
{
    char *name;
    int emp_id;
    int salary;
    char designation[7];
   
};

int main()
{
    struct details emp = {.emp_id = 12345, .salary = 34500, .name = "Anna", .designation = "Senior"};

    struct details manager =  emp;
    
    // Printing the details 
    printf("\nName is %s, Address %p\n", emp.name, &emp.name);
    printf("\nemp_ id is %d, Address %p\n", emp.emp_id, &emp.emp_id);
    printf("\nSalary is %d, Address %p\n", emp.salary, &emp.salary);
    printf("\nDesignation is %s, Address %p\n", emp.designation, &emp.designation);
    
    
    
    
    printf("\nName is %s, Address %p\n", manager.name, &manager.name);
    printf("\nemp_ id is %d, Address %p\n", manager.emp_id, &manager.emp_id);
    printf("\nSalary is %d, Address %p\n", manager.salary, &manager.salary);
    printf("\nDesignation is %s, Address %p\n", manager.designation, &manager.designation);
    
    return 0;
    
}