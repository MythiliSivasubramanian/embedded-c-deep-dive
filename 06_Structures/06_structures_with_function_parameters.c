#include <stdio.h>

struct student
{
    char *name;
    int roll_no;
};

void print_student(struct student s)
{
    printf("\nName is %s\n", s.name);
    printf("\nRoll no is %d\n", s.roll_no);
}

int main()
{
    struct student stud = {"Meera", 7};

    print_student(stud);

    return 0;
}
