/*
 * 	Lab 3, Problem 1
 *
 *	Programmer: Jacob Snarr		Date Completed: September 28th, 2020
 * 	Instructor: Joe Jupin		Class: CIS 1057.001
 * 
 * 	Calculates the monthly payment for a car based
 *  on user input and textbook definition of formula
*/

#include <stdio.h>
#include <math.h>

double calculatePayment(double price, double downPayment, double aInterestRate, double nPayments);

int main() {
	double price, downPayment, aInterestRate, mInterestRate, nPayments = 0;

	printf("* Monthly Car Payment Calculator *\n"); // Title for user
	printf("Currency: US Dollar ($)\n\n"); // Define currency

	// Get purchase price of car in USD ($)
	printf("What is the purchase price of the car? \n");
	printf("Note: Don't include currency symbols like '$' \n>");
	scanf("%lf", &price);

	// Get down payment in USD ($)
	printf("\nWhat was the down payment on the car? \n");
	printf("Note: Don't include currency symbols like '$' \n>");
	scanf("%lf", &downPayment);

	// Get annual interest rate
	printf("\nWhat is the annual interest rate of the car? \n");
	printf("Ex: For a 5%% annual interest rate, type '0.05' \n>");
	scanf("%lf", &aInterestRate);
	mInterestRate = aInterestRate/12.0; // convert annual interest rate to monthly

	// Get number of monthly payments
	printf("\nWhat is the total number of monthly payments you will make on the car? \n");
	printf("Ex: If 36 monthly payments, type '36' \n>");
	scanf("%lf", &nPayments);

	// Print output
	printf("\n\nAmount Borrowed: $%0.2lf\n", price-downPayment);
	printf("Monthly Payment: $%0.2lf\n", calculatePayment(price, downPayment, mInterestRate, nPayments));
}

// Calculate monthly payment for car based on user-input and textbook defined formula
double calculatePayment(double p, double dPayment, double aPR, double nPayments) {
	return ((p-dPayment)*aPR)/(1-pow(1+aPR, -1*nPayments));
}