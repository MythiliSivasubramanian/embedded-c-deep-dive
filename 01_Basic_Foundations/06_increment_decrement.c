/*
Increment and Decrement operators :
    pre increment and decrement
    post increment and decrement
    
Key Takeaway:
    Multiple updates of the same variable in a single expression 
    (e.g., a++ + ++a) lead to undefined behavior.
    
    */

#include <stdio.h>

int main()
{
    // variable assignment
    int a = 5;
    printf("\nOriginal value of a : %d\n", a); // 5
    
    // Pre and post increment
    printf("\nIncrement\n");
    printf("\tPost Increment  a++  : %d\n", a++);  //  prints 5, then a becomes 6
    printf("\tNew value of a : %d\n\n", a); // 6
    printf("\tPre Increment ++a  : %d\n", ++a);  // 7
    printf("\tNew value of a : %d\n\n", a); // 7
    
    // Pre and post decrement
    printf("\nDecrement\n");
    printf("\tPost decrement  a--  : %d\n", a--);  // prints 7,  then a becomes 6
    printf("\tNew value of a : %d\n\n", a); // 6
    printf("\tPre decrement --a  : %d\n", --a);  // 5
    printf("\tNew value of a : %d\n\n", a); // 5
    
    printf("\n\nKey Takeaways : Multiple updates of the same variable in a single expression (e.g., a++ + ++a) lead to undefined behavior.");
    
    return 0;
}