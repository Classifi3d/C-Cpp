#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 100


void readArray(int v[MAX], int& n);
void displayNegativeOdd(int v[MAX], int n);

int main() {
	int v[MAX];
	int n;
	printf("Reads from the keyboard n integer values. The program will display the negative odd numbers and how many there are.\n");
	readArray(v, n);
	displayNegativeOdd(v, n);



	return  0;
}

void readArray(int v[MAX], int& n) {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}
}


void displayNegativeOdd(int v[MAX], int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < 0) {
			if ((-1 * v[i]) % 2 == 1) {
				printf("%d ", v[i]);
				counter++;
			}
		}
	}printf("\nThere are %d negative odd numbers in the array.\n",counter);
}