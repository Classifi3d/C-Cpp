#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,imperfectSquare;
	printf("Enter a value the check it if it's a square root\n");
	scanf_s("%d", &n);
	imperfectSquare = sqrt(n);
	if (imperfectSquare * imperfectSquare == n) {
		printf("The number is a square root");
	}
	else printf("The number is not a square root");

	return  0;
}
