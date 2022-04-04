#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b,c,cDetermined;
	printf("Insert from the keyboard 3 integer numbers: a b and c\n");
	scanf_s("%d%d%d", &a,&b,&c);
	cDetermined = sqrt(a * a + b * b);
	printf("The diagonal fromed from a and b is %d\n", cDetermined);
	if (c == cDetermined) {
		printf("The c variable is a diagonal for the rectangle fromed by the a and b variables as sides\n");
	}



	return  0;
}

