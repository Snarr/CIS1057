/*
 * 	Lab 8, Problem 8
 *
 *	Programmer: Jacob Snarr   Date Completed: November 23rd, 2020
 * 	Instructor: Joe Jupin	    Class: CIS 1057.001
 * 
*/

#include <stdio.h>
#include <string.h>

void longest_common_suffix(char *s1, char *s2, char *output);
void fill_output(char *s, char *output, int s1_count, int s1_length);

int main() {
  char word1[50];
  char word2[50];
  char suffix[50];

  printf("Longest Common Suffix Finder\n\n");
  printf("Enter two words to find the longest common suffix between the two.\n");
  
  printf("Word 1: ");
  scanf("%s", word1);

  printf("Word 2: ");
  scanf("%s", word2);

  longest_common_suffix(word1, word2, suffix);

  // printf("%s", suffix);

  printf("%s %s %s \n", word1, word2, suffix);
}

void longest_common_suffix(char *s1, char *s2, char *output) {
  int s1_length = strlen(s1);
  int s1_count = s1_length;
  int s2_length = strlen(s2);
  int s2_count = s2_length;
  int output_count = 0;

  while (s1[s1_count] == s2[s2_count]) {
    s1_count--;
    s2_count--;
  }

  if (s2_length > s1_length) {
    fill_output(s2, output, s2_count, s2_length);
  } else {
    fill_output(s1, output, s1_count, s1_length);
  }
}

void fill_output(char *s, char *output, int s1_count, int s1_length) {
  for (int i = 0; i <= s1_length; i++) {
      if (i == s1_length) {
        output[i] = '\0';
        continue;
      }
      output[i] = s[s1_count+1+i];
    }
}