/*
 * 	Lab 8, Problem 5
 *
 *	Programmer: Jacob Snarr   Date Completed: November 23rd, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
 * 	
*/

#include <stdio.h>
#include <string.h>

int main() {
  char noun[20];
  char revised_noun[10];
  int noun_length;

  printf("Enter a noun: ");
  scanf("%s", noun);

  noun_length = strlen(noun);

  char *suffix = noun + (noun_length-2); 

  if (!strcmp(suffix+1, "y")) {
    noun[noun_length-1] = '\0';
    strcat(noun, "ies");
  } else if (!strcmp(suffix+1, "s") || !strcmp(suffix, "ch") || !strcmp(suffix, "sh")) {
    strcat(noun, "es");
  } else {
    strcat(noun, "s");
  }

  printf("%s\n", noun);
}