//MusteaDan Lab11 Grupa 2013
#include <iostream>
#include <math.h>  
using namespace std;

class fraction{
    private:
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
        virtual void Simplify(){};
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
    public:
    void Simplify(){
            int div=gcd(a,b);
            a/=div;
            b/=div;
            cout<<"== Simplified =="<<endl;
    }
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
    void operator+=(const fraction_ext &x){
        this->a+=x.a;
        this->b+=x.b;
    }
    void operator-=(const fraction_ext &x){
        this->a-=x.a;
        this->b-=x.b;
    }
    void operator*=(const fraction_ext &x){
        this->a*=x.a;
        this->b*=x.b;
    }
    void operator/=(const fraction_ext &x){
        this->a/=x.a;
        this->b/=x.b;
    }

};


int main(){
    int a,b;
    cout<<"Insert the values of a fraction: ";
    cin>>a>>b;
    fraction x;
    x.SetFraction(a,b);
    x.Display();
    cout<<"Insert the values of a fraction: ";
    cin>>a>>b;
    fraction y;
    y.SetFraction(a,b);
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
    n+=m;
    n.Display();
    m-=n;
    m.Display();
    n*=m;
    n.Display();
    m/=n;
    m.Display();


    return 0;
}