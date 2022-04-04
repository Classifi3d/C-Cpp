#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a, b, aux = 1, x, y;
	printf("Enter two values to find out the the least common multiple of the 2 integer numbers\n");
	scanf_s("%d%d", &a, &b);

	x = a, y = b;
	while (x != y) {
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	printf("the result is %d", a * b / x);


	return  0;
}
	