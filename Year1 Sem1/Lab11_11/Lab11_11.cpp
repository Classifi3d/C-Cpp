#include <iostream>

using namespace std;

#define max 40

int main(){

	char s1[] = "Sentence 1";
	char s2[] = "Sentence 2";
	char s3[] = "Sentence 3";
	char s4[] = "Sentence 4";

	char* p[max];
	if (*p = (char*)malloc(max * sizeof(char))) {
		p[0] = _strdup(s1);
		p[1] = _strdup(s2);
		p[2] = _strdup(s3);
		p[3] = _strdup(s4);
	}

	for (int i = 0; i < 4; i += 2) {
		printf("%s\n", *(p + i));
	}

}
