//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include <search.h>

using namespace std;

int intCmp(const void *a,const void *b);

#define MAX 100

int main(){
	int array[MAX];
	int target;
	size_t n=12;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	cin>>target;
	
	int *item = (int*) lfind(&target, array, &n, sizeof (int),(int(*) (const void *, const void *))  intCmp);
	bool flagFound;
	if( item != NULL ) {
    	cout<<"Found target "<<*item<<endl;
    	flagFound=true;
	}else{
		cout<<"Target could not be found"<<endl;
		flagFound=false;
	}
	qsort(array,n,sizeof(int),intCmp);
	if(flagFound==true){
		cout<<"The number was found in these locations: ";
		int count=0;
		for(int i=0;i<n;i++){
			if(array[i]==target){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}


int intCmp(const void *a,const void *b){
	int A=*(int *)a;
	int B=*(int *)b;
	return A-B;
}