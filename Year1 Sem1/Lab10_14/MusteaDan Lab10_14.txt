#include <iostream>

using namespace std;

#define max 100

int main(){

	int A[max], B[max], C[max],n,m,k=0;
	int* a=A, * b=B, * c=C;
	int i = 0, j = 0;
	printf("Develop the algorithm able to interclass two one-dimensional arrays of int type. Use pointers.\n");
	printf("\nWrite 2 vectors with elements in an ascending order.\n");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &*(a + i));
	}

	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &*(b + i));
	}


	while (i < n && j < m){
		if (*(a+i) < *(b + j)){
			*(c + k) = *(a + i);
			k++;
			i++;
		}
		else{
			*(c + k) = *(b + j);
			k++;
			j++;
		}
	}

	if (i <= n){
		for (int p = i; p < n; p++){
			*(c + k) = *(a + p);
			k++;
		}
	}

	if (j <= m){
		for (int p = j; p < m; p++){
			*(c + k) = *(b + p);
			k++;
		}
	}

	for (int p = 0; p < k; p++) {
		printf("%d ", *(c + p));
	}


}