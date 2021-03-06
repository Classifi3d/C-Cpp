#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100000

ifstream fin ("MusteaDan Lab03_5.txt");
ofstream fout ("MusteaDan Lab03_5.txt");

void generateFile(int N);
void readFile(int N,int array[MAX]);
int divEtImpMax(int N,int array[MAX],int start, int finish);
int divEtImpMin(int N,int array[MAX],int start, int finish);

int main(){
    int n,array[MAX];
    cin>>n;
    generateFile(n);
    readFile(n,array);
    int intDivEtImpMax,intDivEtImpMin;
    intDivEtImpMax=divEtImpMax(n,array,0,n-1);
    intDivEtImpMin=divEtImpMin(n,array,0,n-1);
    //cout<<divEtImpMax(n,array,0,n-1)<<endl;
    //cout<<divEtImpMin(n,array,0,n-1)<<endl;
    fout<<intDivEtImpMax<<endl<<intDivEtImpMin;

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

int divEtImpMax(int N,int array[MAX],int start, int finish){
    int a, b, mid;
    if (start==finish){
        return array[start];
    }else{
        mid = (start+finish)/2;
        a = divEtImpMax(N,array,start, mid);
        b = divEtImpMax(N,array,mid+1, finish);
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
}

int divEtImpMin(int N,int array[MAX],int start, int finish){
    int a, b, mid;
    if (start==finish){
        return array[start];
    }else{
        mid = (start+finish)/2;
        a = divEtImpMin(N,array,start, mid);
        b = divEtImpMin(N,array,mid+1, finish);
        if (a<b){
            return a;
        }else{
            return b;
        } 
    }
}

