#include <iostream>

using namespace std;

#define MAX 100

void readArray(int array[MAX],int n){
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
}

int binarySearchAscending(int array[MAX],int start,int end,int x){
    if(end>=start){
        int mid=start + (end-start)/2;
        if(array[mid]==x){
            return mid;
        }
        if(array[mid]>x){
            return binarySearchAscending(array,start,mid-start,x);
        }
        return binarySearchAscending(array,mid+start,end,x);
    }
    return -1;

}

int main(){
    int array[MAX],n=5,a;
    readArray(array,n);
    cin>>a;
    if(binarySearchAscending(array,0,n+1,a)!=-1){
        cout<<"The prime factors of "<<a<<" are: ";
        for (int i=2;i<= a/2;i++) { 
            if(a%i==0){
                cout<<i<<" ";
                while(a%i == 0){ 
                    a/=i; 
                } 
            }
        } 
    }


    return 0;
}   