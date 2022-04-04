//MusteaDan Lab06 Grupa 2013
#include <iostream>

using namespace std;

class Test2{
    private:
    int x;
    Test2( ){
    cout<<"Apel constructor explicit vid."<<endl;
    }
    Test2(int x){
        this->x=x;
        cout<<"Contructor called with variable"<<endl;
    }
    public:
    static Test2 Constructor(int);
    static Test2* PointerConstructor(int);

};

Test2 Test2::Constructor(int x){
    return Test2(x);
}

Test2* Test2::PointerConstructor(int x){
    cout<<"POINTER!!!"<<endl;
    return new Test2(x);//!REMBER THIS!!!
}

int main(){
    int a;
    cout<<"Introduceti valoarea variabilei de tip \"int\" din clasa: "<<endl;
    cin>>a;
    Test2 A = Test2::Constructor(a);
    Test2* p = Test2::PointerConstructor(a) ;



    return 0;
}