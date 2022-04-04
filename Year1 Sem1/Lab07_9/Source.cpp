#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a, b, aux=1, x, y;
	printf("Enter two values to find out the integer quotien of 2 integer numbers by using a series of subtractions\n");
	scanf_s("%d%d", &x, &y);
	if (x > y) {
		a = x;
		b = y;
	}
	else {
		a = y;
		b = x;
	}

	while (a > b) {
		a -= b;
	}

	printf("the result is %d", a);


	return  0;
}
