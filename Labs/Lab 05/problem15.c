/*
 * 	Lab 5, Problem 15
 *
 *	Programmer: Jacob Snarr		Date Completed: October 12th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Calculate PI using given series equation
*/

#include <stdio.h>

int main() {
    double pi = 0;

    for (int i = 1; i <= 99; i += 2) { // For Loop for odd numbers in range 1-99 inclusive
        double fraction = 1.0/i; // Create fraction

        if (i % 4 != 1) { // Make every other fraction negative
            fraction *= -1.0;
        }

        pi += fraction; // Add fraction to pi
    }

    pi = 4.0 * pi; // Multiply by 4 according to equation

    printf("%lf", pi);

	return 0;
}

