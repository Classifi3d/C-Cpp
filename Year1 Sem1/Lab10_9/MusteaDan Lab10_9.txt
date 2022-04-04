
#include <iostream>

using namespace std;

#define max 100
int numOfStudents(float* p, int dim	);
int main(){
    
	float marksavg[max];
	int dim;
	float *p = marksavg;
	scanf_s("%d", &dim);
	for (int i = 0; i < dim; i++) {
		scanf_s("%f", &p[i]);
	}
	printf("%d",numOfStudents(p, dim));

}

int numOfStudents(float *p,int dim) {

	int count = 0;
	for (int i = 0; i < dim; i++) {
		if (p[i] >= 8.0) {
			count++;
		}
	}
	return count;
}