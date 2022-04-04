//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include <time.h>

using namespace std;

#define MAX 200

int main(){
	int n,array[MAX];
	n=200;
	srand(NULL);
	cout<<"The generated array: ";
	for(int i=0;i<n;i++){
		array[i]=rand()%100;
		cout<<array[i]<<" ";
	}cout<<endl;
	int min=101,maxi=-1,sum=0,avg;
	for(int i=0;i<n;i++){
		sum+=array[i];
		if(array[i]>maxi){
			maxi=array[i];
		}
		if(array[i]<min){
			min=array[i];
		}
	}

	bool avgFound=false;
	avg=(int)(sum/n);
	for(int i=0;i<n;i++){
		if(array[i]==avg){
			avgFound=true;
		}
	}
	cout<<"======================================================================="<<endl;
	cout<<"The min: "<<min<<" The max: "<<maxi<<" and The Average: "<<avg<<" which was ";
	if(avgFound=true){
		cout<<"found in the array"<<endl;
	}else{
		cout<<"NOT found in the array"<<endl;
	}

	return 0;
}