#include <iostream>

using namespace std;

#define max 20

void sum(int ** a, int **b,int **c,int m,int n) {
	for (int i = 0; i < m; i++) {//allocation
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j]+b[i][j];
		}
	}
}

void display(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {//allocation
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}
}


int main(){
	int m, n, ** a, ** b, ** c;
	//1st matrix
	cin >> m;
	if ((a = new int* [m])){
		cin >> n;
		for (int i = 0; i < m; i++){
			a[i] = new int[n];
			if (a[i] == 0){
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < m; i++){//allocation
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		display(a, m, n);
	}
	else
		cout << "Alocation failed!";

	//2nd matrix
	if ((b = new int* [m])) {
		for (int i = 0; i < m; i++) {
			b[i] = new int[n];
			if (b[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < m; i++) {//allocation
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		display(b, m, n);
	}
	else
		cout << "Alocation failed!";
	//3rd matrix
	if ((c = new int* [m])) {
		for (int i = 0; i < m; i++) {
			c[i] = new int[n];
			if (c[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

	}

	sum(a, b, c, m, n);
	display(c, m, n);



	if (a){
		for (int i = 0; i < m; i++)
			delete[]a[i];
		delete[]a;
	}
	if (b) {
		for (int i = 0; i < m; i++)
			delete[]b[i];
		delete[]b;
	}
	if (c) {
		for (int i = 0; i < m; i++)
			delete[]c[i];
		delete[]c;
	}
	cin.ignore();
	cin.get();
}