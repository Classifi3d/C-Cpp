#define  _CRT_SECURE_NO_WARNINGS

#include  <iostream>
#include  <memory.h>
#include  <malloc.h>

using namespace std;

#define max 64

void  Read(int  a[max], int  &n);
int  SumNegative(int  a[max], int  n);

int  main() {
	int  n = 0, a[max];
	Read(a, n);

	if (a) {
		//delete[]a;
		free(a);
	}
}

void  Read(int  a[max], int  &n) {

	scanf_s("%d", &n);
	if (a = (int*)malloc(n * sizeof(int) ) ){
		for (int i = 0; i < n; i++){
			scanf("%d", a + i);
		}

		for (int i = 0; i < n; i++) {
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	printf("\n%d", SumNegative(a, n));

}

int  SumNegative(int  a[max], int  n){
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (a[i] < 0) {
			sum += a[i];
		}
	}
	return sum;
}