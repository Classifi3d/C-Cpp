#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int n,a;
	printf("Enter n integer numbers from the keyboard so that the program displays those that can be divided by 3.\n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		if (a % 3 == 0) {
			printf("--->%d\n", a);
		}
	}


	return  0;
}
