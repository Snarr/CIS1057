/*
 * 	Lab 10, Problem 2
 *
 *	Programmer: Jacob Snarr   Date Completed: November 30th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	
*/

#include <stdio.h>
#include <string.h>

#define INPUT_FILE "file2.txt"

struct element_t {
  int atomic_number;
  char name[25];
  char symbol[3];
  char class[25];
  double atomic_weight;
  int electrons[7];
};

struct element_t scan_element(FILE *file);
void print_element(struct element_t element);

int main() {
  struct element_t sodium;
  
  FILE *input_file = fopen(INPUT_FILE, "r"); // Open input file for reading

  sodium = scan_element(input_file);

  fclose(input_file); // Close file after  values are stored

  print_element(sodium);
}

struct element_t scan_element(FILE *file) {
  struct element_t element;

  fscanf(file, "%d", &element.atomic_number);
  fscanf(file, "%s", &element.name);
  fscanf(file, "%s", &element.symbol);
  fscanf(file, "%s", &element.class);
  fscanf(file, "%lf", &element.atomic_weight);

  for (int i = 0; i < 7; i++) {
    fscanf(file, "%d", &element.electrons[i]);
  }

  return element;
}

void print_element(struct element_t element) {
  printf("Atomic Number: %d\n", element.atomic_number);
  printf("Name: %s\n", element.name);
  printf("Symbol: %s\n", element.symbol);
  printf("Class: %s\n", element.class);
  printf("Atomic Weight: %0.4lf\n", element.atomic_weight);
  printf("Electrons:\n    ");
  for (int i = 0; i < 7; i++) {
    printf("%d / ", element.electrons[i]);
  }
}