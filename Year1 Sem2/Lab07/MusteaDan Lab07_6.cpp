//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

class Complex{
    private:
    double real,imag;
    char* name;
    int nameLength=7;
    public:
    Complex(){
        cout<<"Explicit"<<endl;
        this->real=1.0;
        this->imag=1.0;
        this->name=new char[7];
        //this->name=(char*) malloc(7);
    }
    Complex(double real,double imag,char Name[7]){
        cout<<"Parameters"<<endl;
        nameLength=strlen(Name)+1;
        this->name=new char[nameLength];
        this->real=real;
        this->imag=imag;
        strcpy(this->name,Name);
    }
    Complex(const Complex &num){
        cout<<"Copy"<<endl;
        this->name=new char[nameLength];
        this->real=num.real;
        this->imag=num.imag;
        strcpy(this->name,num.name);
    }
    ~Complex(){
        cout<<"Destructor"<<endl;
        delete[] name;
    }
    void SetImag(int imag){
        this->imag=imag;
    }
    void SetReal(int real){
        this->real=real;
    }
    void SetName(char name[7]){
        nameLength=strlen(name)+1;
        strcpy(this->name,name);
    }
    int GetImag(){
        return this->imag;
    }
    int GetReal(){
        return this->real;
    }
    char* GetName(){
        return this->name;
    }
    void Addition(const Complex &num){
        this->real+=num.real;
        this->imag+=num.imag;
    }
    void Substraction(const Complex &num){
        this->real-=num.real;
        this->imag-=num.imag;
    }
    void Multiply(const Complex &num){
        int rl,im;
        rl=(-1)*(this->imag*num.imag + this->real*num.real);
        im=this->imag*num.real+num.imag*this->real;
        this->imag=im;
        this->real=rl;
    }
    void Differentiate(const Complex &num){
        int rl,im;
        rl=(-1)*(this->imag/num.imag + this->real/num.real);
        im=this->imag/num.real+this->real/num.imag;
        this->imag=im;
        this->real=rl;
    }
};

int main(){
    Complex num[10];
    Complex complex_sum(0,0,"sum"),complex_sub(0,0,"sub"),complex_mul(1,1,"mul"),complex_dif(1,1,"dif");
    srand(NULL);
    for(int i=0;i<10;i++){
        num[i].SetImag(rand()%10);
        num[i].SetReal(rand()%10);
        char ch[4]; 
        ch[0]='a'+rand()%26;
        ch[1]='a'+rand()%26;
        ch[2]=rand()%9;
        ch[3]= '\0';
        num[i].SetName(ch);
        cout<<num[i].GetReal()<<" "<<num[i].GetImag()<<" "<<num[i].GetName()<<endl;
        complex_sum.Addition(num[i]);
        complex_sub.Substraction(num[i]);
        complex_mul.Multiply(num[i]);
        complex_dif.Differentiate(num[i]);
    }
    cout<<complex_sum.GetReal()<<" "<<complex_sum.GetImag()<<" "<<complex_sum.GetName()<<endl;
    cout<<complex_sub.GetReal()<<" "<<complex_sub.GetImag()<<" "<<complex_sub.GetName()<<endl;
    cout<<complex_mul.GetReal()<<" "<<complex_mul.GetImag()<<" "<<complex_mul.GetName()<<endl;
    cout<<complex_dif.GetReal()<<" "<<complex_dif.GetImag()<<" "<<complex_dif.GetName()<<endl;

    return 0;
}