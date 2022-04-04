#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

int main() {

	int x;
	printf("Polinomul este: X^3 + 3X^2 - X - 3\nIntrodu X: ");
	scanf_s("%d", &x);
	printf("Rezultatul polinomul este: %d", x*x*x + 3*x*x  - x - 3);


	return 0;
}