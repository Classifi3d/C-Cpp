#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a,figureCounter=1;
	printf("Enter a value to determin the number of figures it has\n");
	scanf_s("%d", &a);

	while (a > 9) {
		figureCounter++;
		a /= 10;
	}

	printf("%d",figureCounter);


	return  0;
}
