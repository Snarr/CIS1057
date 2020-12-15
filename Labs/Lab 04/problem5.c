/*
 * 	Lab 4, Problem 5
 *
 *	Programmer: Jacob Snarr		Date Completed: October 5th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Characterizes earthquake damage based on Richter scale number input
*/

#include <stdio.h>

int main() {
	double n = 0.0;

	if (n < 5.0) {
		printf("Little or no damage\n");
	} else if (n >= 5.0 && n < 5.5) {
		printf("Some damage\n");
	} else if (n >= 5.5 && n < 6.5) {
		printf("Serious damage: walls may crack or fall\n");
	} else if (n >= 6.5 && n < 7.5) {
		printf("Disaster: houses and buildings may collapse\n");
	} else {
		printf("Catastrophe: most buildings destroyed\n");
	}

	return 0;
}