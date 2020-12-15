/*
 * 	Lab 10, Problem 1
 *
 *	Programmer: Jacob Snarr   Date Completed: November 30th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	
*/

#include <stdio.h>

#define INPUT_FILE "file.txt"

struct date_t {
  int year;
  int month;
  int day;
};

struct tank_t {
  double tank_capacity;
  double fuel_level;
};

struct auto_t {
  char make[25];
  char model[25];
  int odometer;

  struct tank_t tank;
  
  struct date_t manufacture_date;
  struct date_t purchase_date;
};

struct date_t scan_date(FILE *file);
struct tank_t scan_tank(FILE *file);
struct auto_t scan_auto(FILE *file);
void print_date();
void print_tank();
void print_auto(struct auto_t car);

int main() {
  struct auto_t car[25];
  
  FILE *input_file = fopen(INPUT_FILE, "r"); // Open input file for reading
  
  for (int i = 0; !feof(input_file); i++) {
    car[i] = scan_auto(input_file);
    printf("------------------\n");
    print_auto(car[i]);
  }

  fclose(input_file); // Close file after  values are stored

  return 0;
}

struct auto_t scan_auto(FILE *file) {
  struct auto_t car;

  fscanf(file, "%s", &car.make);
  fscanf(file, "%s", &car.model);
  fscanf(file, "%d", &car.odometer);

  car.manufacture_date = scan_date(file);
  car.purchase_date = scan_date(file);
  car.tank = scan_tank(file);

  return car;
}

struct date_t scan_date(FILE *file) {
  struct date_t date;

  fscanf(file, "%d", &date.month);
  fscanf(file, "%d", &date.day);
  fscanf(file, "%d", &date.year);

  return date;
}

struct tank_t scan_tank(FILE *file) {
  struct tank_t tank;

  fscanf(file, "%lf", &tank.tank_capacity);
  fscanf(file, "%lf", &tank.fuel_level);

  return tank;
}

void print_auto(struct auto_t car) {
  printf("Make: %s\n", car.make);
  printf("Model: %s\n", car.model);
  printf("Odometer: %d\n", car.odometer);

  printf("Manufacture Date:\n");
  print_date(car.manufacture_date);
  printf("Purchase Date:\n");
  print_date(car.purchase_date);

  printf("Tank:\n");
  print_tank(car.tank);
}

void print_date(struct date_t date) {
  printf("  Month: %d\n", date.month);
  printf("  Day: %d\n", date.day);
  printf("  Year: %d\n", date.year);
}

void print_tank(struct tank_t tank) {
  printf("  Tank Capacity: %0.1lf\n", tank.tank_capacity);
  printf("  Fuel Capacity: %0.1lf\n", tank.fuel_level);
}