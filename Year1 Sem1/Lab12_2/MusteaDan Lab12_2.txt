#include <iostream>
#include <time.h>
using namespace std;

#define pi 2,14159


struct circle {
	int radious;
	int diameter;
};

void displayByValue(circle C) {
	cout << "dislayed by value radious:"<<C.radious << " diameter " << C.diameter<<endl;
}

void displayByPointer(struct circle* C) {
	cout << "dislayed by value pointer:" << (*C).radious << " diameter " << (*C).diameter<<endl;
}

int main() {
	int r, d;
	cin >> r >> d;

	circle C;
	C.radious = r;
	C.diameter = d;

	circle* c = &C;
	displayByPointer(c);
	displayByValue(C);

	return 0;
}
