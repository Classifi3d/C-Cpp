#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

int main()
{
	int* v;
	int n, m;
	scanf_s("%d%d", &n, &m);

	
	if ((v = (int*)malloc(n*m * sizeof(int)))) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				*(v + i * n + j) = 1;
				//scanf_s("%d", v + i*n+j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", *(v+i*n+j));
			}printf("\n");
		}
	}
	else
		printf("\nAlocare nereusita !");

	if (v){
		free(v);
	}

}

