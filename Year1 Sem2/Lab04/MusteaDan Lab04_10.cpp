//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include <time.h>

using namespace std;

#define MAX 200

int floatCmp(const void *a, const void *b);
int intCmp(const void *a,const void *b);

int main(){
	int n,arrayInt[MAX],arrayFractional[MAX];
	float arrayReal[MAX];
	n=200;
	srand(NULL);
	cout<<"The generated array of integer parts: "<<endl;
	for(int i=0;i<n;i++){
		arrayInt[i]=rand()%100;
		cout<<arrayInt[i]<<" ";
	}cout<<endl;
	cout<<"The generated array of fractional parts: "<<endl;
	for(int i=0;i<n;i++){
		arrayFractional[i]=rand()%20+1;
		cout<<arrayFractional[i]<<" ";
	}cout<<endl;
	cout<<"The resulting array of real numbers: "<<endl;
	for(int i=0;i<n;i++){
		arrayReal[i]=((float)arrayInt[i]/(float)arrayFractional[i]);
		cout<<arrayReal[i]<<" ";
	}cout<<endl;
	cout<<"=========== Sorted Arrays ==========="<<endl;
	qsort(arrayInt,n,sizeof(int),intCmp);
	cout<<"The sorted array of integer parts: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arrayInt[i]<<" ";
	}cout<<endl;
	qsort(arrayFractional,n,sizeof(int),intCmp);
	cout<<"The sorted array of fractional parts: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arrayFractional[i]<<" ";
	}cout<<endl;
	qsort(arrayReal,n,sizeof(float),floatCmp);
	cout<<"The sorted array of real numbers: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arrayReal[i]<<" ";
	}cout<<endl;

	return 0;
}

int intCmp(const void *a,const void *b){
	int A=*(int *)a;
	int B=*(int *)b;
	return A-B;
}

int floatCmp(const void* a, const void* b){
  float fa = *(const float*) a;
  float fb = *(const float*) b;
  return (fa > fb) - (fa < fb);
}