#include <iostream>

using namespace std;

#define max 20


void Read(int(*mat)[max], int& n);
void Interchange(int(*mat)[max], int n, int l1, int l2);
void Display(int(*mat)[max], int n, int l1, int l2);

int main() {

	int a[max][max], b[max][max], n;
	int(*m)[max] = a;
	int l1=0, l2=0;

	printf("Read the dimension of the matrix then the elements of it.\n");
	scanf_s("%d", &n);
	Read(m, n);
	printf("read the position of the 2 rows that will be switched.\n");
	scanf_s("%d%d", &l1, &l2);
	Display(m, n, l1, l2);

}


void Read(int(*mat)[max], int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &(*(*(mat + i) + j)));
		}
	}
}

void Interchange(int(*mat)[max], int n, int l1, int l2) {
	int  count = 0;
	int aux;

	for (int i = 0; i < n; i++) {
		aux = *(*(mat + i) + l1);
		*(*(mat + i) + l1) = *(*(mat + i) + l2);
		*(*(mat + i) + l2) = aux;
	}

}

void Display(int(*mat)[max], int n, int l1, int l2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", (*(*(mat + i) + j)));
		}printf("\n");
	}
	printf("\n");
	Interchange(mat, n, l1, l2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", (*(*(mat + i) + j)));
		}printf("\n");
	}
}
