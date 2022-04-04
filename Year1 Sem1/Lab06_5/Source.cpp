#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int convertToTwo(int a) {
	if (a == 0)
		return 0;
	else
		return (a % 2 + 10 *convertToTwo(a / 2));
}

int main() {
	int number;
	printf("Insert a number which will be convert into base 2\n");
	scanf_s("%d", &number);
	number = convertToTwo(number);
	int zeroCount = 0;
	while (number != 0){
		if (number % 10 == 0) zeroCount++;
		number /= 10;
	}
	printf("The number of zeros the binary number has is %d", zeroCount);

	return  0;
}

