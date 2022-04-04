//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

class Fraction{
    private:
        int a,b,nameLength=40;
        char* name;
    public:
        Fraction(){
            //cout<<"Explicit"<<endl;
            this->a=0;
            this->b=1;
            this->name=new char[20];
        }
        Fraction(int x,int y,char unknown[40]){
            //cout<<"Paramters"<<endl;
            if(y!=0){
                this->a=x;
                this->b=y;
                strcpy(this->name,unknown);
            }
        }
        Fraction(const Fraction &f){
            //cout<<"Copy"<<endl;
            this->name = new char[f.nameLength];
            this->a=f.a;
            this->b=f.b;
            nameLength=f.nameLength;
            strcpy(this->name,f.name);
        }
        ~Fraction(){
            //cout<<"Destructor"<<endl;
            delete[] this->name;
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
        void SetAll(int a,int b,char name[20]){
            nameLength=strlen(name)+1;
            this->name=new char[nameLength];
            this->a=a;
            this->b=b;
            strcpy(this->name,name);
        }
        void SetName(char name[20]){
            nameLength=strlen(name)+1;
            strcpy(this->name,name);
        }
        char* GetName(){
            return this->name;
        }
        int GetA(){
            return this->a;
        }
        int GetB(){
            return this->b;
        }
        void Display(){
            cout<<this->a<<"/"<<this->b<<" "<<this->name<<endl;
        }
};

int main(){
    Fraction a,b;
    int x,y;
    char name[40];
    cout<<"Insert the divisor and the divident number and the name for the fraction: ";
    cin>>x>>y>>name;
    a.SetAll(x,y,name);
    cout<<a.GetA()<<"/"<<a.GetB()<<" "<<a.GetName()<<endl;
    Fraction c(a);
    b.Display();
    //c.Display();
    cout<<c.GetA()<<"/"<<c.GetB()<<" "<<c.GetName()<<endl;



    return 0;
}