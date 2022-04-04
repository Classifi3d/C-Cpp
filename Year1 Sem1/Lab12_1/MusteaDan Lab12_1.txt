#include <iostream>

using namespace std;

#define max 100




struct student {
	char name[max];
	char surename[max];
	char country[max];
	int group;
	int birth_year;
};




int main(){
	
	student a[max];
	int dim = -1;

	do {
		dim++;
		cin >> a[dim].name >> a[dim].surename >> a[dim].country >> a[dim].group >> a[dim].birth_year;
		cout << "element introdus!" << endl;
	} while (strcmp(a[dim].name,"AAA")!=0);
	cout << "exit";

	int group,stud_count=0;
	cout << "insert the group: ";
	cin >> group;

	for (int i = 0; i <= dim; i++) {
		if (a[i].group == group) {
			if (strcmp(a[dim].country, "romania") == 0) {
				stud_count++;
			}
		}
	}
	cout << stud_count << endl;
}
