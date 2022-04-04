//Mustea Dan Lab04 Grupa 2013
#include <iostream>

using namespace std;

#define MAX 1000

void sortTwoInOne(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[MAX],int &p);
void mergeSorted(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[MAX],int &p);
int intCompare(const void *a,const void *b);

int main(){
	int n,m,p,arrayA[MAX],arrayB[MAX],arrayC[2*MAX];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arrayA[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>arrayB[i];
	}
	sortTwoInOne(arrayA,n,arrayB,m,arrayC,p);
	cout<<endl;
	for(int i=0;i<p;i++){
		cout<<arrayC[i]<<" ";
	}cout<<endl;

	return 0;
}

void sortTwoInOne(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[2*MAX],int &p){
	qsort(arrayA,n,sizeof(int),intCompare);
	qsort(arrayB,m,sizeof(int),intCompare);
	mergeSorted(arrayA,n,arrayB,m,arrayC,p);

}

int intCompare(const void *a,const void *b){
	int A=*(int *)a;
	int B=*(int *)b;
	return A-B;
}

void mergeSorted(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[2*MAX],int &p){
	int k=0;
	int i=0,j=0;
	while(i<n||j<m){
		if(i<n&&j<m){
			if(arrayA[i]<arrayB[j]){
				if(arrayC[k-1]!=arrayA[i]){
					arrayC[k++]=arrayA[i++];
				}
			}else if(arrayB[j]<arrayA[i]){
				if(arrayC[k-1]!=arrayB[j]){
					arrayC[k++]=arrayB[j++];
				}			
			}else if(arrayB[j]==arrayA[i]){
				if(arrayC[k-1]!=arrayA[i]){
					arrayC[k++]=arrayA[i];
				}
				i++;
				j++;
			}
		}else if(i<n){
			if(arrayC[k-1]!=arrayA[i]){
				arrayC[k++]=arrayA[i];
			}
			i++;
		}else if(j<m){
			if(arrayC[k-1]!=arrayB[j]){
				arrayC[k++]=arrayB[j];
			}
			j++;
		}
 
	}
	p=k;

}
