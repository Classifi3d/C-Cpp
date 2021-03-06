//Mustea Dan Lab04 Grupa 2013
#include <iostream>

using namespace std;

#define MAX 1000

void quick_sort_desc(int array[MAX],int start,int end);
int partition(int array[MAX],int start,int end);

int main(){	
	int n,array[MAX];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	quick_sort_desc(array,0,n-1);
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}cout<<endl;

	return 0;
}

void quick_sort_desc(int array[MAX],int start,int end){
	if(start<end){
		int index=partition(array,start,end);
		quick_sort_desc(array,start,index);
		quick_sort_desc(array,index+1,end);
	}
}

int partition(int array[MAX],int start,int end){
	int index=array[start];
	int i=start;
	for(int j=start+1;j<=end;j++){
		if(array[j]>index){
			i++;
			int aux=array[i];
			array[i]=array[j];
			array[j]=aux;
		}
	}
	int aux=array[i];
	array[i]=array[start];
	array[start]=aux;
	return i;
}