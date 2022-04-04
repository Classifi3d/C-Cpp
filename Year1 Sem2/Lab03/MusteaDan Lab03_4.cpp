#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

void display(int array[MAX],int N,int a[MAX],int b[MAX]);
bool valid(int k,int array[MAX],int N);
void backtrack(int k,int array[MAX],int N,int a[MAX],int b[MAX],int &highestProfit);
int associationsProfit(int link[MAX],int N,int a[MAX],int b[MAX]);

int main(){
    int array[MAX],N;
    int b[MAX],f[MAX];
    int highestProfit=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>b[i];
    }
    for(int i=0;i<N;i++){
        cin>>f[i];
    }
    backtrack(0,array,N,b,f,highestProfit);
    int profitLen=0;

    int highestProfitCp=highestProfit;
    while(highestProfitCp!=0){
        profitLen++;
        highestProfitCp/=10;
    }
    for(int i=0;i<N*2+3+profitLen;i++){
        cout<<"_";
    }
    cout<<endl;
    cout<<highestProfit<<endl;
    return 0;
}

int associationsProfit(int link[MAX],int N,int a[MAX],int b[MAX]){
    int profit=0;
    for(int i=0;i<N;i++){
        profit+=a[i]*b[link[i]];
    }
    return profit;
}


void display(int array[MAX],int N,int a[MAX],int b[MAX]){
    for (int j=0;j<N;j++){
        cout<<array[j]<<" ";
    }
    cout<<" | ";
    cout<<associationsProfit(array,N,a,b);
    cout<<endl;
}

bool valid(int k,int array[MAX]){
    for(int j=0;j<k;j++){
        if (array[j]==array[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int k,int array[MAX],int N,int a[MAX],int b[MAX],int &highestProfit){
    for(int i=0;i<N;i++){//elements 
        array[k]=i;
        if(valid(k,array)==true){
            if (k==N-1){
                display(array,N,a,b);
                int profit=associationsProfit(array,N,a,b);
                if(profit>highestProfit){
                    highestProfit=profit;
                }
            } else{
                backtrack(k+1,array,N,a,b,highestProfit);
            }
        }
    }
}
