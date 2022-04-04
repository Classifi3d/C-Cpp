//MusteaDan Lab11 Grupa 2013
#include <iostream>

using namespace std;

class Animal{
public:
    virtual void breath()=0;
    virtual void eat(){
        cout<<"EAT"<<endl;
    };
    virtual void sleep(){
        cout<<"SLEEP"<<endl;
    }
};

class Dog : public Animal{
public:
    void breath(){
        cout<<"DOG BREATH"<<endl;
    }
    void eat(){
        cout<<"DOG EAT"<<endl;
    }
};

class Fish : public Animal{
public:
    void breath(){
        cout<<"FISH BREATH"<<endl;
    }
    void sleep(){
        cout<<"FISH SLEEP"<<endl;
    }
};

int main(){
    Animal* a[3];
    a[0] = new Dog();
    a[1] = new Fish();
    a[2] = new Dog();
    a[0]->breath();
    a[1]->eat();
    a[2]->sleep();
    cout<<"==========="<<endl;
    Dog b;
    b.breath();
    b.eat();
    b.sleep();
    Fish c;
    c.breath();
    c.eat();
    c.sleep();

    return 0;
}