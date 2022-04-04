#define  _CRT_SECURE_NO_WARNINGS
#include  <cstdio>
#include  <conio.h>

#define PI 3.14159

int main() {
	float radious;
	printf_s("Type the radious of the circle: ");
	scanf_s("%f", &radious);

	printf("The area of the circle is %.3f", radious * radious * PI);
	printf("The length of the circle is %.3f",  2 * PI * radious);

	return  0;
}

