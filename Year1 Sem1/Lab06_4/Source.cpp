#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <bitset>
using namespace std;

int getsets(int x, int p, int n);
int convertTenToTwo(int a);

int main() {
	int a;
	cout << "Insert the 'a' value:";
	cin >> a;
	cout << a <<"'s represantion is the other 3 main bases is "<< convertTenToTwo(a) <<" in B2; "<< a << hex << a << " in B16; " << oct << a <<" in B8; "<< dec<<endl;		//DEC RESETS THE BASE!!! 
	//bitset<16>(a)

	int x, p, n;
	cin >> x >> p >> n;
	cout << getsets(x, p, n);

	return  0;
}

int convertTenToTwo(int a) {
	if (a == 0)
		return 0;
	else
		return (a % 2 + 10 * convertTenToTwo(a / 2));
}

int getsets(int x, int p, int n){
	x = convertTenToTwo(x);

	while (p > 0) {
		x = x/10;
		p--;
	}
	

	int newNum = 0, P = 1;
	while (x != 0 && n > 0) {
		newNum = newNum + P*(x % 10);
		//cout << newNum << " " << P << " " << x << " " << n << endl;
		P *= 10;
		x /= 10;
		n--;
	}
	//cout << newNum << endl;
	return newNum;

}


