#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int n=0;
	char c;
	printf("Enter n a integer number and a single character. The program should display that character on n rows, n times in a row.\n");
	scanf_s("%d",&n);
	scanf_s(" %c", &c);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c << " ";
		}printf("\n");
	}



	return  0;
}
