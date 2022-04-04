//MusteaDan Lab11 Grupa 2013
#include <iostream>

using namespace std;

class Pozitie
{
protected:
    int x, y;

public:
    Pozitie(int = 0, int = 0);
    Pozitie(const Pozitie &);
    ~Pozitie();
    //void afisare();
    //void deplasare(int, int);
    virtual void afisare();
    virtual void deplasare(int, int);
}; //CB
// constructor
Pozitie::Pozitie(int abs, int ord)
{
    x = abs;
    y = ord;
    cout << "Constructor CB \"Pozitie\", ";
    afisare();
}
//constructor de copiere
Pozitie::Pozitie(const Pozitie &p)
{
    x = p.x;
    y = p.y;
    cout << "Constructor de copiere CB \"Pozitie\", ";
    afisare();
}
// destructor
Pozitie::~Pozitie()
{
    cout << "Destructor CB \"Pozitie \", ";
    afisare();
}
void Pozitie::afisare()
{
    cout << " CB afisare: coordonate: x = " << x << ", y = " << y << "\n";
}
void Pozitie::deplasare(int dx, int dy)
{
    cout << "CB: deplasare" << endl;
    x += dx;
    y += dy;
}
// clasa derivata
class Punct : public Pozitie
{
    int vizibil;
    char culoare;

public:
    Punct(int = 0, int = 0, char = 'A');    
    Punct(const Punct &);
    ~Punct();
    void arata()
    {
        vizibil = 1;
    }
    void ascunde()
    {
        vizibil = 0;
    }
    void coloreaza(char c)
    {
        culoare = c;
    }
    void deplasare(int, int);
    void afisare();
}; //CD
// constructor
Punct::Punct(int abs, int ord, char c) : Pozitie(abs, ord)
{
    vizibil = 0;
    culoare = c;
    cout << "Constructor CD \"Punct\", ";
    afisare(); //CD
}
// constructor de copiere
Punct::Punct(const Punct &p) : Pozitie(p.x, p.y)
{
    vizibil = p.vizibil;
    culoare = p.culoare;
    cout << "Constructor de copiere CD \"Punct\", ";
    afisare(); //CD
}
// destructor
Punct::~Punct()
{
    cout << "Destructor CD \"Punct\", ";
    afisare(); //CD
}
// redefinire functie de deplasare in clasa derivata
void Punct::deplasare(int dx, int dy)
{
    if (vizibil)
    {
        cout << " CD: Deplasare afisare CD\n";
        x += dx;
        y += dy;
        afisare(); //CD
    }
    else
    {
        x += dx;
        y += dy;
        cout << "Deplasare prin CD afisare din CB\n";
        Pozitie::afisare();
    }
}
// redefinire metoda de afisare in clasa derivata
void Punct::afisare()
{
    cout << "Pozitie: x = " << x << ", y = " << y;
    cout << ", culoare: " << culoare;
    if (vizibil)
        cout << ", vizibil \n";
    else
        cout << ", invizibil \n";
}

class Cerc : public Pozitie{
public:
    Cerc(){
        cout<<"Constructor Cerc!"<<endl;
    }
    Cerc(const Cerc &a){
        cout<<"Constructor Cerc!"<<endl;
        this->x=a.x;
        this->y=a.y;
    }
    Cerc(int x,int y){
        cout<<"Constructor Cerc!"<<endl;
        this->x=x;
        this->y=y;
    }
    ~Cerc(){
        cout<<"Deconstructor Cerc!"<<endl;
    }

};

int main()
{
    //order of the constructors and deconstructors is construct pozitie then constructor punct then the respective destructors in reverse: punct then pozitie
    Pozitie a(1,2);
    Punct aux(3,10);
    a.afisare();
    a.deplasare(3,-4);
    a.afisare();
    Punct b(aux);
    b.afisare();
    b.ascunde();
    b.afisare();
    b.coloreaza('r');
    b.deplasare(3,0);
    b.arata();
    b.afisare();
    Cerc c(0,0);
    c.afisare();


    return 0;
}