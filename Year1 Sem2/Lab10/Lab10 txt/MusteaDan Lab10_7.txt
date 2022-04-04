//MusteaDan Lab10 Grupa 2013
#include <iostream>

using namespace std;

#define PI 3.14159
#define SQRT2 1.4142

class circle{
private:
protected:
    double radius;
public:
    circle(double radius){
        cout<<"1";
        this->radius=radius;
    }
    circle(){}
    double area(){
        return PI*radius*radius;
    }
};

class square{
private:
protected: 
    double length;
public:
    square(double length){
        this->length=length;
    }
    square(){}
};

class roundsquare : public circle, public square{
public:
    roundsquare(double radius, double length){
        circle(radius);
        square(length);
    }
    void canitfit(){
        bool a=0;
        if(length*SQRT2<=radius){
            a=1;
        }
        if(a==1){
            cout<<"The square can fit"<<endl;
        }else{
            cout<<"The square cannot fit"<<endl;
        }
    }
    void perimeters(){
        cout<<"The perimeters of the cricle and square respectively are: "<<2*PI*radius<<" "<<4*length<<endl;
    }

};

int main(){
    double radius,length;
    cout<<"Insert the length of the radius of a cricle and the side of a square: ";
    cin>>radius>>length;
    roundsquare a(radius,length);
    a.canitfit();
    a.perimeters();




    return 0;
}