//MusteaDan Lab10 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000
#define PI 3.14159

class shape{
    public:
        char *name;
    public:
    void setname(char* name){
        strcpy(this->name,name);
    }
};

class circle : public shape{
    private:
        double radius;
    public:
    circle(){
    }
    circle(char* name,double radius){
        this->name=name;
        this->radius=radius;
    }
    double perimeter(){
        return PI*2*radius;
    }
    double area(){
        return PI*radius*radius;
    }
};
class square : public shape{
    private:
        double side;
    public:
    square(){
    }
    square(char* name,double side){
        this->name=name;
        this->side=side;
    }
    double perimeter(){
        return 4*side;
    }
    double area(){
        return side*side;
    }
};
class rectangle : public shape{
    private:
        double side1,side2;
    public:
    rectangle(){
    }
    rectangle(char* name,double side1,double side2){
        this->name=name;
        this->side1=side1;
        this->side2=side2;
    }
    double perimeter(){
        return side1*2+side2*2;
    }
    double area(){
        return side1*side2;
    }
};

int main(){
    char name1[MAX],name2[MAX],name3[MAX];
    double radius1,side1,side2,side3;
    cout<<"Insert the name and radius of the cricle: "<<endl;
    cin>>name1>>radius1;
    circle a(name1,radius1);
    cout<<"The perimeter and area of "<<a.name<<" the are: "<<a.perimeter()<<" "<<a.area()<<endl;
    cout<<"Insert the name and side of the square: "<<endl;
    cin>>name2>>side1;
    square b(name2,side1);
    cout<<"The perimeter and area of "<<b.name<<" the are: "<<b.perimeter()<<" "<<b.area()<<endl;
    cout<<"Insert the name and both sides of the rectangle: "<<endl;
    cin>>name3>>side2>>side3;
    rectangle c(name3,side2,side3);
    cout<<"The perimeter and area of "<<c.name<<" the are: "<<c.perimeter()<<" "<<c.area()<<endl;



    return 0;
}