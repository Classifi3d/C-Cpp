//MusteaDan Lab07 Grupa 2013
#include <iostream>

using namespace std;

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

class Fraction{
    private:
        int a,b;
        static int icount;
    public:
        Fraction(){
            icount++;
            this->a=0;
            this->b=1;
        }
        Fraction(int x,int y){
            icount++;
            if(y!=0){
                this->a=x;
                this->b=y;
            }
        }
        Fraction(const Fraction &f){
            icount++;
            this->a=f.a;
            this->b=f.b;
        }
        ~Fraction(){
            cout<<"icount: "<<icount<<endl;
            icount--;
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

        friend Fraction f_add_fraction(Fraction f1,Fraction f2){
            Fraction f3;
            f3.b=0;
            f3.a=0;
            f3.a=f1.a+f2.a;
            f3.b=f1.b+f2.b;
            return f3;
        }
        friend Fraction f_sub_fraction(Fraction f1,Fraction f2){
            Fraction f3;
            f3.b=0;
            f3.a=f1.a-f2.a;
            f3.b=f1.b-f2.b;
            return f3;
        }
        friend Fraction f_mul_fraction(Fraction f1,Fraction f2){
            Fraction f3;
            f3.b=0;
            f3.a=f1.a*f2.a;
            f3.b=f1.b*f2.b;
            return f3;
        }
        friend Fraction f_dif_fraction(Fraction f1,Fraction f2){
            Fraction f3;
            f3.b=0;
            f3.a=f1.a/f2.a;
            f3.b=f1.b/f2.b;
            return f3;
        }
        friend void Simplifiy(Fraction fr){
            int x=fr.a,y=fr.b,res,copa=fr.a,copb=fr.b;
            res=CMMDC(x,y);
            while(res!=1){
                x/=res;
                y/=res;
                res=CMMDC(x,y);
            }
            fr.a=copa;
            fr.b=copb;

        }


};

int Fraction::icount=0;


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
    f3=f_add_fraction(f1,f2);
    f4=f_sub_fraction(f1,f2);
    f5=f_mul_fraction(f1,f2);
    f5=f_dif_fraction(f1,f2);
    f3.Display();
    f4.Display();
    f5.Display();
    f6.Display();

    return 0;
}