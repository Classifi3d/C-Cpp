#include <time.h>
#include <iostream>

using namespace std;

void init(int numere[ ], int dim);
void afis(int numere[ ], int dim);
void bubble(int numere[ ], int dim);
void quick(int numere[ ], int dim);
void shell(int numere[],int dim);
void slection(int numere[],int dim);
int comparare(const void *arg1, const void *arg2);

int main( ){

int dim, *numere;
cout << "\nIntrodu nr. elemente: ";
cin >> dim;
numere = new int[dim];

init(numere, dim);
bubble(numere, dim);

init(numere, dim);
quick(numere, dim);

init(numere, dim);
shell(numere, dim);

init(numere, dim);
slection(numere, dim);

cout<<endl;
delete[ ]numere;

}

int comparare(const void *arg1, const void *arg2)
{
if (*(int *)arg1<*(int *)arg2)
return -1;
if (*(int *)arg1 == *(int *)arg2)
return 0;
if (*(int *)arg1>*(int *)arg2)
return 1;
}

void init(int numere[ ], int dim){
clock_t start, end;
double dif;
start = clock( );
srand((unsigned)time(NULL));
for (int i = 0; i<dim; i++) {
numere[i] = rand();
}
end = clock( );
dif = (double)(end - start);
cout << "\nGenerarea numerelor a durat (clicks) " << dif << " si (seconds) " << ((float)dif) /
CLOCKS_PER_SEC << endl;
}

void afis(int numere[ ], int dim)
{
clock_t start, end;
double dif;
start = clock( );
for (int i = 0; i<dim; i++)
cout << " " << numere[i];
end = clock( );
dif = (double)(end - start);
cout << "\nAfisarea numerelor a durat (clicks) " << dif << " si (seconds) " << ((float)dif) /
CLOCKS_PER_SEC << endl;
}

void bubble(int numere[ ], int dim)
{
clock_t start, end;
double dif;
int aux, ok;
start = clock( );
do {
ok = 1;
for (int i = 0; i<dim - 1; i++) {
if (numere[i]>numere[i + 1]) {
aux = numere[i];
numere[i] = numere[i + 1];
numere[i + 1] = aux;
ok = 0;
}
}
} while (ok == 0);
end = clock( );
dif = (double)(end - start);
cout << "\nOrdonarea cu \"bubble sort\" a numerelor a durat (clicks) " << dif << " si (seconds) " <<
((float)dif) / CLOCKS_PER_SEC << endl;
}

void quick(int numere[ ], int dim) {
clock_t start, end;
double dif;
start = clock( );
qsort((int*)numere, dim, sizeof(int), comparare);
end = clock( );
dif = (double)(end - start);
cout << "\nOrdonarea cu \"quick sort\" a numerelor a durat (clicks) " << dif << " si (seconds) " <<
((float)dif) / CLOCKS_PER_SEC << endl;
}

void slection(int numere[],int dim){
	clock_t start,end;
	double dif;
	start=clock();
	int i,indexMin;
	for(i=0;i<dim-1;i++){
		for(int j=i+1;j<dim;j++){
			if(numere[j]<numere[indexMin]){
				indexMin=j;
			}
			int aux=numere[indexMin];
			numere[indexMin]=numere[i];
			numere[i]=aux;
		}
	}
	end=clock();
	dif=(double)(end-start);
	cout<<endl<<"Ordonarea cu \"selection sort\" a numerelor a durat (clicks)"<<dif<<"si (secounds) "<<((float)dif)/CLOCKS_PER_SEC;
}

void shell(int numere[],int dim){
	clock_t start,end;
	double dif;
	start=clock();
	for(int g=dim/2;g>0;g/=2){
		for(int i=g;i<dim;i++){
			int aux=numere[i];
			int j;
			for(j=i;j>=g&&numere[j-g];j-=g){
				numere[j]=numere[j-g];	
			}
			numere[j]=aux;
		}
	}
	end=clock();
	dif=(double)(end-start);
	cout<<endl<<"Ordonarea cu \"shell\" a numerelor a durat (clicks)"<<dif<<"si (secounds) "<<((float)dif)/CLOCKS_PER_SEC;
}