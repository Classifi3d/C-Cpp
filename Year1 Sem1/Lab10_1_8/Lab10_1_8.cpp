
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  100


void  readArray(int  *v, int& n);
float  findAvgArray(int  *v, int  n);
void  displayAboveAvgArray(int  *v, int  n);

int  main() {
	int  a[MAX];
	int* v = a;;
	int  n;
	printf("Reads  from  the  keyboard  n  integer  values.  The  program  will  find  the  average  value  and  diplay  the  values  that  are  greater  than  the  average.\n");
	readArray(v, n);
	//printf("%f",  findAvgArray(v,  n));
	displayAboveAvgArray(v, n);



	return    0;
}

void  readArray(int* v, int& n) {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}
}

float  findAvgArray(int* v, int  n) {
	int  avg = 0;
	for (int i = 0; i < n; i++) {
		avg += v[i];
	}
	return  (float)avg / (float)n;
}

void  displayAboveAvgArray(int* v, int  n) {
	printf("\n");
	float  avg = findAvgArray(v, n);
	for (int i = 0; i < n; i++) {
		if (float(v[i]) > avg) {
			printf("%.0f  ", (float)v[i]);
		}

	}printf("\n");
}