#include <iostream>

using namespace std;

#define max 100

struct product {
	char name[max];
	int price;
	int quantity;

};

int main()
{
	product **p=NULL;
	int n;
	cin >> n;
	int maxstockvalue = 0;

	if (p = new product * [n]) {
		for (int i = 0; i < n; i++) {
			p[i] = new product;
			if (p[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> p[i]->name;
			cin >> p[i]->price;
			cin >> p[i]->quantity;

			if (p[i]->price * p[i]->quantity > maxstockvalue) {
				maxstockvalue = p[i]->price * p[i]->quantity;
			}
		}

		for (int i = 0; i < n; i++) {
			if (p[i]->price * p[i]->quantity == maxstockvalue) {
				cout << "name: " << p[i]->name << " stock value: " << maxstockvalue;
			}
		}
	}

	if (p) {
		for (int i = 0; i < n; i++)
			delete[]p[i];
		delete[]p;
	}

}
