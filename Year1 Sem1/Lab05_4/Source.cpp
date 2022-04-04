#define  _CRT_SECURE_NO_WARNINGS
#include  <cstdio>
#include  <conio.h>
#include  <cmath>

float  parallelResistors(float  R1, float  R2);
float  parallelCapacitors_seriesResistors(float  C1, float  C2);
float  seriesCapacitors(float  C1, float  C2);



int  main() {
	float  R1,  R2;
	printf("Insert the values for 2 resistors\n");
	scanf_s("%f  %f",&R1,&R2);
	printf_s("%.3f  \n",  parallelResistors(R1,  R2));
	printf_s("%.3f  \n", parallelCapacitors_seriesResistors(R1,  R2));

	printf("\nInsert the values for 2 capacitors\n");
	float  C1,  C2;
	scanf_s("%f  %f",  &C1,  &C2);
	printf_s("%-.4f  \n", parallelCapacitors_seriesResistors(C1,  C2));
	printf_s("%.4f  \n",  seriesCapacitors(C1,  C2));

	return  0;
}

float  parallelResistors(float  R1, float  R2) {
	float  par = (R1 * R2) / (R1 + R2);

	return  par;
}

float  parallelCapacitors_seriesResistors(float  C1, float  C2) {
	return  C1 + C2;
}

float  seriesCapacitors(float  C1, float  C2) {
	return  1 / ((1 / C1) + (1 / C2));
}
