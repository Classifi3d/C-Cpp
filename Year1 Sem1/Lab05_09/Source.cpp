#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float v1, v2,distance,time;
	printf("Write the speed of 2 vehicels in Km/H ");
	scanf_s("%f%f", &v1, &v2);
	distance = v1 + v2;
	time = 100 / distance;
	printf("The time when both vehicels meet is: %.0f Minutes", time*60);

	return 0;
}
