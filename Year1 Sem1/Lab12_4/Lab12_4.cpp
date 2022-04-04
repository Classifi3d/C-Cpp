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


int main(){
	int n;
	personal_data a[20];
	cin >> n;
	for (int i = 0; i < n; i++) {//num of employees
		cin >> a[i].name >> a[i].surname >> a[i].occupation >> a[i].code >> a[i].department;
		cin >> a[i].birth_date.day >> a[i].birth_date.month >> a[i].birth_date.year;
		cin >> a[i].empl_date.day >> a[i].empl_date.month >> a[i].empl_date.year;
	}

	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].occupation,"engineer")==0) {
			cout<<"name: "<< a[i].name <<" surename: "<< a[i].surname <<" occupation: "<< a[i].occupation <<" code: "<< a[i].code <<" department: "<< a[i].department;
			cout<<"birthday day "<< a[i].birth_date.day <<" month "<< a[i].birth_date.month <<" year "<< a[i].birth_date.year;
			cout<<"employment day "<< a[i].empl_date.day <<" month "<< a[i].empl_date.month <<" year "<< a[i].empl_date.year;
		}
	}
}
