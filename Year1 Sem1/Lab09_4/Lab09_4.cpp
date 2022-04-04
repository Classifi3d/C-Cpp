#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


#define MAX 20

void oddElimination(int* p, int &LENGTH);

int main()
{
	printf("Write a C/C++ application that generates 20 random numbers, each smaller than 50 (use srand(), rand() and % operator). Write a function that eliminates the odd elements from the one dimensional array (using pointers). Display both the initial and the final array in the main function.\n");
	int v[MAX];
	int* p=v;

	for (int i = 0; i < MAX; i++) {
		p[i] = rand() % 50;
	}

	for (int i = 0; i < MAX; i++) {
		printf_s("%d ", p[i]);
	}printf_s("\n");

	int length = 0;
	oddElimination(v, length);
	p = v;
	
	
	for (int i = 0; i < length; i++) {
		printf_s("%d ", p[i]);
	}printf_s("\n");

}

void oddElimination(int *p,int &LENGTH) {
	int length = MAX;
	for (int i = 0; i < length; i++) {
		if (p[i] % 2 == 1) {
			for (int j = i; j <	length-1; j++) {
				p[j] = p[j + 1];
			}
			length--;
			i--;
		}
	}
	LENGTH = length;
}