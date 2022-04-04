#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int main() {
	int a,b,res=0;
	printf("Enter two values to find out the product of 2 integer numbers\n");
	scanf_s("%d%d", &a,&b);

	for (int i = 0; i < a; i++) {
		res += b;
	}
	printf("%d", res);


	return  0;
}
