#include <iostream>

using namespace std;

#define max 100

void display(int* a[max], int n) {
	for (int i = 0; i < n; i++) {//allocation
		for (int j = 0; j < n; j++) {
			printf("%d ",a[i][j]);
		}printf("\n");
	}
}

int sum(int* a[max], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {//allocation
		for (int j = 0; j < n; j++) {
			if (i > j) {//below the main diagonal
				if (a[i][j] > 0) {//positive numbers
					sum += a[i][j];
				}
			}
		}
	}
	return sum;
}

int main(){
	int n, ** a;

	scanf_s("%d", &n);
	if ((a = new int* [n])) {
		for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			if (a[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < n; i++) {//allocation
			for (int j = 0; j < n; j++) {
				scanf_s("%d", &a[i][j]);
			}
		}

		display(a, n);
		printf("%d", sum(a, n));
	}
	else
		cout << "Alocation failed!";

	if (a) {
		for (int i = 0; i <n; i++)
			delete[]a[i];
		delete[]a;
	}
}