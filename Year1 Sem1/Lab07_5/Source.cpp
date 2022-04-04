#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool isPrime(int a);

int main() {
	int a;
	printf("Enter a value to find out the greatest prime number smaller\n");
	scanf_s("%d", &a);

	//printf("%d\d", isPrime(a));
	
	for (int i = a; i > 0; i--) {
		bool result = isPrime(i);
		if (result) {
			printf("%d\n", result);
			i = 0;
		}
	}
	


	printf("Enter a value to find out all the prime numbers smaller then it\n");
	scanf_s("%d", &a);
	for (int i = 1; i < a; i++) {
		if (isPrime(i)) {
			printf("%d\n", i);
		}
	}


	return  0;
}

bool isPrime(int a) {
	bool ok = true;
	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0) {
			ok = false;
			i = a / 2;
		}
	}
	return ok;
}

