/*
 * 	Lab 6, Problem 7
 *
 *	Programmer: Jacob Snarr   Date Completed: November 2nd, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	Approximates square root using next guess/last guess formula
*/

#include <stdio.h>
#include <math.h>

#define INITIAL_GUESS 1.0
#define THRESHOLD 0.005

void approximate_square_root(double num, double *ng);

int main() {
  double n = 4;
  double next_guess = INITIAL_GUESS;

  printf("Enter a number: ");
  scanf("%lf", &n);

  approximate_square_root(n, &next_guess);
  printf("The square root of %0.2lf is %0.2lf", n, next_guess);
}

void approximate_square_root(double num, double *ng) {
  double last_guess = INITIAL_GUESS;

  while (1) {
    *ng = 0.5 * (last_guess + num/last_guess); // Set next guess
    if (fabs(*ng - last_guess) < THRESHOLD) { // Break if difference < 0.005
      return;
    }
    last_guess = *ng; // Save last guess
  }
}