/*
 * 	Lab 3, Problem 13
 *
 *	Programmer: Jacob Snarr		Date Completed: September 28th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Predicts Gotham's population after 1990
 *  based on equation "P(t) = 52.966 + 2.184t"
*/

#include <stdio.h>
#include <math.h>

double population(int year);

int main() {
	int year = 0;

	printf("* Gotham Population Calculator *\n\n"); // Title for user

	// Input Questions
	printf("Enter a year after 1990> "); // Get user input
	scanf("%d", &year);

	printf("Predicted Gotham City population for %d (in thousands): %0.3lf\n", year, population(year)); // Print solution
}

// Uses linear equation to calculate Gotham's Population in 'year'
double population(int year) {
	int t = year-1990;

	return 52.966 + 2.184*((double) t);
}