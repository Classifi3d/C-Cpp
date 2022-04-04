#include <iostream>

using namespace std;

#define MAX 1000

//! UNDER CONSTRUCTION
int divEtImp(int N,int array[MAX],int start, int finish){
    int a, b, mid;
    if (start==finish){
        return array[start];
    }else{
        mid = (start+finish)/2;
        a = divEtImp(N,array,start, mid);
        b = divEtImp(N,array,mid+1, finish);
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
}


int main(){
    int n,array[MAX];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }


    return 0;
}
