#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

#define max 1000


void creatFile(char fileName[max-4]);
void writeFile(char fileName[max]);
int fileExists(char fileName[max]);
int arrayLength(char array[max]);

int main(){

	char fileName[max];
	printf("Insert a filename\n");
	//scanf_s("%s", fileName);
	cin >> fileName;

	//adds a ".txt" extension to the file name that was read from the keyboard
	int i = arrayLength(fileName);
	fileName[i] = '.';
	fileName[i + 1] = 't';
	fileName[i + 2] = 'x';
	fileName[i + 3] = 't';
	fileName[i + 4] = '\0';



	if (fileExists(fileName) == NULL) {
		printf("File does not exist\n");
		creatFile(fileName);
	}
	else {
		printf("File does exist\n");
	}


	FILE* fPointer = fopen(fileName, "r");
	char array[max];
	while (!(feof(fPointer))) {
		fgets(array, max, fPointer);
		for (int i = 0; i < arrayLength(array); i++) {
			if (array[i] >= '0' && array[i] <= '9') {
				printf("%c", array[i]);
			}
		}
		//puts(array);
	}

	fclose(fPointer);
}

void creatFile(char fileName[max-4]) {//creats file if it didn't exist
	FILE* fPointer = fopen(fileName, "w");
	fclose(fPointer);

	writeFile(fileName);

}

void writeFile(char fileName[max]) {//writes in the file that was newly created
	int numOfLines = 0;
	char array[max];
	printf("Insert the num of lines you wish to write to file.\n");
	scanf_s("%d", &numOfLines);
	
	FILE* fPointer = fopen(fileName, "w");
	fprintf(fPointer,"");

	while (numOfLines > 0) {
		//scanf_s("%s", array);
		cin >> array;

		//adding endline to the string that was read
		int i=arrayLength(array);
		if (numOfLines > 1) {//avoids the program from printing the last line twice
			array[i] = '\n';
			array[i + 1] = '\0';
		}

		fprintf(fPointer, array);
		numOfLines--;
	}
	
	fclose(fPointer);
}

int arrayLength(char array[max]) {//returns the length of an array
	int i = 0;
	while (array[i] != '\0') {
		i++;
	}
	return i;
}


int fileExists(char fileName[max]) {//checks if the file exists
	if (fopen(fileName, "r") == NULL){

		return 0;
	}

	return 1;
}