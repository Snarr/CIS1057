/*
 * 	Lab 6, Problem 1
 *
 *	Programmer: Jacob Snarr   Date Completed: November 2nd, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	Simulates a teller machine by determining how many of each
 *  kind of bill to dispense to reach a user requested amount.
*/
#include <stdio.h>

void calculateBillCount(int amount, int *count_50s, int *count_20s, int *count_10s);

int main() {
  int amount = -1;
  int count_50s = 0;
  int count_20s = 0;
  int count_10s = 0;

  printf("Automatic Teller Machine\n"); // Title of program

   // Continuously ask user for amount until proper input is given
  while (amount % 10 != 0 || amount < 0) { // Only accept positive values divisible by 10
    printf("***Request any amount that is divisble by 10***\n");
    printf("How much money do you want? ");
    scanf("%d", &amount); // Write the value back to the "amount" variable
  }
  calculateBillCount(amount, &count_50s, &count_20s, &count_10s); // Pass the values into calculateBillCount()
  printf("$50 bills: %d\n", count_50s);
  printf("$20 bills: %d\n", count_20s);
  printf("$10 bills: %d\n", count_10s);
}

void calculateBillCount(int amount, int *count_50s, int *count_20s, int *count_10s) {
  *count_50s = (amount - (amount % 50)) / 50; // Count how many 50s fit into amount
  amount -= *count_50s*50; // Adjust amount
  *count_20s = (amount - (amount % 20)) / 20; // Count how many 20s fit into amount
  amount -= *count_20s*20; // Adjust amount
  *count_10s = (amount - (amount % 10)) / 10; // Count how many 10s fit into amount
  amount -= *count_10s*10; // Adjust amount
}