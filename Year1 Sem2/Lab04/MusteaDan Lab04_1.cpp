//Mustea Dan Lab04 Grupa 2013
#include <iostream>

using namespace std;

#define MAX 100

void read(int array[MAX],int &n);
void bubble_sort(int array[MAX],int n);

int main(){
	int n,array[MAX];
	
	read(array,n);
	bubble_sort(array,n);
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	
	return 0;
}

void read(int array[MAX],int &n){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
}

void bubble_sort(int array[MAX],int n){
	n--;
	bool flag=false;
	while(flag!=true){
		flag=true;
		for(int i=0;i<n;i++){
			if(array[i]>array[i+1]){
				int aux=array[i];
				array[i]=array[i+1];
				array[i+1]=aux;
				flag=false;
			}
		}
	}

}