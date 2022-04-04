#include <iostream>
#include <time.h>
using namespace std;

int main() {

	int* a = NULL;
	int n;
	scanf_s("%d", &n);
	if (a = (int*)malloc(n * sizeof(int))) {
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &*a + i);
		}

		for (int i = 0; i < n; i++) {
			printf("%d ", *(a + i));
		}
		printf("\n");

		float* b = NULL;
		if (b = (float*)malloc(n * sizeof(int))) {
			for (int j = 0; j < n; j++) {
				*(b + j) = sqrt(*a + j);
			}

			for (int j = 0; j < n; j++) {
				printf("%f ", *(b+ j));
			}
			printf("\n");
		}

		if (b) {
			delete[]b;
		}

	}

	if (a) {
		delete[]a;
	}

}

