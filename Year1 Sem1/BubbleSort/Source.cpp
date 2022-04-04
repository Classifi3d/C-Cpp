#include <iostream>
using namespace std;

int main() {

	int n, f, p;
	cin >> n;
	f = 2;
	while (n > 1)
	{
		p = 0;
		while (n % f == 0)
		{
			n = n / f;
			p++;
		}
		if (p > 0)
			cout << f << "^" << p << " ";
		f++;
	}

	return 0;

}