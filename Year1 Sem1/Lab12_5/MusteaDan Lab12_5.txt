#include <iostream>
#include <cstring>
using namespace std;

#define max 100

struct 	data_calend {
	int day;
	int month;
	int year;
};

struct personal_data {
	char name[max];
	char surname[max];
	char occupation[max];
	int code;
	int department;
	data_calend birth_date;
	data_calend empl_date;
};


int main() {
	int n;
	personal_data a[20];
	cin >> n;
	for (int i = 0; i < n; i++) {//num of employees
		cin >> a[i].name >> a[i].surname >> a[i].occupation >> a[i].code >> a[i].department;
		cin >> a[i].birth_date.day >> a[i].birth_date.month >> a[i].birth_date.year;
		cin >> a[i].empl_date.day >> a[i].empl_date.month >> a[i].empl_date.year;
		cout << "Entered succesfully!"<<endl;
	}

	int codeOrder[20];
	for (int i = 0; i < n; i++) {
		codeOrder[i] = a[i].code;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (codeOrder[j] > codeOrder[j + 1]) {
				int aux = codeOrder[j];
				codeOrder[j] = codeOrder[j + 1];
				codeOrder[j + 1] = aux;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (codeOrder[i] == a[j].code) {
				cout << "name: " << a[j].name << " surename: " << a[j].surname << " occupation: " << a[j].occupation << " code: " << a[j].code << " department: " << a[j].department<<endl;
				cout << "birthday day " << a[j].birth_date.day << " month " << a[j].birth_date.month << " year " << a[j].birth_date.year << endl;
				cout << "employment day " << a[j].empl_date.day << " month " << a[j].empl_date.month << " year " << a[j].empl_date.year << endl;

			}
		}

	}

	

	int emplymentOrder[20];
	for (int i = 0; i < n; i++) {
		emplymentOrder[i] = a[i].empl_date.year*10000+ a[i].empl_date.month*100+ a[i].empl_date.day;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (emplymentOrder[j] > emplymentOrder[j + 1]) {
				int aux = emplymentOrder[j];
				emplymentOrder[j] = emplymentOrder[j + 1];
				emplymentOrder[j + 1] = aux;
			}
		}
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (emplymentOrder[i] == a[j].empl_date.year * 10000 + a[j].empl_date.month * 100 + a[j].empl_date.day) {
				cout << "name: " << a[j].name << " surename: " << a[j].surname << " occupation: " << a[j].occupation << " code: " << a[j].code << " department: " << a[j].department << endl;
				cout << "birthday day " << a[j].birth_date.day << " month " << a[j].birth_date.month << " year " << a[j].birth_date.year << endl;
				cout << "employment day " << a[j].empl_date.day << " month " << a[j].empl_date.month << " year " << a[j].empl_date.year << endl;
			}
		}
	}
	
}
