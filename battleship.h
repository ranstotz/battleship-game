#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LEN 80

// Read and return an integer
int getInt(void)
{
	int n;
	scanf_s(" %d", &n);
	// printf("You have entered whole number %d. \n", n);
	return n;
}

// Read and return a double
double getDouble(void)
{
	double x;
	scanf_s(" %lf", &x);
	// printf("You have entered real number  %lf. \n", x);
	return x;
}

// Read and return a char
char getCharacter(void)
{
	char ch;
	scanf_s(" %c", &ch, 1);
	// printf("You have entered a %c. \n", ch);
	return ch;
}

// Read a string into "list", a char array input/output parameter.
void getString(char list[])
{
	int i = 0;
	char ch;
	scanf_s(" %c", &ch, 1);

	// Keep reading characters until you hit \n (new line) or the max string size
	// (whichever comes first). Need to save one spot at the end to hold the null character
	// '\0' that marks the end of the characters in the string.
	while ((ch != '\n') && (i < MAX_STRING_LEN - 1))
	{
		list[i] = ch;
		ch = getchar();
		i++;
	}

	// If we hit the max string size before the new line, then consume all the rest
	// of the characters until the new line but do not save these characters (because
	// they wouldn't fit in the string).
	while (ch != '\n')
	{
		ch = getchar();
	}

	// put the null character '\0' after all the real characters. C (e.g. printf) expects this.
	list[i] = '\0';
}
