#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 10

void sortAndDisplay(int v[], int n);

int main() {
	int v[MAX];
	int n;
	printf("Read from the keyboard a dimension then an array with integer as elements,Define and implement a function that receives the array as parameter and then displays its elements, ordered increasingly.\n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}

	sortAndDisplay(v,n);

	return  0;
}

void sortAndDisplay(int v[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (v[j] > v[j + 1]) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

}