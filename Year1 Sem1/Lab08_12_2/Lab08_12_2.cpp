#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 100

int main()
{
	printf("Read from the a text, the programe will uppercase the first occurance of every letter in the text.\n");
	char v[MAX];
	int length=0;
	cin.get(v, MAX);
	for (int i = 0; i < MAX; i++) {
		if (v[i] == '\0') {
			length = i;
		}
	}
	int alphabetOccurrence[25] = { 0 };
	for (int i = 0; i < length; i++) {
		int ch = (int)v[i] - 64 - 32;
		if (alphabetOccurrence[ch] == 0) {
			v[i] = v[i] - 32;
			alphabetOccurrence[ch] = 1;
		}
		printf("%c", v[i]);
	}



}

