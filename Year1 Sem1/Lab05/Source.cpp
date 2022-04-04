#define  _CRT_SECURE_NO_WARNINGS
#include  <cstdio>
#include  <conio.h>
#include  <cmath>

float  parallelResistors(float  R1, float  R2);
float  seriesResistors(float  R1, float  R2);
float  parallelCapacitors(float  C1, float  C2);
float  seriesCapacitors(float  C1, float  C2);
float  triangleHypotenuse(float  Cath1, float  Cath2);
float  ecuation(float  a, float  b);

int  main() {
	/*
	float  R1,  R2;
	scanf_s("%f  %f",&R1,&R2);
	printf_s("%.3f  \n",  parallelResistors(R1,  R2));
	printf_s("%.3f  \n",  seriesResistors(R1,  R2));

	float  C1,  C2;
	scanf_s("%f  %f",  &C1,  &C2);
	printf_s("%-.4f  \n",  parallelCapacitors(C1,  C2));
	printf_s("%.4f  \n",  seriesCapacitors(C1,  C2));

	float  Cath1,  Cath2;
	scanf_s("%f  %f",  &Cath1,  &Cath2);
	printf_s("%f  \n",triangleHypotenuse(Cath1,  Cath2));
	*/
	float  a, b;
	scanf_s("%f  %f", &a, &b);
	printf_s("%f  \n", ecuation(a, b));

	return  0;
}

float  parallelResistors(float  R1, float  R2) {
	float  par = (R1 * R2) / (R1 + R2);

	return  par;
}

float  seriesResistors(float  R1, float  R2) {

	return  R1 + R2;
}

float  parallelCapacitors(float  C1, float  C2) {
	return  C1 + C2;
}

float  seriesCapacitors(float  C1, float  C2) {
	return  1 / ((1 / C1) + (1 / C2));
}

float  triangleHypotenuse(float  Cath1, float  Cath2) {
	return  sqrt(Cath1 * Cath1 + Cath2 * Cath2);
}

float  ecuation(float  a, float  b) {
	return  (-b) / a;
}