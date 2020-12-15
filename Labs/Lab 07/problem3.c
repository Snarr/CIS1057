/*
 * 	Lab 7, Problem 3
 *
 *	Programmer: Jacob Snarr   Date Completed: November 14th, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	Take a system of point masses [(x, y, z), mass] and use them
 *  to calculate the center of gravity of the system.
*/

#include <stdio.h>

#define INPUT_FILE "file.txt"
#define N_MAX 10

int fget_point_mass(FILE *file, int p_location[N_MAX][3], int p_mass[]);
void center_grav(int p_location[][3], int p_mass[], int n, double p_cog[3]);
void fwrite_point_mass(int p_location[N_MAX][3], int p_mass[], int n, double p_cog[3]);

int main(void) {
  int location[N_MAX][3];
  int mass[N_MAX];
  double cog[3];
  
  FILE *input_file = fopen(INPUT_FILE, "r"); // Open input file for reading
  int n = fget_point_mass(input_file, location, mass);
  fclose(input_file); // Close file after  values are stored
  center_grav(location, mass, n, cog);
  fwrite_point_mass(location, mass, n, cog);

  return 0;
}


/* Gets point mass system information from file
 * Pre:   File path is defined.
 * Post:  Location matrix information and mass values are returned
 *        through output arrays.
 *        The actual number of point masses is returned as the function value.
*/
int fget_point_mass(FILE *file, int p_location[N_MAX][3], int p_mass[]) {
  int n;
  fscanf(file, "%d", &n); // Scan the file for the first integer, store that as N

  for (int r = 0; r < n; r++) { // Loop through each row from Row 0 to Row N
    for (int i = 0; i < 4; i++) { // Loop through the 4 integers per row
      int k;
      fscanf(file, "%d", &k); // Store the current integer in local variable K

      if (i == 3) {
        p_mass[r] = k; // If last value in the row, store as a mass
      } else {
        p_location[r][i] = k; // Otherwise, store in a location vector
      }
    }
  }
  return n;
}

/* Calculates Center of Gravity of system of point masses
 * Pre:   Location matrix, masses, and
 *        number of rows are defined.
 * Post:  Center of gravity values
 *        returned through output array.
*/
void center_grav(int p_location[][3], int p_mass[], int n, double p_cog[3]) {
  int location_sums[3] = {0, 0, 0};
  int mass_sum = 0;

  for (int i = 0; i < n; i++) { // Loop through each row AKA location matrix
    for (int j = 0; j < 3; j++) { // Loop through each value of the location matrix
      location_sums[j] += p_location[i][j]*p_mass[i]; // Add Location Value * Mass Value to respective location sum
    }
    mass_sum += p_mass[i]; // Add current mass value to Mass Sum
  }

  for (int i = 0; i < 3; i++) { // Calculate 3 center of gravity (CoG) values
    p_cog[i] = (1.0*location_sums[i])/(1.0*mass_sum); // Divide location sum by mass sum and store as a double CoG value
  }
}

/* Prints Point Mass and Center of Gravity information
 * Pre:   Location matrix, masses, number of rows, and center
 *        of gravity values are defined.
 * Post:  Information is formatted and printed to the user.
*/
void fwrite_point_mass(int p_location[N_MAX][3], int p_mass[], int n, double p_cog[3]) {
  for (int i = 0; i < n; i++) { // Loop over and print information for each point mass
    printf("Point Mass %d\n", i+1);
    printf("     Location: (%d, %d, %d)\n", p_location[i][0], p_location[i][1], p_location[i][2]);
    printf("     Mass:      %d g\n", p_mass[i]);
  }
  printf("Number of Point Masses\n"); // Print N, number of point masses
  printf("     N:         %d\n", n);
  printf("Center of Gravity\n"); // Print CoG
  printf("     Location: (%0.2lf, %0.2lf, %0.2lf)\n", p_cog[0], p_cog[1], p_cog[2]);
};