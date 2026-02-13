// 1. Print “Hello, NAME” where NAME is input from the keyboard.
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[] ) {
	char *str;
	size_t bytes;
	ssize_t length = getline(&str, &bytes, stdin);

	printf("Type your name, and press enter.\n");

	// Since `length` includes the newline, 
	// we need at least 2 characters
	if (length < 2) {
		printf("No name given.\n");
		return 1;
	}

	printf("Hello, %s", str);


	free(str);

	return 0;
}
