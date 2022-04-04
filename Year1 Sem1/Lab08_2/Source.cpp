#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 20

int main() {
	int v[MAX];
	int n, smallestValue, highestValue;
	printf("Read from the keyboard a dimension then an array with integer as elements, then the program determines the value of the smallest positive element from a one dimensional array.\n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}

	smallestValue = v[0];
	highestValue = v[0];

	for (int i = 0; i < n; i++) {
		if (v[i] < smallestValue) smallestValue = v[i];
		if (v[i] > highestValue) highestValue = v[i];
	}


	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	printf("smallest value:%d\nhighest value:%d", smallestValue, highestValue);

	return  0;
}
