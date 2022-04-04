#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  100


void  readArray(int  *v, int& n);
void  creatArrayRemainder(int  *v, int  n, int  b[MAX]);
void  displayArray(int  *v, int& n);


int  main() {
	int  V[MAX], B[MAX];
	int* v = V, * b = B;
	int  n;
	printf("Reads  from  the  keyboard  n  integer  values.  The  program  will  build  another  array  containing  the  remainders  obtained  by  dividing  the  values  in  the  initial  array  to  the  number  of  the  positive  elements.\n");
	readArray(v, n);
	creatArrayRemainder(v, n, b);
	displayArray(b, n);

	return    0;
}

void  readArray(int* v, int& n) {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}
}

void  displayArray(int* v, int& n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", v[i]);
	}
}


int  findNumOfPosElements(int  *v, int  n) {
	int  num = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			num++;
		}
	}
	return  num;
}

void  creatArrayRemainder(int* v, int  n, int  b[MAX]) {
	int  num = findNumOfPosElements(v, n);
	for (int i = 0; i < n; i++) {
		b[i] = v[i] % num;
		if (b[i] < 0)  b[i] *= -1;
	}
}