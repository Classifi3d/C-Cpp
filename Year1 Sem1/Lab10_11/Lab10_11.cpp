#include <iostream>

using namespace std;

#define max 20

void Read(int(*mat)[max], int& n);
int NumNeg(int(*mat)[max], int n);

int main(){

	int mat[max][max],n;
	int (*m)[max] = mat;

	Read(m, n);
	printf("%d", NumNeg(m, n));
}

void Read(int(*mat)[max], int& n) {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &(*(*(mat + i) + j)));
		}
	}
}

int NumNeg(int(*mat)[max], int n) {
	int  count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (n - 1 > i + j) {
				if (*(*(mat + i) + j) < 0) {
					count++;
				}
			}
		}
	}
	return count;
}