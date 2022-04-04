//MusteaDan Lab06 Grupa 2013
#include <iostream>

using namespace std;

class Test2{
    private:
    int x;
    Test2( ){
    cout<<"\nApel constructor explicit vid.";
    }
    Test2(int x){
        this->x=x;
        cout<<"Contructor called with variable";
    }
    public:
    static Test2 Constructor(int);

};

Test2 Test2::Constructor(int x){
    return Test2(x);
}


int main(){
    int a;
    cout<<"Introduceti valoarea variabilei de tip \"int\" din clasa: "<<endl;
    cin>>a;
    Test2 A = Test2::Constructor(a);



    return 0;
}