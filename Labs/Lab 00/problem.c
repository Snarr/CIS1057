#include <stdio.h>

int main() {
	char name[50];
	int age;

	printf("Hello World!\n");


	printf("Enter your name:\n");
	scanf("%s", name);

	printf("Enter your age:\n");
	scanf("%d", &age);

	printf("Hello %s. You are %d.\n", name, age);

	if (age < 35)
		printf("You are young!\n");
	else if (age < 50)
		printf("You are middle age!\n");
	else
		printf("You are old\n");

	int i = 0;
	for(i=0; i<=20; i++)
		printf("i = %d\n", i);
	

	return 0;
}