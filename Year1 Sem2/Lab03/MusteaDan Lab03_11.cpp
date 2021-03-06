#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define MAX 100

ifstream fin ("MusteaDan Lab03_11.txt");

void readArrayFromFile(float array[MAX],int &n){

    float x;
    int counter=0;
    while(fin>>x){
        array[counter++]=x;
    }
    n=counter;
}

int binarySearchAscending(float array[MAX],int start,int end,float x){
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

int cmpfunc(const void * a, const void * b) {
    if(*(float*)a == *(float*)b) return 1;
    else return 0;
    // return *(float*)a-*(float*)b;

}


int main(){
    float target;
    cin>>target;
    int n=0;
    float array[MAX];
    readArrayFromFile(array,n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<endl;
    }
    //my method
    //int index=binarySearchAscending(array,0,n+1,target);
    // cout<<"the element is: "<<(float)array[index]<<" and it has the position: "<<index<<endl;

    //bsearch
    float *item = (float*) bsearch (&target, array, n, sizeof (float), cmpfunc);
    if( item != NULL ) {
        cout<<"Found target "<<*item<<endl;
    } else {
        cout<<"Target could not be found"<<*item<<endl;
    }


    return 0;
}