#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a, odd[20] = { 0 },dim=0;
	printf("Enter a value to determin what odd figures it has\n");
	scanf_s("%d", &a);

	while (a > 0) {
		if (a % 2 != 0) {
			odd[dim++] = a % 10;
		}
		a /= 10;
	}

	for(int i=0;i<dim;i++)
		printf("%d\n", odd[i]);


	return  0;
}
