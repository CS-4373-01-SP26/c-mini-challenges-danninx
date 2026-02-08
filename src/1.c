// 1. Print “Hello, NAME” where NAME is input from the keyboard.
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[] ) {
	if (argc != 2) {
		printf("usage: hello NAME");
		exit(1);
	}

	printf("Hello, %s\n", argv[1]);

	return 0;
}
