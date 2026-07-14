#include <stdio.h>

struct student
{
    char *name;
    int roll_no;
};

int main()
{
    struct student stud[3] = {{"Asha", 1}, {"Ravi", 2}, {"Nisha", 3}};

    printf("\nName is %s\n", stud[0].name);
    printf("\nRoll no is %d\n", stud[0].roll_no);

    printf("\nName is %s\n", stud[1].name);
    printf("\nRoll no is %d\n", stud[1].roll_no);

    return 0;
}
