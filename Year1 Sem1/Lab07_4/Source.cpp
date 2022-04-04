#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, result;
	printf("Enter a value from the keyboard an integer value n, and calculates n!\n");
	scanf_s("%d", &n);
	result = 1;
	while (n > 0) {
		result *= n;
		n--;
	}
	printf("%d", result);

	return  0;
}
