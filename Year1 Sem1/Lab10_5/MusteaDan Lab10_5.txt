#include <iostream>
#include<conio.h>
#include <time.h>
using namespace std;

int main() {

	char msg1[100]="value too small";
	char msg2[100] = "value too big";
	char msg3[100] = "correct value";
	char* p1 = msg1, * p2 = msg2, * p3 = msg3;
	srand(time(0));

	int pass = rand() % 100;
	int guess;
	do {
		scanf_s("%d", &guess);

		if (pass > guess) {
			printf("%s", p1);
		}
		else if (pass < guess) {
			printf("%s", p2);
		}

	} while (pass!=guess);

	printf("%s", p3);

}

