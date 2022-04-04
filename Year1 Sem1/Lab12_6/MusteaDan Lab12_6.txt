#include <iostream>
#include <cstring>

using namespace std;


#define max 100

struct stud {
	char name[max];
	char surename[max];
	int mark;
};


stud HighestMark(stud (*student),int maxstd) {
	int highestMark = 0;
	stud x;
	for (int i = 0; i < maxstd; i++) {
		if (student[i].mark > highestMark) {
			highestMark = student[i].mark;
			x.mark = student[i].mark;
			strcpy_s(x.name,student[i].name);
			strcpy_s(x.surename, student[i].surename);
		}
	}
	return x;
}


int main(){



	int maxstd;
	cin>>maxstd;

	stud* student = NULL;
	if (student = (stud*)malloc(maxstd * sizeof(stud))) {
		for (int i = 0; i < maxstd; i++) {
			cin >> student[i].name;
			cin >> student[i].surename;
			cin >> student[i].mark;
		}
		stud x;
		x=HighestMark(student, maxstd);
		cout << x.mark << " " << x.name << " " << x.surename << endl;
	}
	if (student) {
		delete[]student;
	}

}