#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

void display(int array[MAX],int N);
void backtrack(int k,int array[MAX],int N,int graph[MAX][MAX],int dim);
int costIfAvailable(int graph[MAX][MAX], int i, int j);
bool checkIfChainIsCorrect(int k,int array[MAX],int N,int graph[MAX][MAX]);
void readGraph(int graph[MAX][MAX],int &N);
void displayGraph(int graph[MAX][MAX],int N);
bool valid(int k,int array[MAX]);

ifstream fin ("MusteaDan Lab03_3.txt");

int main(){
    int array[MAX],N;
    int graph[MAX][MAX];

    readGraph(graph,N);
    //cout<<N<<endl;
    //displayGraph(graph,N);


    array[0]=0;
    backtrack(1,array,N,graph,1);
    for(int dim=0;dim<=N;dim++){
        backtrack(0,array,N,graph,dim);
    }


    return 0;
}

void displayGraph(int graph[MAX][MAX],int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}


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

int costIfAvailable(int graph[MAX][MAX], int i, int j){
    if(graph[i][j]!=-1){
        return graph[i][j];
    }else{
        return -1;
    }
}

bool checkIfChainIsCorrect(int k,int array[MAX],int N,int graph[MAX][MAX]){
    for(int i=1;i<N;i++){
        if(costIfAvailable(graph,array[i-1],array[i])==-1){
            return false;
        }
    }
    return true;
}

//!<----------------------------
void display(int array[MAX],int N){
    cout<<"D: ";
    for (int j=0;j<=N;j++){
        cout<<array[j]<<" ";
    }
    cout<<endl;
}
//!<----------------------------
bool valid(int k,int array[MAX]){
    for(int j=0;j<=k;j++){
        if (array[j]==array[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int k,int array[MAX],int N,int graph[MAX][MAX],int dim){//k=1
    for(int i=0;i<N;i++){//elements [0;N)
        array[k]=i;
        cout<<k<<" "<<i<<endl;
        if(k==dim){//TODO dim=1
            if(valid(k,array)==true){//!no
                display(array,N);//!no  
            }
            else{
                backtrack(k+1,array,N,graph,dim);
            }
        }
    }
}

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

/*
void backtrack(int k,int array[MAX],int N,int graph[MAX][MAX]){
    //for(int dim=2;dim<N;dim++)
    array[0]=0;
    for(int i=1;i<=N;i++){//elements
        array[k]=i;
        if(valid(k,array)==true){
            if (k==N-1){
                //if (checkIfChainIsCorrect(k,array,dim,graph)==true){
                    display(array,N);
               // }
            }else{
                backtrack(k+1,array,N,graph);
            }
        }
    }
}*/

/*
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
*/

