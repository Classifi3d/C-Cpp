#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


#define MAX 2000

void ReadArray(int* v, int dim);
int ScalarProduct(int* p1, int* p2, int n, int m);

int main()
{
	printf("Write a C/C++ application that reads from the keyboard two one dimensional arrays of integers and displays the scalar product of the two arrays. Use a function that reads the elements from the keyboard and another function that calculates the scalar product, using pointers in both functions. Reading and displaying the arrays’ elements should be done in the main function.\n");
	int n, m;
	scanf_s("%d%d",&n,&m);
	int a[MAX] = { 0 }, b[MAX] = { 0 };
	int *p1, *p2;
	p1 = a;
	p2 = b;
	ReadArray(p1, n);
	ReadArray(p2, m);
	printf("%d",ScalarProduct(p1, p2, n, m));



}


void ReadArray(int* v, int dim) {
	for (int i = 0; i < dim; i++) {
		scanf_s("%d", &v[i]);
	}
}

int ScalarProduct(int* p1, int* p2, int n, int m) {

	int sum = 0, dim = 0;
	if (n > m) dim = n;
	else dim = m;

	for (int i = 0; i < dim; i++) {
		sum += p1[i] * p2[i];
	}

	return sum;
}
