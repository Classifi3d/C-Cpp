#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a;
	printf("Enter a value to find out all of the divisors\n");
	scanf_s("%d", &a);

	for (int i = 1; i <= a / 2; i++) {
		if (a % i == 0) {
			printf("%d\n", i);
		}
	}
	


	return  0;
}
