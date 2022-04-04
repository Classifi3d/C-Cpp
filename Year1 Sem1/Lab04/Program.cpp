#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
//#include <stdio.h>
#include <cmath>

#include <iostream>
using namespace std;


int Problem1() {
	//Write a program that determines the average value of 3 non-integer numbers.
	printf("\n Determines average value of 3 non-integer numbers \nThe numbers are:");
	float a, b, c, avg;
	scanf_s("%f %f %f", &a, &b, &c);
	avg = (a + b + c) / 3;
	printf("%f",avg);

	return 0;
}

int Problem2() {
	//Write a program that determines the geometric average of 2 integer numbers.
	printf("\n Determines the geometric average of 2 integer numbers \nThe numbers are:");
	int a, b;
	float med;
	scanf_s("%d %d", &a, &b);
	med = a + b;
	//med = sqrt(med);
	printf("%f", sqrt(med));

	return 0;
}

int Problem3() {
	//Write a C/C++ application that defines an integer variable, initialized with several constant values. Display its value by overloading the << operator and by using the cout object.	
	int element = 5;
	cout << "The constant is " << element;


	return 0;
}

int Problem4() {
	//Define an array of characters that will be displayed using cout. Display other character arrays and use escape sequences. Verify the usage of the whitespaces.
	char a[100]="The array defined";
	cout << a;
	char b[100] ="\nThe fox\t\tjumped over the fence\'s gate\?";
	printf("%s", &b);

	return 0;
}

int Problem5() {
	//Write a program that defines 3 integer values. Calculate and display their weighted sum, the weights being represented as positive values smaller than 1 that add up to 1.
	printf("Write 3 values and their weight(which is less then 1 and all 3 weights add up to 1\n");
	float aw, bw, cw, a, b, c;
	scanf_s("%f %f %f %f %f %f", &a, &aw, &b, &bw, &c, &cw);
	printf("%f", a * aw + b * bw + c * bw);
	return 0;
}

#define PI 3.1415
#define YEAR 2019
#define NAME "Mustea Dan"

int Problem6() {
	//Define several symbolic constants of different types (integer numbers, real numbers, arrays of characters). Display their values using cout and the << operator.
	cout << "It's the year "<<YEAR<<" and "<<NAME<<"\'s favourite number is "<<PI<<".";

	return 0;
}

int Problem7() {
	//Define 3 real numbers named a, b and c. Display the value of 1/a + 1/b + 1/c. Display the same result considering as input integer numbers.
	float a, b, c,specialSum;
	printf_s("Type 3 real numbers:");
	scanf_s("%f %f %f", &a, &b, &c);
	specialSum = 1 / a + 1 / b + 1 / c;
	printf_s("%f \n", specialSum);
	printf_s("%d / 1000000 \n", int(specialSum * 1000000));
	
	return 0;
}

int main() {
	printf("Choose which problem you want to be displayed:\n1. Write a program that determines the average value of 3 non-integer numbers.\n2. Write a program that determines the geometric average of 2 integer numbers.\n3. Write a C/C++ application that defines an integer variable, initialized with several constant values. Display its value by overloading the << operator and by using the cout object.\n4. Define an array of characters that will be displayed using cout. Display other character arrays and use escape sequences. Verify the usage of the whitespaces.\n5. Write a program that defines 3 integer values. Calculate and display their weighted sum, the weights being represented as positive values smaller than 1 that add up to 1.\n6. Define several symbolic constants of different types (integer numbers, real numbers, arrays of characters). Display their values using cout and the << operator.\n7. Define 3 real numbers named a, b and c. Display the value of 1/a + 1/b + 1/c. Display the same result considering as input integer numbers.\n8. Exit the program\n");

	int problem;
	//scanf_s("%d", problem);
	cin >> problem;
	switch (problem) {
	case 1:
		Problem1();
		break;
	case 2:
		Problem2();
		break;
	case 3:
		Problem3();
		break;
	case 4:
		Problem4();
		break;
	case 5:
		Problem5();
		break;
	case 6:
		Problem6();
		break;
	case 7:
		Problem7();
		break;
	case 8:
		cout << "Exit";
		break;

	}
	return 0;
}