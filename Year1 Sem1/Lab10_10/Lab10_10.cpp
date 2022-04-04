#include <iostream>
using namespace std;

#define max 100
void Read(int* p, int& dim);
float Mean(int* p, int dim);
void Subtract(int* p, int dim, int* v);
void Display(int* p, int dim);

int main(){
	int A[max],B[max],dim;
	int* a=A, * b=B;
	Read(a, dim);
	Subtract(a, dim, b);
	Display(a, dim);
	Display(b, dim);

}

void Read(int* p,int &dim) {
	scanf_s("%d", &dim);
	for (int i = 0; i < dim; i++) {
		scanf_s("%d", &(*(p + i)));
	}

}

float Mean(int* p, int dim) {
	float avg = 0;
	for (int i = 0; i < dim; i++) {
		avg += *(p + i);
	}
	return avg / dim;
}

void Subtract(int* p, int dim,int *v) {
	int mean = Mean(p, dim);
	printf("The mean is: %d\n", mean);
	for (int i = 0; i < dim; i++) {
		*(v + i) = *(p + i) - mean;
	}
}

void Display(int* p, int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%d ", *(p + i));
	}
	printf("\n");
}