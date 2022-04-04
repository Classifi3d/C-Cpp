#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 3

void readMatrix(float v[MAX][MAX], int n, int m) {
	for (int i = 0; i < n; i++) {//y
		for (int j = 0; j < m; j++) {//x
			scanf_s("%f", &v[i][j]);
		}
	}
}

void sumNumbersMatrix(float v[MAX][MAX], int n, int m) {
	float SUM[MAX];// 3
	for (int j = 0; j < n; j++) {//y
		float sum = 0;
		for (int i = 0; i < m; i++) {//x
			sum += v[i][j];
		}
		cout << sum << endl;
		SUM[j] = sum;
	}
	float auxv[MAX];// 3
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (SUM[j] > SUM[j + 1]) {
				float aux = SUM[j];
				SUM[j] = SUM[j + 1];
				SUM[j + 1] = aux;

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


void displayMatrix(float v[MAX][MAX], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%f ", v[i][j]);
		}printf("\n");
	}

}

int main() {
	float v[MAX][MAX];
	int n=3, m=3;
	printf("Read from the keyboard the elements of 3 by 3 matrix with float elements.\n");
	readMatrix(v, n, m);
	displayMatrix(v, n, m);

	sumNumbersMatrix(v, n, m);
	displayMatrix(v, n, m);


	return  0;
}
