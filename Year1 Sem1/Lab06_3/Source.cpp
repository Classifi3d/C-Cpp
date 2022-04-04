#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	unsigned char var;

	printf("Enter a char value:\n");
	scanf_s("%c", &var);

	for (int i = 0; i < 8; i++) {
		printf("the position: %d and the bit: %d\n", i+1, var % 2);
		var = var >> 1;
	}

	return  0;
}

