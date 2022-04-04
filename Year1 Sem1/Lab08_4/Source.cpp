#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 10

void read(char v[]);
int dimension(char v[]);
int compare(char v[], char password[]);

int main() {
	char password[MAX] ="password";
	char v[MAX];
	int failCounter = 0;;
	//printf("Read from the keyboard a dimension then an array with integer as elements,Define and implement a function that receives the array as parameter and then displays its elements, ordered increasingly.\n");


	int ok = 0;
	do {
		read(v);
		if(1==compare(v, password)){
			ok = 1;
		}
		else {
			failCounter++;
		}
		

	} while (ok != 1);

	printf("%d", failCounter);

	return  0;
}

int compare(char v[], char password[]) {
	for (int i = 0; i < dimension(v); i++) {
		if (v[i] != password[i]) {
			return 0;
		}
	}
	return 1;
}


int dimension(char v[]) {
	for (int i = 0; i < MAX; i++) {
		if (v[i] == '\0') {
			return i+1;
		}
	}


}

void read(char v[]) {

	cin.get(v, MAX);
	cin.get();

}