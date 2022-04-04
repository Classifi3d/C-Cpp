#include <iostream>
#include <cstring>

using namespace std;

#define max 256

int main(){

	struct a_structure {
		int d;
		char c;
		char s[max];
	};



	a_structure** pa_structure = NULL;
	int n;
	n = 1;

	if (pa_structure = new a_structure * [n]) {
		for (int i = 0; i < n; i++) {
			pa_structure[i] = new a_structure;
			if (pa_structure[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> pa_structure[i]->d;
			cin >> pa_structure[i]->c;
			cin >> pa_structure[i]->s;

		}

		cout << endl;
		cout << pa_structure << endl;
		cout << (*pa_structure)->d << endl;
		cout << (*pa_structure)->c << endl;
		cout << (*pa_structure)->s << endl;
	}

	if (pa_structure) {
		for (int i = 0; i < n; i++)
			delete[]pa_structure[i];
		delete[]pa_structure;
	}


}
