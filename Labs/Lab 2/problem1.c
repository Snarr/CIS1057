/*
 * 	Lab 2, Problem 1
 *
 *	Programmer: Jacob Snarr		Date Completed: September 16th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Calculates the mileage reimbursement based on a set rate with
 * 	user input for the start and end mileage counts.
*/

#include <stdio.h>

int main() {

	double start, end = 0;
	double difference = 0;
	double rate = 0.35;

	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");

	printf("Enter beginning odometer reading=> ");
	scanf("%lf", &start);
	printf("Enter ending odometer reading=> ");
	scanf("%lf", &end);

	difference = end-start;

	printf("You traveled %.1lf miles. At $0.35 per mile,\nyour reimbursement is $%.2lf\n", difference, rate*difference);

	return 0;
}