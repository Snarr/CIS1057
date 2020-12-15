/*
 * 	Lab 8, Problem 2
 *
 *	Programmer: Jacob Snarr   Date Completed: November 19th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int search(char COLOR_CODES[10][7], int size, char color[7]);

int main() {
  char COLOR_CODES[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};

  char band1[7];
  int digit1;
  char band2[7];
  int digit2;
  char band3[7];
  int multiplier;

  char repeat_flag;

  while(1) {
    printf("Enter the colors of the resistor's three bands, beginning with\nthe band nearest the end. Type the colors in lowercase letters\nonly, NO CAPS.\n");

    printf("Band 1 => ");
    scanf("%s",band1);
    digit1 = search(COLOR_CODES, 10, band1);
    
    printf("Band 2 => ");
    scanf("%s",band2);
    digit2 = search(COLOR_CODES, 10, band2);

    printf("Band 3 => ");
    scanf("%s",band3);
    multiplier = search(COLOR_CODES, 10, band3);

    if (digit1 == -1) {
      printf("Invalid color: %s\n", band1);
    } else if (digit2 == -1) {
      printf("Invalid color: %s\n", band2);
    } else if (multiplier == -1) {
      printf("Invalid color: %s\n", band3);
    } else {
      double resistance_value = (((digit1*10.0) + digit2*1.0)*pow(10.0,multiplier))/1000.0;

      printf("Resistance value: %.2lf kilo-ohms\n", resistance_value);
    }

    printf("Do you want to decode another resistor?\n=> ");
    scanf(" %c", &repeat_flag);

    if (repeat_flag == 'y') {
      printf("\n");
      continue;
    } else {
      break;
    }
  }
  
  return (0);
}

int search(char COLOR_CODES[10][7], int size, char color[7]) {
  for(int i = 0; i < size; i++) {
    if (strcmp(color, COLOR_CODES[i]) == 0) {
      return i;
    }
  }
  return -1;
}
