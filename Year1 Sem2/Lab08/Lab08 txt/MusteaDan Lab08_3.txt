//MusteaDan Lab08 Grupa 2013
#include <iostream>

using namespace std;

class Repository{
    private:
    int a,b;
    public:
    Repository(){
        a=0;
        b=0;
    }
    Repository(int a,int b){
        this->a=a;
        this->b=b;
    }
    void Get(){
        cout<<this->a<<" "<<this->b<<endl;
    }
    friend class Mathematics;
};

class Mathematics{
    public:
    Repository Sum(Repository x,Repository y){
        Repository aux;
        aux.a=x.a+y.a;
        aux.b=x.b+y.b;
        return aux;
    }
    Repository Substract(Repository x,Repository y){
        Repository aux;
        aux.a=x.a-y.a;
        aux.b=x.b-y.b;
        return aux;
    }
    Repository Multiply(Repository x,Repository y){
        Repository aux;
        aux.a=x.a*y.a;
        aux.b=x.b*y.b;
        return aux;
    }
    Repository Differentiate(Repository x,Repository y){
        Repository aux;
        aux.a=x.a/y.a;
        aux.b=x.b/y.b;
        return aux;
    }
};

int main(){
    Repository c,a(7,4),b(3,9);
    Mathematics r1;
    c=r1.Sum(a,b);
    c.Get();
    c=r1.Substract(a,b);
    c.Get();
    c=r1.Multiply(a,b);
    c.Get();
    c=r1.Differentiate(a,b);
    c.Get();
    
    return 0;
}