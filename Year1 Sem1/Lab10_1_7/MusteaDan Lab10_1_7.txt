
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  3

void  readMatrix(int(*v)[MAX], int n, int m);
void  displayMatrix(int(*v)[MAX], int  n, int  m);
void  rearrageMatrix(int(*v)[MAX], int  n, int  m, int(*c)[MAX]);


int  main() {
	int  V[MAX][MAX];
	int(*v)[MAX] = V;
	int  nv = 3, mv = 3;
	int cpy[MAX][MAX];
	int(*c)[MAX] = cpy;
	printf("Read from the keyboard the elements of a 3x3 float matrix. Rearrange the columns so that the sum of each column's elements is smaller than the sum of the elements of the next column to the right.\n");
	readMatrix(v, nv, mv);
	displayMatrix(v, nv, mv);
	rearrageMatrix(v, nv, mv, c);

	return    0;
}

void  readMatrix(int(*v)[MAX], int n, int m) {
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

}

void rearrageMatrix(int(*v)[MAX], int  n, int  m, int(*c)[MAX]) {
	int mSum[MAX];
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += *(*(v + i) + j);
		}
		mSum[j] = sum;
	}


	int min = mSum[0], minLoc = 0;
	for (int i = 0; i < MAX; i++) {//min
		if (mSum[i] < min) {
			min = mSum[i];
			minLoc = i;
		}
	}

	int max = mSum[0], maxLoc = 0;
	for (int i = 0; i < MAX; i++) {//max
		if (mSum[i] > max) {
			max = mSum[i];
			maxLoc = i;
		}
	}
	int mid = mSum[0], midLoc = 0;
	for (int i = 0; i < MAX; i++) {//mid
		if (mSum[i] != min && mSum[i] != max) {
			mid = mSum[i];
			midLoc = i;
		}
	}

	int ord[] = { minLoc,midLoc,maxLoc };


	//min
	for (int i = 0; i < n; i++) {//ord
		for (int j = 0; j < m; j++) {//collum
			*(*(c + j) + i) = *(*(v + j) + ord[i]);
		}
	}
	printf("\n");
	displayMatrix(c, n, m);

}
