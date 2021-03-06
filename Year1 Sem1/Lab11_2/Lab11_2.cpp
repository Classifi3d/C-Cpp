#include <iostream>

using namespace std;

#define max 100

void read(float* distribution) {
	for (int i = 0; i < 15; i++) {
		scanf_s("%f", &*(distribution + i));
	}
}

void pointerAllocation(float dis[max], float* p[max],int &dim) {
	int k = 0;
	for (int i = 0; i < 15; i+=3) {
		//*(p + k) = &*(dis + i);
		p[k] = &dis[i];
		k++;
	}
	dim = k;
	
	for (int i = 0; i < k; i++) {
		cout << *p[i] << " ";
	}

}

float salesCity(float p[max],int index) {
	//cout << (&p + index);
	float sum = p[index] + p[index + 1] + p[index + 2];
	return sum;
}


int main(){
	float distribution[max];
	float* p[max];
	float *v = distribution;
	int dim = 0;
	read(v);
	pointerAllocation(v, p, dim);
	cout << endl;
	for (int i = 0; i < dim; i++) {
		cout<<salesCity(v,i)<<"-";
	}


}

