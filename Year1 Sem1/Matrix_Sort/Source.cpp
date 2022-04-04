#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 100

void readMatrix(char v[MAX][MAX], int& n, int& m) {
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s(" %c", &v[i][j]);
		}
	}
}

void sumNumbersMatrix(char v[MAX][MAX], int n, int m) {
	int dim[MAX];// n
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			try {
				if (int(v[i][j]) > 48 && int(v[i][j]) < 57) {
					sum += int(v[i][j]) - 48;
					//cout << "*";
				}

			}
			catch (int e) {}
		}
		cout << sum << endl;
		dim[i] = sum;
		char auxv[MAX];//m
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (dim[j] > dim[j + 1]) {
					char aux = dim[j];
					dim[j] = dim[j + 1];
					dim[j + 1] = aux;

					for (int I = 0; I < m; I++) {
						auxv[I] = v[j][I];
					}

					for (int I = 0; I < m; I++) {
						v[j][I] = v[j + 1][I];
					}

					for (int I = 0; I < m; I++) {
						v[j + 1][I] = auxv[I];
					}
				}
			}
		}

	}
}


void displayMatrix(char v[MAX][MAX], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", v[i][j]);
		}printf("\n");
	}

}

int main() {
	char v[MAX][MAX];
	int n, m;
	printf("Read from the keyboard the dimensions dimensions then a matrix with alphanumerical elements.\n");
	readMatrix(v, n, m);
	displayMatrix(v, n, m);

	sumNumbersMatrix(v, n, m);
	displayMatrix(v, n, m);


	return  0;
}
