//MusteaDan Lab11 Grupa 2013
#include <iostream>

using namespace std;

class Military{
private:
public:
    virtual void sunt_milirtar(){
        cout<<"I'm in the military"<<endl;
    }
};

class Soldier : public Military{
public:
    void sunt_milirtar(){
        cout<<"I'm a soldier"<<endl;
    }
};

class Officer : public Military{
public:
    void sunt_milirtar(){
        cout<<"I'm a officer"<<endl;
    }
};

class Lieutenant : public Officer{
public:
    void sunt_milirtar(){
        cout<<"I'm a lieutenant"<<endl;
    }
};

class Colonel : public Officer{
public:
    void sunt_milirtar(){
        cout<<"I'm a colonel"<<endl;
    }
};

class Captain : public Officer{
public:
    void sunt_milirtar(){
        cout<<"I'm a captain"<<endl;
    }
};

class General : public Officer{
public:
    void sunt_milirtar(){
        cout<<"I'm a general"<<endl;
    } 
};


int main(){

Military a;
Soldier b;
Officer c;
Lieutenant d;
Captain e;
General f;

a.sunt_milirtar();
b.sunt_milirtar();
c.sunt_milirtar();
d.sunt_milirtar();
e.sunt_milirtar();
f.sunt_milirtar();

    return 0;
}