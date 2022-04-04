#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>
#include <cmath>

int main() {

	int a,b,c;
	printf("Introdu cele 3 laturi: ");
	scanf_s("%d%d%d", &a,&b,&c);
	float p, s,A,B,C;
	p = (a + b + c);
	p = p / 2;
	printf("%f\n", p);

	p = p * a * b * c;
	printf("%f\n", p);
	s = sqrt(p);
	printf("Aria triunghiului este %.2f",s);


	return 0;
}