#include <iostream>

using namespace std;

#define max 100

void dir_sort(float* p, int n) {
	*p = 0;
	for (int i = 0; i < n; i++) {//num of elm
		float x;
		scanf_s("%f", &x);
		int j = i - 1;
		while (j >= 0 && *(p + j) > x) {//move forward if greater then num read
			*(p + j + 1) = *(p + j);
			j = j - 1;
		}
		*(p + j + 1) = x;

		/*
		//optional display with every new element
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		*/
	}
	for (int i = 0; i < n; i++) {
		printf("%.2f ", *(p + i));
	}
}

int main(){
	int n;
	scanf_s("%d", &n);
	float v[max];
	float* p = v;
	dir_sort(p, n);

}

