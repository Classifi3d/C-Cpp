#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

#define max 100


int compareFunc(const void* a, const void* b) {
	return ( *(int*)a - *(int*)b );
}

int main(){
	printf("Order in increasing mode a one-dimensional array of integer type using qsort() from stdlib.h. Use the same algorithm for float numbers and a decreasing order.\n");

	srand(time(NULL));
	int n = rand() % 100 + 1;
	float A[max];
	float* a = A;
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 10000;
	}

	for (int i = 0; i < n; i++) {
		printf("%f ", *(a + i));
	}printf("\n\n");

	qsort(a, n,sizeof(int),compareFunc);

	for (int i = 0; i < n; i++) {
		printf("%f ",*(a + i));
	}


}
