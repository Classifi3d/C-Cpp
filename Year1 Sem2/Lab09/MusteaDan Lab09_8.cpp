#include <iostream>
#include<cstring>
using namespace std;

class Complex{
    private:
    double real,imag;
    public:
    Complex(){
        this->real=1.0;
        this->imag=1.0;
    }
    Complex(double real,double imag){
        this->real=real;
        this->imag=imag;
    }
    Complex(const Complex &num){
        this->real=num.real;
        this->imag=num.imag;
    }
    void SetImag(int imag){
        this->imag=imag;
    }
    void SetReal(int real){
        this->real=real;
    }
    int GetImag(){
        return this->imag;
    }
    int GetReal(){
        return this->real;
    }
    void Display(){
        cout<<this->real<<" "<<this->imag<<endl;
    }
    Complex operator+(Complex &num){
        Complex aux;
        aux.real+=num.real;
        aux.imag+=num.imag;
        return aux;
    }
    Complex operator-(Complex &num){
        Complex aux;
        aux.real-=num.real;
        aux.imag-=num.imag;
        return aux;
    }
    Complex operator*( Complex &num){
        Complex aux;
        double rl,im;
        rl=(-1)*(this->imag*num.imag + this->real*num.real);
        im=this->imag*num.real+num.imag*this->real;
        aux.imag=im;
        aux.real=rl;
        return aux;
    }
    void operator=(Complex &num){
        this->real=num.real;
        this->imag=num.imag;
    }
    Complex operator/(const Complex &num){
        Complex aux;
        int rl,im;
        rl=(-1)*(this->imag/num.imag + this->real/num.real);
        im=this->imag/num.real+this->real/num.imag;
        aux.imag=im;
        aux.real=rl;
        return aux;
    }
};

int main(){

Complex a,b;
int x,y;
cout<<"Insert the real and imaginary parts of a complex number: ";
cin>>x>>y;
a.SetImag(y);
a.SetReal(x);
cout<<"Insert the real and imaginary parts of a complex number: ";
cin>>x>>y;
b.SetImag(y);
b.SetReal(x);

Complex c=a+b;
Complex d=a-b;
Complex e=a*b;
Complex f=a/b;
c.Display();
d.Display();
e.Display();
f.Display();



}