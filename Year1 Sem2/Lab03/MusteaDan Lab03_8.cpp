#include <iostream>
#include <search.h>

using namespace std;

#define MAX 10000

void generateArray(int N,int array[MAX]);
int compare(int *x, int *y);
void display(int N,int array[MAX]);

int main(){
    int n=10,array[MAX],target;
    generateArray(n,array);
    display(n,array);
    target=rand();
    cout<<"Generated number:"<<target<<endl;
    size_t N=n;
    int *result=(int*)lsearch(&target,array,&N,sizeof(int),(int(*) (const void *,const void *))compare);
    display(n+1,array);

    return 0;
}

void generateArray(int N,int array[MAX]){
    srand (time(NULL));
    for(int i=0;i<N;i++){
        array[i]=rand();
    }
}

void display(int N,int array[MAX]){
    cout<<"Array: ";
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int compare(int *x, int *y){   
   return (*x - *y); 
} 