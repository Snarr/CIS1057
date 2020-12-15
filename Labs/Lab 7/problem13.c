/*
 * 	Lab 7, Problem 13
 *
 *	Programmer: Jacob Snarr   Date Completed: November 14th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	Implements the bubble sort array sorting algorithm
*/

#include <stdio.h>

#define ARRAY_LENGTH 10

void bubble_sort(int arr[], int length);
void print_int_array(int arr[], int length);

int main() {
  int arr[ARRAY_LENGTH] = {34, 65, 81, 3, 451, 92, -3, 49, 56, 11};

  printf("Unsorted:\n");
  print_int_array(arr, ARRAY_LENGTH); // Print Unsorted Array

  bubble_sort(arr, ARRAY_LENGTH); // Sort Array using Bubble Sort

  printf("Sorted:\n");
  print_int_array(arr, ARRAY_LENGTH); // Print Sorted Array
}

/* Implements bubble sort algorithm for sorting an array
 * Pre:   The array and the length of the array are defined.
 * Post:  The array is sorted on each pass and each change is
 *        returned as an array output parameter.
*/
void bubble_sort(int arr[], int length) {
  for (int l = 0; l < length-1; l++) { // Length modifier loop for each pass
    for (int i = 0; i < length-1-l; i++) { // Loop through array from 0 to New Length (length minus l) minus 1
      if (arr[i] > arr[i+1]) {
        int tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
      }
    }
  }
}

/* Prints any integer array.
 * Pre:   The array, and the length of the array, are defined.
 * Post:  The array is printed to the user.
*/
void print_int_array(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
    
    if (i == length-1) {
      printf("\n");
    }
  }
}