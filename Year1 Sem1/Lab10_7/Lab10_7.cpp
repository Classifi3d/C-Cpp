#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#define max 256

int main(int argc, char* argv[]) {

	int i;

	char *string1[max],*string2[max],*string3[max];
	if (argc == 1) {
		printf("You have not entered the strings\n");
		exit(1);
	}

	*string1 = argv[1];
	*string2 = argv[2];

	strcat(*string3, *string1);
	strcat(*string3, *string2);
	printf("%s\n",*string3);

	return 0;
}
