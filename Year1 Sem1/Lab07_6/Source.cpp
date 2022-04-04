#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b;
	printf("Enter 2 values to find out the greatest coman divider between them\n");
	scanf_s("%d%d", &a,&b);
	while (a!=b)
	{	
		if (a > b) {
			a -= b;
		}
		else b -= a;
	}

	printf("%d", a);

	return  0;
}
