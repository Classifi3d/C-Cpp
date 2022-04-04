//MusteaDan Lab10 Grupa 2013
#include <iostream>
#include <math.h>

using namespace std;

class Triangle{
    protected:
    double s1,s2,s3;//sides
    public:
    double Perimeter(){
        return s1+s2+s3;
    }
    void SetSides(double s1,double s2,double s3){
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;
    }
};

class Triangle_extended : public Triangle{
    public:
    double Area(){
        double s;
        s=(s1+s2+s3)/2;
        return sqrt(s*(s-s1)*(s-s2)*(s-s3));
    }
    double Height(){
        if(s1>s2&&s1>s3){//s1 is base
            return 2*Area()/s1;
        }
        if(s2>s3&&s2>s1){//s1 is base
            return 2*Area()/s2;
        }
        if(s3>s2&&s3>s1){//s1 is base
            return 2*Area()/s3;
        }
    }
};

int main(){
    Triangle a;
    cout<<"Insert the 3 sides of the triangle: ";
    double x,y,z;
    cin>>x>>y>>z;
    a.SetSides(x,y,z);
    cout<<"Triangle Class Perimeter: "<<a.Perimeter()<<endl;
    Triangle_extended b;
    b.SetSides(x,y,z);
    cout<<"Triangle_extened Class Perimeter, Area and triangle's height respectivley: "<<b.Perimeter()<<" "<<b.Area()<<" "<<b.Height()<<endl;


    return 0;
}