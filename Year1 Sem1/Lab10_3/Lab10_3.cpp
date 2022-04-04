#include <iostream>
#include<conio.h>
using namespace std;

int main(){

	char array[100];
	//scanf_s("%s", array);

	int dim = 0;
	char chr = 'a';
	while (chr!=13) {
		chr = _getche();
		array[dim++] = chr;
	}

	printf("\n");
	if (dim > 7) {
		for (int i = 1; i <= 7; i += 2) {
			printf("%c", array[i]);
		}
	}


}

