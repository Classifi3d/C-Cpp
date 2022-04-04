//Mustea Dan Lab12 Group: 2013
#include <iostream>

using namespace std;

class Complex{
protected:
    int real,imag;
public:
    friend ostream &operator<<(ostream &output, Complex&aux){
        output <<"Real: "<<aux.real<<" Imag: "<<aux.imag;
        return output;
    }
    friend istream &operator>>(istream &input, Complex&aux){
        input >> aux.real >> aux.imag;
        return input;
    }

};

class Point : public Complex{
protected:
    char color;
public: 
    friend ostream &operator<<(ostream &output, Point&aux){
        output <<"X: "<<aux.real<<" Y: "<<aux.imag<<" Color: "<<aux.color;
        return output;
    }
    friend istream &operator>>(istream &input, Point&aux){
        input >>aux.real>>aux.imag>>aux.color;
        return input;
    }

}; 


int main(){

    Complex a;
    cout<<"Insert the real and imag parts of a complex number: ";
    cin>>a;
    cout<<a<<endl;
    Point b;
    cout<<"Insert the coordinates (X,Y) and the color (r-RED / g-GREEN / b-BLUE) of a point: ";
    cin>>b;
    cout<<b<<endl;
    a=b;
    cout<<a<<endl;

    return 0;
}