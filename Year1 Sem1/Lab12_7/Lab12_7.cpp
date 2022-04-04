#include <iostream>
#include <cstring>

using namespace std;


#define max 100

struct stud {
	char name[max];
	char surename[max];
	char gender;
};


int main() {

	int maxstd;
	cin >> maxstd;

	stud* student = NULL;
	if (student = (stud*)malloc(maxstd * sizeof(stud))) {
		for (int i = 0; i < maxstd; i++) {
			cin >> student[i].name;
			cin >> student[i].surename;
			cin >> student[i].gender;
		}

		int femCount = 0;
		for (int i = 0; i < maxstd; i++) {
			if (student[i].gender == 'f') {
				femCount++;
			}
		}
		cout << femCount;
	}

	if (student) {
		free(student);
	}

}