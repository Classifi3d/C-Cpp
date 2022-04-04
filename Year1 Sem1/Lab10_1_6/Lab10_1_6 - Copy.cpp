
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  100

void  readMatrix(int  v[MAX][MAX], int& n, int& m);
void  displayMatrix(int  v[MAX][MAX], int  n, int  m);
void  oddPostionDisplayMatrix(int  v[MAX][MAX], int  n, int  m);
int  sumEvenElementsMatrix(int  v[MAX][MAX], int  n, int  m);
void  sumEvenElementsTwoMatrices(int  a[MAX][MAX], int  b[MAX][MAX], int  na, int  ma, int  nb, int  mb);
int  sumTwoMatrices(int  a[MAX][MAX], int  b[MAX][MAX], int  na, int  ma, int  nb, int  mb);

int  main() {
	int  A[MAX][MAX], B[MAX][MAX];
	int (*a)[MAX] = A, (*b)[MAX]=B;
	int  na, ma, nb, mb;
	printf("\n");
	readMatrix(a, na, ma);
	//readMatrix(b, nb, mb);

	displayMatrix(a, na, ma);
	//displayMatrix(b, nb, mb);

	//oddPostionDisplayMatrix(a, na, ma);
	printf("\n");
	//sumEvenElementsTwoMatrices(a, b, na, ma, nb, mb);
	printf("\n");
	//sumTwoMatrices(a, b, na, ma, nb, mb);



	return    0;
}

void  readMatrix(int  *v, int& n, int& m) {
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("  %d", &v[i]);
		}
	}
}

void  displayMatrix(int  v[MAX][MAX], int  n, int  m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d  ", v[i][j]);
		}printf("\n");
	}

}

void  oddPostionDisplayMatrix(int  v[MAX][MAX], int  n, int  m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] % 2 != 0) {
				printf("positon:  %d,  %d\n", i, j);
			}
		}
	}

}

int  sumEvenElementsMatrix(int  v[MAX][MAX], int  n, int  m) {
	int  sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] % 2 == 0) {
				sum += v[i][j];
			}
		}
	}
	return  sum;
}

void  sumEvenElementsTwoMatrices(int  a[MAX][MAX], int  b[MAX][MAX], int  na, int  ma, int  nb, int  mb) {
	printf("%d", sumEvenElementsMatrix(a, na, ma) + sumEvenElementsMatrix(b, nb, mb));
}

int  sumTwoMatrices(int  a[MAX][MAX], int  b[MAX][MAX], int  na, int  ma, int  nb, int  mb) {
	if (mb != ma) {
		printf("the  matrices  dimensions  do  not  match!\n");
		return  0;
	}

	if (nb != na) {
		printf("the  matrices  dimensions  do  not  match!\n");
		return  0;
	}

	for (int i = 0; i < na; i++) {
		for (int j = 0; j < ma; j++) {
			printf("%d  ", a[i][j] + b[i][j]);
		}printf("\n");
	}
	return  0;
}
