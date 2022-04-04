
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50

class Calculator{
    private:
        int x,y,z;
    public:
    static int calcul(int x){
        return x*x;
    }
    int calcul(int x,int y){
        return x*y;
    }//yes we can use static and non static methods for the overloaded public methods
    static double calcul(int x,int y,int z){
        return ((x*x-x*y-y*z)/2);
    }
    void SetX(int x){
        this->x=x;
    }
    void SetY(int y){
        this->y=y;
    }
    void SetZ(int z){
        this->z=z;
    }
};

int main(){
int x,y,z;
cin>>x>>y>>z;
Calculator a;
a.SetX(x);
a.SetY(y);
a.SetZ(z);
cout<<a.calcul(x,y)<<endl;
}