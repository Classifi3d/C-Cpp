#include <iostream>

using namespace std;
#define max 1000
float* p;

int main(){
	int N;
	int * tab;

	cin >> N;
	if ((tab = new int[N])){
		//read
		for (int i = 0; i < N; i++){
			cin >> tab[i];
		}

		//sum & avg
		int avg = 0,sum=0;
		for (int i = 0; i < N; i++)
		{
			sum += tab[i];
		}

		avg = sum/N;

		//formula
		float Mn = 0;
		for (int i = 0; i < N; i++) {
			Mn += pow((tab[i] - avg), i);
		}
		Mn = Mn / N;
		p = &Mn;

	}

	cout << *p;

	if (tab) {
		free(tab);
		delete[]tab;
	}

	cin.ignore();
	cin.get();
}
