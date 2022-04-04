#include <iostream>

using namespace std;

int main(){
	int m, n, ** a;

	//1st matrix
	cin >> m;//m & n < 7
	if ((a = new int* [m])) {
		cin >> n;//m & n < 7
		for (int i = 0; i < m; i++) {
			a[i] = new int[n];
			if (a[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < m; i++) {//allocation
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		if ((m == n) && (m == 3)) {//Saruss's method can only be used on a 3x3 matrix even thought the requirement said it was to be used on m==n matrices
			int x = 0, y = 0;
			for (int i = 0; i < 3; i++)
			{
				x = x + a[0][i] * a[1][(i + 1) % 3] * a[2][(i + 2) % 3];
				y = y + a[2][i] * a[1][(i + 1) % 3] * a[0][(i + 2) % 3];
			}
			printf("val of determinant is: %d\n", (x - y));
		}
	}
	else
		cout << "Alocation failed!";

	if (a) {
		for (int i = 0; i < m; i++)
			delete[]a[i];
		delete[]a;
	}
	

}
