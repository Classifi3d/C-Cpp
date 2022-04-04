//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include<fstream>

using namespace std;

ifstream fin1 ("MusteaDan Lab04_8-1.txt");
ifstream fin2 ("MusteaDan Lab04_8-2.txt");

#define MAX 100000

int floatCmp(const void *a, const void *b);

int main(){
	int k=0;
	float array[MAX]={0};
	float x,y;

	//read from file
	while(fin1>>x){
		array[k++]=x;
	}
	int counter=0;
	while(fin2>>y){
		array[k++]=y;
		array[k]=(float)((array[k-1]+array[counter++])/2);
		k++;
	}

	//sort
	qsort(array,k,sizeof(float),floatCmp);

	//num of non unique
	int unique=0;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(array[i]==array[j] && i!=j){
				j=k;//exit inner loop
				unique++;
			}	
		}
	}

	cout<<k<<endl;
	for(int i=0;i<k;i++){
		cout<<array[i]<<" ";
	}cout<<endl;

	cout<<"number of non unique elements is: "<<k-unique<<endl;

	fin1.close();
	fin2.close();

	return 0;
}

int floatCmp(const void* a, const void* b){
  float fa = *(const float*) a;
  float fb = *(const float*) b;
  return (fa > fb) - (fa < fb);
}