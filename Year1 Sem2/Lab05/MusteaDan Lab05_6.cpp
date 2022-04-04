//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class complexNumbers{
    private:
        int real,imag;
    public:
        void SetComplexNumber(int a,int b){
            this->real=a;
            this->imag=b;
        }
        void GetComplexNumber(){
            cout<<"real part: "<<this->real<<" | imaginary part: "<<this->imag<<endl;
        }
};

int main(){

    complexNumbers a,b;
    cout<<"Insert the set of values of 2 complex numbers: ";
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    a.SetComplexNumber(a1,a2);
    b.SetComplexNumber(b1,b2);
    a.GetComplexNumber();
    b.GetComplexNumber();


    return 0;
}