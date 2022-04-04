#include <iostream>

using namespace std;

#define max 100

struct car {
	char producer[max];
	int production_year;
	int cylinder_volume;
	char color[max];

};

int main()
{
	car** c = NULL;
	int n;
	cin >> n;

	if (c = new car * [n]) {
		for (int i = 0; i < n; i++) {
			c[i] = new car;
			if (c[i] == 0) {
				cout << "\nAllocation error!";
				cin.ignore();
				cin.get();
				return 1;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> c[i]->producer;
			cin >> c[i]->production_year;
			cin >> c[i]->cylinder_volume;
			cin >> c[i]->color;

		}

		for (int i = 0; i < n; i++) {
			if (c[i]->production_year > 2010 && strcmp(c[i]->color,"red")==0) {
				cout<<"car - producer: "<< c[i]->producer<<" production year "<< c[i]->production_year<<" cylinder volume "<<c[i]->cylinder_volume<<" color "<< c[i]->color<<endl;
			}
		}
	}

	if (c) {
		for (int i = 0; i < n; i++)
			delete[]c[i];
		delete[]c;
	}

}
