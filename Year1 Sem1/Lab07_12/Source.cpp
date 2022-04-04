#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int n,counter=1;
	float sum = 0,a;
	printf("Read from the keyboard an integer number n. Read a series of real numbers, until their sum is greater than n.\n");
	scanf_s("%d", &n);

	scanf_s("%f", &a);
	sum = a;
	while (sum < n) {
		counter++;
		scanf_s("%f", &a);
		sum += a;
	}

	printf("\n%.2f\n%d\n",sum, counter);


	return  0;
}
