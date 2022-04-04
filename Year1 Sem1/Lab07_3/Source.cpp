#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,result;
	int a = 4;//(a is “hard coded”) || (a se defineste in program).
	printf("Enter a value n to calcute 4 at the n-th power\n");
	scanf_s("%d", &n);
	result = 1;
	while (n > 0) {
		result *= a;
		n--;
	}
	printf("%d", result);

	return  0;
}
