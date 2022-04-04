#include <iostream>
#include <time.h>
using namespace std;

#define max 10000

int main(){
	srand(time(NULL));
	int num[101] = { 0 };
	int *a=NULL;

	if (a = (int*)malloc(max * sizeof(int))) {
		for (int i = 0; i < max; i++) {
			a[i] = rand() % 100 + 1;
		}

		for (int i = 0; i < max; i++) {
			num[a[i]]++;
		}

		for (int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){
				if (num[j] > num[i]){
					int aux = num[i];
					num[i] = num[j];
					num[j] = aux;
				}
			}
		}

		for (int i = 100; i > 90; i--) {
			printf("%d - %d\n", a[i], num[i]);
		}

	}

	if (a) {
		delete[]a;
	}
}

