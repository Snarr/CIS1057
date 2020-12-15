/*
 * 	Lab 5, Problem 1
 *
 *	Programmer: Jacob Snarr		Date Completed: October 12th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Determine if input integer is divisible by 9
*/

/*  Outputs: 

    Enter a number here> 154368
    8 6 3 4 5 1 ; Sum = 27
    Divisble by 9

    Enter a number here> 621594
    4 9 5 1 2 6
    Divisble by 9

    Enter a number here> 123456
    6 5 4 3 2 1 ; Sum = 21
    Not divisble by 9

*/

#include <stdio.h>

int main() {
	int num;
    int sum = 0;

    printf("Enter a number here> ");
    scanf("%d", &num);

    while (num >= 1) { // Run loop until last digit is divided by 10
        int digit = num % 10; // Find right-most digit using modulo
        printf("%d ", digit);
        sum += digit; // Add digit to sum of digits
        num *= 0.1; // Set input number to itself divided by 10.
    }

    printf("; Sum = %d", sum);

    // Use ternary operator to print based on output of boolean expression
    // We haven't learned this yet but I've used it in other languages and its fun :)
    (sum % 9 == 0) ? printf("\nDivisble by 9") :  printf("\nNot divisble by 9");

	return 0;
}