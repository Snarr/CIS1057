/*
 * 	Lab 7, Problem 12
 *
 *	Programmer: Jacob Snarr   Date Completed: November 14th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	Implement binary search algorithm
*/

/*
When there is a large number of array elements, which function
do you think is faster: binary_srch or the linear search
function of Figure 7.14?

I think that the binary search algorithim would definitely be
faster than the linear search algorithm for large sets of data.
*/

#include <stdio.h>

#define ARRAY_LENGTH 10

int binary_srch(int arr[], int bottom, int top, int target);
void print_results(int arr[], int length, int target, int found_index);

int main() {
  int arr[ARRAY_LENGTH] = {0, 1, 12, 27, 35, 50, 52, 73, 81, 99};
  int target = 35;
  int found_index = binary_srch(arr, 0, ARRAY_LENGTH, target);
  print_results(arr, ARRAY_LENGTH, target, found_index);
}

/* Implements binary search algorithm for finding item in an array
 * Pre:   The array, the index of the lower bound,
 *        the index of the upper bound, and the target are defined.
 * Post:  The index of the target is returned as the function value.
*/
int binary_srch(int arr[], int bottom, int top, int target) {
  int found = 0;
  int index = -1; // Set flag in case index of target is not found

  while (bottom <= top && found == 0) {
    int middle = ((top-bottom)/2)+bottom;

    if (arr[middle] == target) {
      found = 1;
      index = middle;
    } else if (arr[middle] > target) {
      top = middle-1;
    } else {
      bottom = middle+1;
    }
  }
  return index;
}

/* Prints results of the binary search to the user
 * Pre:   The array, the length of the array, the target value,
 *        and the found index are defined.
 * Post:  The array, the target, and the index are printed to
 *        the user. The user is notified if the target is not
 *        found in the array.
*/
void print_results(int arr[], int length, int target, int found_index) {
  printf("Array:   {");
  for (int i = 0; i < length; i++) { // Loop through and print each array element
    if (i == length-1) {
      printf("%d}\n", arr[i]); // For the last element, close the printed array bracket
      continue;
    }
    printf("%d, ", arr[i]);
  }
  printf("Target:  %d\n", target);
  (found_index != -1) ? printf("Index:   %d\n", found_index) : printf("Index:   Not Found\n");
}