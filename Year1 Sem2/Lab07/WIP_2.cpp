//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

class RealNumbers{
    private:
        double* pointerArray;
        int dim;
    public:
        void Set(double array[MAX],int dim){
            this->dim=dim;
            this->pointerArray= new double[this->dim];
        }
        void GetArray(){
            for(int i=0;i<this->dim;i++){
                cout<<this->pointerArray[i]<<" ";
            }
        }
        int GetDim(){
            return this->dim;
        }
        double GetArrayElement(int index){
            return pointerArray[index];
        }
        void Substract(RealNumbers rn1,RealNumbers rn2){
            int min_dim=rn1.GetDim();
            if(min_dim>rn2.GetDim()){
                min_dim=rn2.GetDim();
            }cout<<rn1.dim<<" "<<rn2.dim;
            this->dim=min_dim;
            for(int i=0;i<min_dim;i++){
                this->pointerArray[i]=rn1.GetArrayElement(i)-rn2.GetArrayElement(i);
            }
        }
};

void SetArray(double* array,int &n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
}

int main(){
    RealNumbers r1,r2,r3;
    int n,m,k;
    double ar1[MAX],ar2[MAX],ar3[MAX];
    SetArray(ar1,n);
    cout<<"in between"<<endl;
    SetArray(ar2,m);
    cout<<"HERE2";
    r1.Set(ar1,n);
    //cout<<r1.GetArrayElement(2);
    //cout<<r1.GetDim();
    //r1.GetArray();
    r2.Set(ar2,m);
    r3.Substract(r1,r2);
    cout<<"HERE1"<<endl;
    r3.GetArray();

    return 0;
}