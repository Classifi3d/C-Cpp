
#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  100


void  readArray(char  *v, int& n);
void  displayArray(char  *v, int& n);
void  ReverseEvenPos(char  *v, int  n, char  *b, int& k);

int  main() {
	char  V[MAX], B[MAX];
	char* v = V, * b = B;
	int  n, k = 0;
	printf("Read  from  the  keyboard  an  array  of  characters.  The  program  will  display  the  elements  from  the  even  positions  of  the  reverted  array.\n");
	readArray(v, n);
	displayArray(v, n);
	printf("\n");
	ReverseEvenPos(v, n, b, k);
	displayArray(b, k);

	return    0;
}

void  readArray(char  *v, int& n) {
	cin.get(v, MAX);
	n = 0;
	for (int i = 0; i < MAX; i++) {
		if (v[i] == '\0') {
			n = i;
			i = MAX;
		}
	}
}

void  displayArray(char *v, int& n) {
	for (int i = 0; i < n; i++) {
		printf("%c", v[i]);
	}
}

void  ReverseEvenPos(char  *v, int  n, char  *b, int& k) {
	k = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i % 2 == 0) {
			b[k++] = v[i];
		}

	}
}