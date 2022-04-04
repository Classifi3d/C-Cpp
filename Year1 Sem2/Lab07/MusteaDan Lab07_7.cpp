//MusteaDan Lab07 Grupa 2013
#include <iostream>

using namespace std;

class Fraction{
    private:
        int a,b;
    public:
        Fraction(){
            this->a=0;
            this->b=1;
        }
        Fraction(int x,int y){
            if(y!=0){
                this->a=x;
                this->b=y;
            }
        }
        Fraction(const Fraction &f){
            this->a=f.a;
            this->b=f.b;
        }
        Fraction AddFraction(Fraction f){
            Fraction F;
            F.a=f.a+this->a;
            F.b=f.b+this->b;
            return F;
        }
        Fraction SubFraction(Fraction f){
            Fraction F;
            F.a=f.a-this->a;
            F.b=f.b-this->b;
            return F;
        }
        Fraction MulFraction(Fraction f){
            Fraction F;
            F.a=f.a*this->a;
            F.b=f.b*this->b;
            return F;
        }
        Fraction DivFraction(Fraction f){
            Fraction F;
            F.a=f.a*this->b;
            F.b=f.b*this->a;
            return F;
        }
        void Set(int a,int b){
            this->a=a;
            this->b=b;
        }
        int GetA(){
            return this->a;
        }
        int GetB(){
            return this->b;
        }
        void Display(){
            cout<<this->a<<"/"<<this->b<<endl;
        }
        int CMMDC(int x,int y){
            while(x!=y){
                if(x>y){
                    x-=y;
                }
                if(y>x){
                    y-=x;
                }
            }
            return x;
        }
        void Simplifiy(){
            int x=this->a,y=this->b,res=CMMDC(x,y);
            while(res!=1){
                x/=res;
                y/=res;
                res=CMMDC(x,y);
            }
        }


};

int main(){
    Fraction f1,f2,f3,f4,f5,f6;
    int a,b;
    cout<<"Insert the values of the fraction: "<<endl;
    cin>>a>>b;
    f1.Set(a,b);
    f1.Display();
    cout<<"Insert the values of the fraction: "<<endl;
    cin>>a>>b;
    f2.Set(a,b);
    f2.Display();
    cout<<"-----"<<endl;
    f3=f1.AddFraction(f2);
    f4=f1.SubFraction(f2);
    f5=f1.MulFraction(f2);
    f6=f1.DivFraction(f2);
    f1.Simplifiy();
    f2.Simplifiy();
    f1.Display();
    f2.Display();
    f3.Display();
    f4.Display();
    f5.Display();
    f6.Display();


    return 0;
}