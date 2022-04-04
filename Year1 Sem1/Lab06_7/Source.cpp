#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int x, y;
	printf("Insert 2 values:\n");
	scanf_s("%d%d", &x, &y);
	int a = x + y;
	int b = x - y;
	int c = y - x;
	int d = x * y;
	int e = x / y;
	int f = y / x;
	int min=x;
	(a < b && a < c && a < d && a < e && a < f) ? min = a:0;
	(b < a && b < c && b < d && b < e && b < f) ? min = b : 0;
	(c < a && c < b && c < d && c < e && c < f) ? min = c : 0;
	(d < a && d < b && d < c && d < e && d < f) ? min = d : 0;
	(e < a && e < b && e < c && e < d && e < f) ? min = e : 0;
	(f < a && f < b && f < c && f < d && f < e) ? min = f : 0;
	printf("The smallest value is %d", min);

	return  0;
}

