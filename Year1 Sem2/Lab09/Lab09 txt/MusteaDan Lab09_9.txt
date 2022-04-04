#include <iostream>

using namespace std;

class Number{
    private:
    double var;
    public:
    Number(){
        var=0;
    }
    Number(double var){
        this->var=var;
    }
    void Set(double n){
        var=n;
    }
    double Get(){
        return var;
    }
    Number operator+(Number &num){
        Number aux;
        aux.var=this->var+num.var;
        return aux;
    }
    Number operator-(Number &num){
        Number aux;
        aux.var=this->var-num.var;
        return aux;
    }
    Number operator*(Number &num){
        Number aux;
        aux.var=this->var*num.var;
        return aux;
    }
    Number operator/(Number &num){
        Number aux;
        aux.var=this->var/num.var;
        return aux;
    }

};

class Mathematics{
    private:
    Number num;
    public:
    Mathematics operator+(Mathematics &num){
        Mathematics aux;
        aux.num=this->num+num.num;
        return aux;
    }
    Mathematics operator-(Mathematics &num){
        Mathematics aux;
        aux.num=this->num-num.num;
        return aux;
    }
    Mathematics operator*(Mathematics &num){
        Mathematics aux;
        aux.num=this->num*num.num;
        return aux;
    }
    Mathematics operator/(Mathematics &num){
        Mathematics aux;
        aux.num=this->num/num.num;
        return aux;
    }
    Mathematics(){
        num.Set(0);
    }
    Mathematics(double n){
        num.Set(n);
    }
    void Display(){
        cout<<num.Get()<<endl;
    }
};



int main(){
    double x,y;
    cout<<"Insert the values of 2 real numbers: ";
    cin>>x>>y;
    Mathematics a(x),b(y);
    Mathematics c=a+b;
    Mathematics d=a-b;
    Mathematics e=a*b;
    Mathematics f=a/b;
    c.Display();
    d.Display();
    e.Display();
    f.Display();


    return 0;
}