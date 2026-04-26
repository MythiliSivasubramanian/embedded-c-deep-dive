/* 
Program to get multiple inputs at once and 
print those information
*/


#include <stdio.h> 

int main()

{
    // variables declaration
    char name[25];
    int age;
    float price;
    
    
    printf("\nTaking multiple inputs\n");
    printf("\nEnter name, age, price : ");
    
    // getting multiple inputs
    scanf("%24s %d %f", name, &age, &price);
    
    /*
    
    %24s limits input to 24 characters max and ends with '\0' automatically
    
    %s skips leading whitespaces and reads as a single word (token) until space, 
    tab, or newline. If Joe Doe is entered, only Joe is stored in name variable.
    
    %c reads including whitespace
    
    %d skips leading whitespace and reads a valid integer token. 
    Stops when: non-digit appears or input ends
    
    %f reads a valid floating-point number and stops when the format breaks
    
    */
   
    
    // printing the information
    printf("\nName : %s\nAge : %d\nPrice : %.2f", name, age, price);
    
    return 0;
    // upon successfull execution
}

