#include <iostream>
#include <time.h>
using namespace std;

#define pi 2,14159


struct car {
	int maxspeed;
	int platenumber;
	int numofseats;
};

car Fabrication (int maxspeed,int numofseats){
	srand(time(NULL));
	int platenumber = rand() % 1000 + 1;

	car x;
	x.maxspeed = maxspeed;
	x.platenumber = platenumber;
	x.numofseats = numofseats;
	return x;
};


int main(){
	int a, c;
	cin >> a >> c;
	car CAR;
	CAR=Fabrication(a, c);
	cout << CAR.maxspeed << " " << CAR.platenumber << " " << CAR.numofseats << endl;

	return 0;
}
