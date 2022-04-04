#include <iostream>
#include <fstream>

using namespace std;

#define MAX 2000

ifstream fin ("MusteaDan Lab03_6.txt");
ofstream fout ("MusteaDan Lab03_6.txt");

void generateFile(int N);
void readFile(int N,int array[MAX]);
int greatestCommonDivider(int start, int finish, int array[MAX]);

int main(){
    int n,array[MAX];
    cin>>n;
    generateFile(n);
    readFile(n,array);
    cout<<array[greatestCommonDivider(0,n-1,array)]<<endl;

    return 0;
}

void generateFile(int N){
    srand (time(NULL));
    for(int i=0;i<N;i++){
    fout<<rand()<<endl;
    }
}

void readFile(int N,int array[MAX]){
    int x,k=0;
    while(fin>>x){
        array[k++]=x;
    }
}

int greatestCommonDivider(int start, int finish, int array[MAX]){
    int mid,m1,m2,rest;
    if(start==finish){
        return array[finish];
    }else{
        mid=(start+finish)/2;
        m1=greatestCommonDivider(start,mid,array);
        m2=greatestCommonDivider(mid+1,finish,array);
        rest=m1%m2;
        while(rest!=0){
            m1=m2;
            m2=rest;
            rest=m1%m2;
        }
        return m2;
    }
}