/*
 * 	Lab 6, Problem 5
 *
 *	Programmer: Jacob Snarr   Date Completed: November 2nd, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 *  Answer a few questions for a list of inputs.	
*/

#include <stdio.h>
#include <math.h>

#define LEN 99

void answerQuestions(int num, int *answer_a, int *answer_b, int *answer_c);
int sumOfDigits(int num);
int isPrimeNumber(int num);

int main() {
  int new_len = 0;
  int num_list[LEN];
  int input = 1;

  int answer_a = 0;
  int answer_b = 0;
  int answer_c = 0;

  printf("Enter a list of numbers:\n");

  for (int i = 0; i < LEN; i++) {
    scanf("%d", &input);
    if (input < 1) {
      new_len = i; // Save list length
      break;
    }
    num_list[i] = input;
  }

  for (int i = 0; i < new_len; i++) { // Loop over list of numbers up until list length
    answerQuestions(num_list[i], &answer_a, &answer_b, &answer_c);

    printf("Evaluation for #%d:\n", num_list[i]);
    printf("a. Is the value a multiple of 7, 11, or 13? ");
    if (answer_a) { printf("Yes\n"); } else { printf("No\n"); };
    printf("b. Is the sum of the digits odd or even? ");
    if (answer_b) { printf("Even\n"); } else { printf("Odd\n"); };
    printf("c. Is the value a prime number? ");
    if (answer_c) { printf("Yes\n"); } else { printf("No\n"); };
  }
}

void answerQuestions(int num, int *answer_a, int *answer_b, int *answer_c) {
  *answer_a = ((num % 7 == 0) || (num % 11 == 0) || (num % 13 == 0)) ? 1 : 0;
  *answer_b = (sumOfDigits(num) % 2 == 0) ? 1 : 0;
  *answer_c = isPrimeNumber(num);
}

int sumOfDigits(int num) {
  int sum = 0;
  while (num >= 1) { // Run loop until last digit is divided by 10
    int digit = num % 10; // Find right-most digit using modulo
    sum += digit; // Add digit to sum of digits
    num *= 0.1; // Set input number to itself divided by 10.
  }
  return sum; // Return sum
}

int isPrimeNumber(int num) { // Determine if input is prime number
  if (num % 2 == 0) return 0; // If even, not a prime number
  for (int i = 3; i <= sqrt(num); i += 2) { // Loop over odd values until sqrt(num)
    if (num % i == 0) return 0; // If divisible by odd value, not a prime number
  }
  return 1; // Else, is prime number
}