#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


#define MAX 2000

int stringLength(char v[]);
char* stringChar(char v[], char a);


int main() {


	printf("Write a C/C++ application that reads from the keyboard an array of characters and displays the string obtained by eliminating the characters that appear more than once in the original array using pointers.\n");

	char *p, v[MAX],letters[30];
	int k = 0;
	letters[0] = '\0';
	cin.get(v, MAX);
	p = &v[0];
	for (int i = 0; i < stringLength(v); i++) {
		if (stringChar(letters, v[i]) == NULL) {//if found letter  for the first time
			letters[k] = v[i];
			k++; 
			letters[k] = '\0';
		}
	}
	cout << endl;
	for (int i = 0; i < stringLength(letters); i++) {
		cout << letters[i];
	}


	return  0;
}


int stringLength(char v[]) {
	int ok = 0, i = 0;
	while (ok != 1) {
		if (v[i] == '\0') {
			ok = 1;
		}
		i++;
	}
	return i;
}

char* stringChar(char v[], char a) {
	char* p = v;
	for (int i = 0; i < stringLength(v); i++) {
		if (v[i] == a) {
			return v + i;
		}
	}
	return NULL;

}