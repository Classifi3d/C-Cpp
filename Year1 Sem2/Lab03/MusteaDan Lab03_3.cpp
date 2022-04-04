#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("MusteaDan Lab03_3.txt");

#define MAX 50

/*
void readGraph(int n,int in[MAX],int out[MAX],int cost[MAX],int length){
    cout<<"Insert the number of subsidieries: ";
    fin>>n;
    cout<<"Do not reintroduce connections previously added!"<<endl;
    int con=0;
    for(int i=0;i<=n;i++){
        cout<<"Insert the number of connections of this subsidierie "<<i<<endl;
        fin>>con;
        
        for(int j=0;j<con;j++){
            cout<<"Insert the connection of subsidierie "<<i<<": ";
            int pos=i+j+1;
            cout<<pos<<" - "<<endl;
            in[pos]=i;
            fin>>out[pos];
            cout<<"Insert the cost of this connection"<<endl;
            fin>>cost[pos];
            length=pos;
        }
    }
}*/

void readGraph(int graph[MAX][MAX],int &N){
    fin>>N;

    //cout<<"Insert the cost of connections between 2 subsiduaries, if the connection doesn't exist insert '-1'"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //cout<<"Insert the cost between "<<i<<" "<<j<<endl;
            fin>>graph[i][j];
        }
    }
}

void displayGraph(int graph[MAX][MAX],int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int costIfAvailable(int graph[MAX][MAX], int i, int j){
    if(graph[i][j]!=-1){
        return graph[i][j];
    }else{
        return -1;
    }
}

int recursiveSearch(int graph[MAX][MAX],int N,int visited[MAX],int k,int target){
    if(visited[k]==target){//* found target  
        return 0;
    }
    for(int i=0;i<N;i++){//search on the last element in 'visited' array
        if(costIfAvailable(graph,visited[k],i)!=-1){//if available
            int ok=1;
            for(int v=0;v<=k;v++){//check that it has not been visited before
                if(visited[v]==i){
                    ok=0;
                    //return INT32_MIN;//! loop or invalid
                }
            }
            if(ok==1){//TODO found another node
            visited[k+1]=i;cout<<"p: "<<i<<" ";
            return costIfAvailable(graph,visited[k],visited[k+1])+recursiveSearch(graph,N,visited,k+1,target);
            }
        }
        //else return INT32_MIN;//! loop or invalid
    }
}

bool checkIfChainIsCorrect(int graph[MAX][MAX],int N){


}

bool notVisitedBefore(int array[MAX],int currentLength,int element){
    for(int i=0;i<currentLength;i++){
        if(array[i]==element){
            return false;
        }
    }
    return true;
}


void backtrackChain(int graph[MAX][MAX],int N){
    for(int i=0;i<N;i++){

        
    }

}

int main(){
    int graph[MAX][MAX],N;
    readGraph(graph,N);
    cout<<N<<endl;
    displayGraph(graph,N);
    cout<<endl;
    backtrackChain(graph,N);
    

    return 0;
}