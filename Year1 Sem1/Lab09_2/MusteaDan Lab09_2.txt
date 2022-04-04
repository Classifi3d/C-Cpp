#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


#define MAX 2000

int stringLength(char* v);
char* stringChar(char* v, char a);


int main()
{
	printf("Write a C/C++ application that reads from the keyboard two arrays of characters and displays the total number of individual characters (the number of characters that are in the first array and do not exist in the second one + the number of characters that are in the second array and do not exist in the first one). Use pointers for accessing the arrays of elements.\n");
	char A[MAX], B[MAX];
	char alphabeth[] = "abcdefghijklmnopqrstuvwxyz";
	char charA[30], charB[30];

	char* a = A;
	char* b = B;
	char* alpha = alphabeth;
	char* chara = charA;
	int dimCharA=0;
	char* charb = charB;
	int dimCharB = 0;

	cin.get(a,MAX);
	cin.get();
	cin.get(b,MAX);
	cin.get();

	for (int i = 0; i < stringLength(alpha)-1; i++) {
		if (!(NULL == stringChar(a, alpha[i]))) {
			chara[dimCharA++] = alpha[i];
		}
	}
	chara[dimCharA] = '\0';


	for (int i = 0; i < stringLength(alpha) - 1; i++) {
		if (!(NULL == stringChar(b, alpha[i]))) {
			charb[dimCharB++] = alpha[i];
		}
	}
	charb[dimCharB] = '\0';

	//cout << chara << endl << charb<<endl;
	printf("The characters that are in the first word but not in the secound one are: ");
	for (int i = 0; i < stringLength(chara); i++) {
		if (!(stringChar(charb, chara[i]) != NULL)) printf("%c",chara[i]);

	}

	printf("The characters that are in the secound word but not in the first one are: ");
	for (int i = 0; i < stringLength(charb); i++) {
		if (!(stringChar(chara, charb[i]) != NULL)) printf("%c", charb[i]);

	}

	return 0;
}


int stringLength(char* v) {
	int ok = 0, i = 0;
	while (ok != 1) {
		if (v[i] == '\0') {
			ok = 1;
		}
		i++;
	}
	return i;
}

char* stringChar(char* v, char a) {
	for (int i = 0; i < stringLength(v); i++) {
		if (v[i] == a) {
			return v + i;
		}
	}
	return NULL;

}
