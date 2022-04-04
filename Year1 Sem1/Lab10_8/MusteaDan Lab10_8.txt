#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#define max 256

int main(int argc, char* argv[]) {

	int i;

	char* string1[max],*string2[max];
	if (argc == 1) {
		printf("You have not entered the strings\n");
		exit(1);
	}

	*string1 = argv[1];

	printf("%s\n", _strrev(*string1));

	return 0;
}