/*
 * 	Lab 4, Problem 7
 *
 *	Programmer: Jacob Snarr		Date Completed: October 5th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Prints the number day of the year based on Date Input
*/

#include <stdio.h>

#define DIVISIBLE(year, num) ((year % num) == 0)

int leap(int year);

int main() {
	int numDay = 0;
	int month, day, year = 1;
	int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	printf("Format: '1 2 2001' is January 2nd, 2001\n");
	printf("Enter the date> ");
	scanf("%d %d %d", &month, &day, &year);

	if (leap(year)) {
		monthLength[1] = 29;
	}

	for (int i = 0; i < month-1; i++) {
		numDay += monthLength[i];
	}
	numDay += day;

	printf("%d\n", numDay);

	return 0;
}

int leap(int year) {
	if (DIVISIBLE(year, 4)) {
		if (DIVISIBLE(year, 100)) {
			if (DIVISIBLE(year, 400)) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}