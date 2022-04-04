//MusteaDan Lab10 Grupa 2013
#include <iostream>
#include <math.h>  
using namespace std;

class fraction{
    private:
    int gcd(int a, int b) { 
        if (a == 0)
        return b; 
        if (b == 0) 
        return a; 
        if (a == b) 
            return a; 
        if (a > b) 
            return gcd(a-b, b); 
        return gcd(a, b-a); 
    } 
    protected:
        int a,b;
    public:
        void SetFraction(int a, int b){
            this->a=a;
            this->b=b;
        }
        double GetA(){
            return a;
        }
        double GetB(){
            return b;
        }
        void Display(){
            cout<<a<<'/'<<b<<endl;
        }
        void Simplify(){
            int div=gcd(a,b);
            a/=div;
            b/=div;
        }
        fraction(){
            a=0;
            b=1;
        }
        fraction(int a,int b){
            if(b!=0){
                this->a=a;
                this->b=b;
            }else{
                cout<<"Invalid input!"<<endl;
            }
        }
        fraction operator+(const fraction &x){
            fraction aux;
            aux.a=this->a+x.a;
            aux.b=this->b+x.b;
            return aux;
        }
        fraction operator-(const fraction &x){
            fraction aux;
            aux.a=this->a-x.a;
            aux.b=this->b-x.b;
            return aux;
        }
        fraction operator*(const fraction &x){
            fraction aux;
            aux.a=this->a*x.a;
            aux.b=this->b*x.b;
            return aux;
        }
        fraction operator/(const fraction &x){
            fraction aux;
            aux.a=this->a*x.b;
            aux.b=this->b*x.a;
            return aux;
        }
};

class fraction_ext: public fraction{
    public:
    fraction_ext(int a,int b){
        fraction(a,b);
    }
    fraction_ext(){
        fraction();
    }
    fraction_ext operator++(){
        this->a+=this->b;
        this->b+=this->b;
    }
    fraction_ext operator--(){
        this->a-=this->b;
        this->b-=this->b;
    }

};


int main(){
    int a,b;
    cout<<"Insert the values of a fraction: ";
    cin>>a>>b;
    fraction x;
    x.SetFraction(a,b);
    x.Simplify();
    x.Display();
    cin>>a>>b;
    fraction y;
    cout<<"Insert the values of a fraction: ";
    y.SetFraction(a,b);
    y.Simplify();
    y.Display();
    cout<<"==== Operations ===="<<endl;
    fraction z;
    z=x+y;
    z.Display();
    z=x-y;
    z.Display();
    z=x*y;
    z.Display();
    z=x/y;
    z.Display();
    cout<<"Insert the values of a fraction: ";
    cin>>a>>b;
    fraction_ext n(a,b);
    cout<<"Insert the values of a fraction: ";
    cin>>a>>b;
    fraction_ext m(a,b);
    cout<<"==== Operations Extended ===="<<endl;
    ++n;
    n.Display();
    --m;
    m.Display();

    return 0;
}