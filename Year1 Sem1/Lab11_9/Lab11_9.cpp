#include <iostream>
#include <conio.h>

using namespace std;

#define maxwordlength 100
#define maxwordnumber 1000

int main()
{
	int m, n;
	char** a;
	//1st matrix
	cin >> m;
	if ((a = new char* [m])) {
		n = maxwordlength;
		for (int i = 0; i < m; i++) {
			a[i] = new char[n];
			if (a[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}


	}
	else
		cout << "Alocation failed!";


	char *concat;
	if (concat = (char*)malloc(n * sizeof(char))) {

		int k = 0;
		for (int i = 0; i < m; i++) {
			int dim = 0;
			char chr = 'a';
			while (chr != 13) {
				chr = _getche();
				a[i][dim++] = chr;
				concat[k++] = chr;
			}
			k--;
			printf("\n");
			for (int i = 0; i < k; i++) {
				printf("%c", concat[i]);
			}		printf("\n");
		}
	}

	if (concat)
		free(concat);
	if (a) {
		for (int i = 0; i < m; i++)
			delete[]a[i];
		delete[]a;
	}

}
