/*
 * 	Lab 5, Problem 7
 *
 *	Programmer: Jacob Snarr		Date Completed: October 12th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Determine if given temperature meets standards for hot,
 *  pleasant, or cold. Take average of given temperatures.
*/

/*  Output:

    Please enter a temperature> 55
    55 is a cold temperature.
    Please enter a temperature> 62
    62 is a pleasant temperature.
    Please enter a temperature> 68
    68 is a pleasant temperature.
    Please enter a temperature> 74
    74 is a pleasant temperature.
    Please enter a temperature> 59
    59 is a cold temperature.
    Please enter a temperature> 45
    45 is a cold temperature.
    Please enter a temperature> 41
    41 is a cold temperature.
    Please enter a temperature> 58
    58 is a cold temperature.
    Please enter a temperature> 60
    60 is a pleasant temperature.
    Please enter a temperature> 67
    67 is a pleasant temperature.
    Please enter a temperature> 65
    65 is a pleasant temperature.
    Please enter a temperature> 78
    78 is a pleasant temperature.
    Please enter a temperature> 82
    82 is a pleasant temperature.
    Please enter a temperature> 88
    88 is a high temperature.
    Please enter a temperature> 91
    91 is a high temperature.
    Please enter a temperature> 92
    92 is a high temperature.
    Please enter a temperature> 90
    90 is a high temperature.
    Please enter a temperature> 93
    93 is a high temperature.
    Please enter a temperature> 87
    87 is a high temperature.
    Please enter a temperature> 80
    80 is a pleasant temperature.
    Please enter a temperature> 78
    78 is a pleasant temperature.
    Please enter a temperature> 79
    79 is a pleasant temperature.
    Please enter a temperature> 72
    72 is a pleasant temperature.
    Please enter a temperature> 68
    68 is a pleasant temperature.
    Please enter a temperature> 61
    61 is a pleasant temperature.
    Please enter a temperature> 59
    59 is a cold temperature.
    Please enter a temperature> stop

    Hot Days: 6
    Pleasant Days: 14
    Cold Days: 6
    Average: 71.230769
*/

#include <stdio.h>

int main() {
    double hot, pleasant, cold = 0.0;
    double sum = 0;
    double avg;
    double x;

    while (1) {
        printf("Please enter a temperature> ");

        if (!scanf("%lf", &x)) { // Break loop if bad value entered; Used as sentinel value.
            break;
        }

        sum += x; // Add to sum for future average calculation

        // Determine category, print, and increment.
        if (x >= 85) {
            printf("%0.0lf is a high temperature.\n", x);
            hot++;
        } else if (x >= 60 && x <= 84) {
            printf("%0.0lf is a pleasant temperature.\n", x);
            pleasant++;
        } else {
            printf("%0.0lf is a cold temperature.\n", x);
            cold++;
        }
    }

    avg = sum/(hot+pleasant+cold); // Calculate average
	
    printf("\nHot Days: %0.0lf", hot);
    printf("\nPleasant Days: %0.0lf", pleasant);
    printf("\nCold Days: %0.0lf", cold);
    printf("\nAverage: %lf", avg);

	return 0;
}