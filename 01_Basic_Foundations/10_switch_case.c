/*
Switch Case:

Task 1: Basic Mode Selector (SWITCH)
Problem:
Predefined variable: int mode = 2;
Requirements:
mode 1 : print "LOW"
mode 2 : print "MEDIUM"
mode 3 : print "HIGH"
anything else : "INVALID"


Task 2: Day of the week 
Predefined variable: int day = 5;
Requirements:
if day 1 then print Monday
if day 2 the print Tuesday
...
if day 7 then print Sunday

Task 3: Even / Odd
Predefined varibale : int num = 7;
Requirements:
Print Even if its even number else 
print Odd

Task 4: Temperature Classification
Predefined variable : int temp = 65
Requirements:
Temp 80 then print critical 
temp 60 : High
temp 40 : normal 
Less than 40: low 

Task 5: Calculator 
char op = '+';
int a = 10, b = 5;
Requirements:
+ : addition
- : subtraction
* : multiplication
/ : division

*/



#include <stdio.h>

int main()
{
    int mode = 2;
    
    // Only one Variable and fixed values. Hence switch is used instead of if, if else if ladder
    switch (mode)
    {
        case 1: 
            printf("\n\nLOW\n");
            break;
            
        case 2:
            printf("\nMEDIUM\n");
            break;
            
        case 3:
            printf("\nHIGH\n");
            break;
        
        default:
            printf("\nINVALID\n");

    }
    
    // Task 2 Day of the week 
    
    int day = 2;
    
    // Only one Variable and many fixed values. Hence switch is used instead of if, if else if ladder
    switch (day)
    {
        case 1:
            printf("\nMonday\n");
            break;
        
        case 2:
            printf("\nTuesday\n");
            break;
        
        case 3:
            printf("\nWednesday\n");
            break;
        
        case 4:
            printf("\nThursday\n");
            break;
        
        case 5:
            printf("\nFriday\n");
            break;
            
        case 6:
            printf("\nSaturday\n");
            break;
            
        case 7:
            printf("\nSunday\n");
            break;
            
        default:
            printf("\n\nInvalid\n\n")
    }
    
    // Task 3 : Even / odd number 
    
    //predefined number 
    int num = 7;
    
    // Logic condition is used to find if its even or odd. Hence if else is used.
    if (num % 2 == 0)
    {
        printf("\n\nEven\n");
    }
    
    else
    {
        printf("\nOdd\n\n");
    }
    
    // Task 4 : Temperature Classification
    
    // predefined variable
    int temp = 65;
    

    // Based on conditions and ranges, hence if else if ladder is used.
    if (temp >= 80)
    {
        printf("\n\nCritical\n");
    }
    
    else if (temp >= 60)
    {
        printf("\nHigh\n");
    }
    else if (temp >= 40)
    {
        printf("\nNormal\n");
    }
    else 
    {
        printf("\nLow\n\n");
    }   
    
    
    // Task 5 : Calculator 
    char op = '+';
    int a = 10, b = 5;
    
    // Variable op with fixed operations (*,+, /, -) Hence switch is used.
    switch (op)
    {
        case '+':
            printf("\nAddition is %d\n", a + b);
            break;
        
        case '-':
            printf("\nSubtraction is %d\n", a - b);
            break;
            
        case '*':
            printf("\nMultiplication is %d\n", a * b);
            break;
        
        case '/':
            case '/':
                if (b != 0)
                    printf("\nDivision is %d\n", a / b);
                else
                    printf("\nError: Division by zero\n");
                break;
            
        default:
            printf("\nInvalid operation\n\n");
        
        
    }

    return 0;
    
}
