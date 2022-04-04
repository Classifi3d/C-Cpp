#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX 100

void readMatrix(int(*v)[MAX], int& n, int& m);
void displayMatrix(int(*v)[MAX], int n, int m);
void displayColumnMatrixOrSecDiag(int(*v)[MAX], int n, int m, int c);

int main() {
	int v[MAX][MAX], n, m, c;
	printf("Read from the keyboard the elements of an m x n integer matrix. If the matrix is square, the program will display the elements from the secondary diagonal. If not, print the sum of all the elements from a certain column, c.\n");
	readMatrix(v, n, m);
	scanf_s("%d", &c);
	printf("\n");
	displayColumnMatrixOrSecDiag(v, n, m, c);

	printf("\n\n");
	displayMatrix(v, n, m);


	return 0;
}

void readMatrix(int(*v)[MAX], int& n, int& m) {
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s(" %d", *(v + i) + j );
		}
	}
}

void displayMatrix(int(*v)[MAX], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", *(*(v + i) + j));
		}printf("\n");
	}

}

void displayColumnMatrixOrSecDiag(int(*v)[MAX], int n, int m, int c) {
	if (m == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + j == m - 1) {
					printf("%d ", *(*(v + i) + j));
				}

			}
		}
	}
	else {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += *(*(v + i) + c);
		}
		printf("%d", sum);
	}

}
