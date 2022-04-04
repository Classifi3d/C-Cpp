//Mustea Dan Lab04 Grupa 2013
#include <iostream>

using namespace std;

#define MAX 1000

void sortTwoInOne(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[MAX],int &p);
void mergeSorted(int arrayA[MAX],int n,int arrayB[MAX],int m,int arrayC[MAX],int &p);
int intCompare(const void *a,const void *b);

int main(){
	int n,m,k,array[MAX],arraySorted[MAX];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>array[i];
	}
	cin>>n;
	cout<<"===== Sorted ====="<<endl;
	sortTwoInOne(array,n,&array[n],m-n,arraySorted,k);
	for(int i=0;i<k;i++){
		cout<<arraySorted[i]<<" ";
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
					arrayC[k++]=arrayA[i++];
			}else if(arrayB[j]<=arrayA[i]){
					arrayC[k++]=arrayB[j++];
			}
		}else if(i<n){
				arrayC[k++]=arrayA[i++];
		}else if(j<m){
				arrayC[k++]=arrayB[j++];
		}
	}
	p=k;

}