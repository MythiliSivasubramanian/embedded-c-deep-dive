#include <stdio.h>

struct student
{
    char *name;
    int roll_no;
    int marks[3];
};

int main()
{
    struct student stud = {"Meso", 10, {80, 85, 90}};

    printf("\nName is %s\n", stud.name);
    printf("\nRoll no is %d\n", stud.roll_no);
    printf("\nMarks are %d, %d, %d\n", stud.marks[0], stud.marks[1], stud.marks[2]);

    return 0;
}
