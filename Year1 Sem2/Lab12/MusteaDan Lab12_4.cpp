//Mustea Dan Lab12 Group: 2013
#include <iostream>
#include <cstring>

using namespace std;

class AcceleratedMovement{
private:
    double dc,vc,a;
public:
    AcceleratedMovement(){
        //static
        dc=0;
        vc=0;
        a=0;
    }
    AcceleratedMovement(double dc,double vc,double a){
        this->dc=dc;
        this->vc=vc;
        this->a=a;
    }
    friend ostream &operator<<(ostream &output,AcceleratedMovement &aux){
        output << "DC: "<<aux.dc<<" VC: "<<aux.vc<<" A: "<<aux.a;
        return output;
    }
    friend istream &operator>>(istream &input,AcceleratedMovement &aux){
        input >>aux.dc>>aux.vc>>aux.a;
        return input;
    }
};


int main(){
    AcceleratedMovement a;
    cout<<a<<endl;
    cin>>a;
    cout<<a<<endl;
    
    return 0;
}