/*
 * 	Lab 2, Problem 11
 *
 *	Programmer: Jacob Snarr		Date Completed: September 16th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Calculates and displays the values for a Pythagorean triple
 * 	from two positive integers "m" and "n" where "m > n".
*/

#include <stdio.h>

int main() {

	int m, n, side1, side2, hypotenuse = 0;

	printf("PYTHAGOREAN TRIPLE GENERATOR\n");

	// User input of M and N
	printf("Value of M: ");
	scanf("%d",&m);
	printf("Value of N: ");
	scanf("%d", &n);

	// Calculations for triple values
	side1 = m*m - n*n;
	side2 = 2*m*n;
	hypotenuse = m*m + n*n;


	// Printing results
	printf("From the values M = %d and N = %d,\n", m, n);
	printf("the following Pythagorean Triple is generated:\n");

	printf("-- Side 1:     %d\n", side1);
	printf("-- Side 2:     %d\n", side2);
	printf("-- Hypotenuse: %d\n", hypotenuse);

	return 0;
}