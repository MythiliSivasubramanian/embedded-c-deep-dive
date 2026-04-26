/*
Take the below info as input:
    name : string
    initial : char
    age : int
    height : float

Print all values using correct format specifiers
*/

#include <stdio.h>  
// standard input and putput Library

int main () 
// program execution starts from main fucntion

{
    // variables declaration
    char name[20]; // accepts 20 characters, starts from 0 
    
    char initial;  // single character
    int age;
    float height;
    
    printf("\nEnter the following information : \n");
    
    printf("\nEnter Name : ");
    scanf("%19s", name);  // limits input to 19 characters (+ \0 automatically)
    // character array of a string, hence & is not used. 
    
    printf("\nEnter Initial : ");
    scanf(" %c", &initial); // buffer + whitespace handling : %c reads including whitespace characters 
    // if not skipped through space before %c
    scanf("%d", &age);
    
    printf("\nEnter Height : ");
    scanf("%f", &height);
    
    // printing the information
    printf("\nPrinting the information : \n");
    printf("\nName : %s", name);
    printf("\nInitial : %c", initial);
    printf("\nAge : %d", age);
    printf("\nHeight : %.2f\n\n", height);
    
    return 0; // on successfull execution 
    
    
}