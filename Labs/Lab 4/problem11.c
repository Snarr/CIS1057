/*
 * 	Lab 4, Problem 11
 *
 *	Programmer: Jacob Snarr		Date Completed: October 5th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Identifies substance within 5% of boiling point for known substances
*/

#include <stdio.h>

int within_x_percent(double ref, double data, double x);

int main() {
	double observed_boiling_point;

	printf("What is the observed boiling point> ");
	scanf("%lf", &observed_boiling_point);

	if (within_x_percent(100, observed_boiling_point, 5)) {
		printf("Water\n");
	} else if (within_x_percent(357, observed_boiling_point, 5)) {
		printf("Mercury\n");
	} else if (within_x_percent(1187, observed_boiling_point, 5)) {
		printf("Copper\n");
	} else if (within_x_percent(2193, observed_boiling_point, 5)) {
		printf("Silver\n");
	} else if (within_x_percent(2660, observed_boiling_point, 5)) {
		printf("Gold\n");
	} else {
		printf("Can't identify substance.\n");
	}

	return 0;
}

int within_x_percent(double ref, double data, double x) {
	x = x/100;
	double lower = ref - x * ref;
	double upper = ref + x * ref;
	if (data >= lower && data <= upper) {
		return 1;
	}
	return 0;
}