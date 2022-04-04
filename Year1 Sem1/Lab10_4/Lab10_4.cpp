
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  20
void  readMatrix(int(*v)[MAX], int &n, int &m);
void  displayMatrix(int(*v)[MAX], int  n, int  m);
void  sumMatrix(int(*a)[MAX], int  na, int  ma, int(*b)[MAX], int  nb, int  mb, int(*c)[MAX], int &nc, int &mc);


int  main() {
	int  A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	int(*a)[MAX] = A, (*b)[MAX] = B, (*c)[MAX] = C;
	int  na=0, ma = 0, nb = 0, mb = 0, nc = 0, mc = 0;

	printf("Read from the keyboard the elements of a 3x3 float matrix. Rearrange the columns so that the sum of each column's elements is smaller than the sum of the elements of the next column to the right.\n");
	readMatrix(a, na, ma);
	readMatrix(b, nb, mb);
	displayMatrix(a, na, ma);
	displayMatrix(b, nb, mb);
	sumMatrix(a, na, ma, b,nb,mb,c,nc,mc);
	displayMatrix(c, nc, mc);
	if (nc == mc) {
		for (int i = 0; i < nc; i++) {
			for (int j = 0; j < mc; j++) {
				if (i + j == nc - 1) {
					printf("%d ", *(*(c + i) + j));
				}
			}
		}
	}


	return    0;
}

void  readMatrix(int(*v)[MAX], int &n, int &m) {
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			*(*(v + i) + j) = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s(" %d", *(v + i) + j);
		}
	}
}

void  displayMatrix(int(*v)[MAX], int  n, int  m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d  ", *(*(v + i) + j));
		}printf("\n");
	}
	printf("\n");
}

void sumMatrix(int(*a)[MAX], int  na, int  ma, int(*b)[MAX], int  nb, int  mb, int(*c)[MAX], int &nc, int &mc) {
	nc = 0,mc=0;
	if (na > nb) {
		nc = na;
	}
	else {
		nc = nb;
	}
	if (ma > mb) {
		mc = ma;
	}
	else {
		mc = mb;
	}

	for (int i = 0; i < nc; i++) {
		for (int j = 0; j < mc; j++) {
			*(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
		}
	}
}
