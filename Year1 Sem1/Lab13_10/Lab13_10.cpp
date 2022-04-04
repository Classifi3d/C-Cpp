/*
Nume: Mustea Dumitru Dan
Grupa: 2013
Seria: ENG
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

#define max 1000

int arrayLength(char array[max], char c);

int main() {

	char fileName1[max];
	printf("Insert the filename of the file that contains the float value\n");
	cin >> fileName1;
	//adds a ".txt" extension to the file name that was read from the keyboard
	int i = arrayLength(fileName1,'\0');
	fileName1[i] = '.';
	fileName1[i + 1] = 't';
	fileName1[i + 2] = 'x';
	fileName1[i + 3] = 't';
	fileName1[i + 4] = '\0';

	char fileName2[max];
	printf("Insert the filename of the file where the result will go\n");
	cin >> fileName2;
	//adds a ".txt" extension to the file name that was read from the keyboard
	i = arrayLength(fileName2, '\0');
	fileName2[i] = '.';
	fileName2[i + 1] = 't';
	fileName2[i + 2] = 'x';
	fileName2[i + 3] = 't';
	fileName2[i + 4] = '\0';





	FILE* fPointer1 = fopen(fileName1, "r+");
	FILE* fPointer2 = fopen(fileName2, "w+");
	char array[max];
	while (!(feof(fPointer1))) {
		fgets(array, max, fPointer1);
		if (array[0] != '-') {//if it's positive
			int num = 0;
			for (int i = 0; i < arrayLength(array,'.'); i++) {
				num *= 10;
				num += array[i]-'0';
			}
			char integ[20];
			_itoa(num, integ, 10);
			int dim=arrayLength(integ,'\0');
			integ[dim] = '\n';
			integ[dim + 1] = '\0';
			fprintf(fPointer2, integ);

		}
	}

	fclose(fPointer1);
}



int arrayLength(char array[max],char c) {//returns the length of an array
	int i = 0;
	while (array[i] != c) {
		i++;
	}
	return i;
}

