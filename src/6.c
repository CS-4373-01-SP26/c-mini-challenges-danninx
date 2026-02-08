// 6. Write a program that accepts a string input from stdio and sends it to a function that transforms it according a transposition function passed in to it as an argument. The function will print out the string, transform it, and then print out the result. The transposition function, you can assume, simply shuffles the existing characters in the string. Build a transposition function that reverses the string and apply it. Where appropriate and possible, use dynamic allocation and pointer arithmetic to get the job done.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STR_EQ(a, b) strcmp(a, b) == 0

typedef enum {
	CAESAR,
	REVERSE,
} Selection;

void reverse(char *str, int length) {
	int i,j;
	i = 0;
	j = length-1;

	while (i < j) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

void caesar(char *str, int length) {
	for (int i=0; i<length; i++) {
		char current = str[i];	
		if (!isalpha(current)) continue;
		
		if (!isupper(current)) { // lowercase
			str[i] = ((current - 'a' + 3) % 26) + 'a';
		} else { // uppercase
			str[i] = ((current - 'A' + 3) % 26) + 'A';
		}
	}		
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: six FUNCTION\navailable functions:\n\t- caesar\n\t- reverse");
		exit(1);
	}

	char *function = argv[1];
	Selection func;
	if (STR_EQ(function, "caesar")) {
		func = CAESAR;
	} else if (STR_EQ(function, "reverse")) {
		func = REVERSE;
	} else {
		printf("function is not valid\navailable functions:\n\t- caesar\n\t- reverse");
		exit(1);
	}

	printf("provide a string (max length 10 characters):\n");
	char str[11];
	int length;
	scanf("%10s%n", str, &length);

	printf("original : %s\n", str);
	switch(func) {
		case CAESAR:
			caesar(str, length);
			break;
		case REVERSE:
			reverse(str, length);
			break;
	}
	
	printf("(%s) : %s\n", function, str);
}
