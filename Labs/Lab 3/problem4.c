/*
 * 	Lab 3, Problem 4
 *
 *	Programmer: Jacob Snarr		Date Completed: September 28th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Approximates n! using Gosper's Formula
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double nFactorial(int intN);

int main() {
	int n = 0;

	printf("* Approximate n! using Gosper's Formula *\n\n"); // Title for user

	// Input Questions
	printf("Enter any integer 'n' to find 'n!' \n"); // Get user input
	scanf("%d", &n);

	printf("%d! equals approximately %0.5lf\n", n, nFactorial(n)); // Print solution
}

// Uses Gosper's Formula to approximate 'n!'
double nFactorial(int intN) {
	double n = (double) intN;
	// My program ran correctly the first time
	// so I did not neeed to debug with intermediate value variables
	return pow(n, n)*exp(-n)*sqrt((2.0*n + 1.0/3.0)*PI);
}