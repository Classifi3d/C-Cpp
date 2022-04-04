#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include  <conio.h>
using namespace std;


int main() {
	int n = 0,sumOddPositive=0, cInteger=0,count=0;
	char c;
	printf("Enter a series of integer numbers, until the user presses on the <Esc>-key. The program display the average value of the odd positive numbers.\n");

	do {
		scanf_s("%d", &cInteger);
		if (cInteger > 0 && cInteger % 2 != 0) {
			sumOddPositive += cInteger;
			count++;
		}
		printf("Do you want to exit the program?\n");
		c = _getch();
	} while (c != 27);

	try {
		printf("%d", sumOddPositive / count);
	}
	catch (int e) {
		printf("There are non odd postive numbers");
	}

	return  0;
}
