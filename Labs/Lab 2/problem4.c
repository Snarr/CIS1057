/*
 * 	Lab 2, Problem 4
 *
 *	Programmer: Jacob Snarr		Date Completed: September 16th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Converts Fahrenheit to Celsius
*/

#include <stdio.h>

int main() {

	int fahrenheit; /* temperature in degrees fahrenheit */
	double celsius; /* temperature in degrees celcius */

	printf("FAHRENHEIT TO CELSIUS CONVERSION CALCULATOR\n");
	printf("Enter a temeprature in Fahrenheit => ");
	scanf("%d", &fahrenheit);

	celsius = (5.0/9.0) * (fahrenheit - 32); /* conversion equation */

	printf("%d in Fahrenheit is %0.2lf in Celsius\n", fahrenheit, celsius);

	return 0;
}