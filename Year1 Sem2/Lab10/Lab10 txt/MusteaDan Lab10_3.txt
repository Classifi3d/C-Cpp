//MusteaDan Lab10 Grupa 2013
#include <iostream>
#include <math.h>
using namespace std;

class dad{
protected: 
    int x,y;
public:
    void SetX(int x){
        this->x=x;
    }
    void SetY(int y){
        this->y=y;
    }
    int GetX(){
        return this->x;
    }
    int GetY(){
        return this->y;
    }
};

class son : public dad{
public:
    son(){
        this->x=0;
        this->y=0;
    }
    son(son &a){
        this->x=a.x;
        this->y=a.y;
    }

    son operator+(son &a){
        son aux;
        aux.SetX(x+a.GetX());
        aux.SetY(y+a.GetY());
        return aux;
    }
    son operator-(son &a){
        son aux;
        aux.SetX(x-a.GetX());
        aux.SetY(y-a.GetY());
        return aux;
    }
    son operator*(son &a){
        son aux;
        aux.SetX(x*a.GetX());
        aux.SetY(y*a.GetY());
        return aux;
    }
    son operator/(son &a){
        son aux;
        aux.SetX(x/a.GetX());
        aux.SetY(y/a.GetY());
        return aux;
    }
    int sum(){
        return x+y;
    }
    int sub(){
        return x-y;
    }
    int mul(){
        return x*y;
    }
    double dif(){
        return x/y;
    }
    void Display(){
        cout<<x<<" "<<y<<endl;
    }
};

class grandson : public son{
    private:
    public:
    double SquareRoot(){
        return sqrt(mul());
    }
    double Power(){
        int base=sum();
        int power=sub();
        return pow(base,power);
    }
};




int main(){
    son a,b,c,d,e,f;
    int x,y;
    cin>>x>>y;
    a.SetX(x);
    a.SetY(y);
    cin>>x>>y;
    b.SetX(x);
    b.SetY(y);
    cout<<"==== Basic Operations ====="<<endl;
    c=a+b;
    c.Display();
    d=a-b;
    d.Display();
    e=a*b;
    e.Display();
    f=a/b;
    f.Display();
    cout<<"==== Advanced Operations ===="<<endl;
    grandson j;
    j.SetX(x);
    j.SetY(y);
    cout<<j.SquareRoot()<<endl;
    cout<<j.Power()<<endl;


    return 0;
}