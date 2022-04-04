//MusteaDan Lab11 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

//header_1.h
class Baza
{
protected:
    int x;

public:
    Baza()
    {
        cout << "Apel la constructorul clasei de baza\n";
        x = 10;
    }
}; // clasa de baza
class Derivata1 : virtual public Baza
{
public:
    Derivata1()
    {
        cout << "Apel la constructorul clasei Derivata1\n";
    }
};
class Derivata2 : virtual public Baza
{
public:
    Derivata2()
    {
        cout << "Apel la constructorul clasei Derivata2\n";
    }
};
class Derivata1si2 : public Derivata1, public Derivata2
{
public:
    Derivata1si2()
    {
        cout << "Apel la constructorul clasei Derivata1si2\n";
    }
};

//header_2.h
enum Color
{
    Co_red,
    Co_green,
    Co_blue
};
// clasa de baza abstracta
class Shape
{
protected:
    int xorig;
    int yorig;
    Color co;

public:
    Shape(int x, int y, Color c) : xorig(x), yorig(y), co(c) {}
    virtual ~Shape() {}      // destructor virtual
    virtual void draw() = 0; // metoda virtuala pura
};
// O metoda virtuala pura face clasa in care apare ca fiind clasa abstracta.
// Metoda virtuala pura trebuie definita in clasele derivate sau redeclarata ca
//metoda virtuala pura in clasele derivate.
// clasa Line (intre origine si un punct destinatie)
class Line : public Shape
{
    int xdest;
    int ydest;

public:
    Line(int x, int y, Color c, int xd, int yd) : xdest(xd), ydest(yd), Shape(x, y, c) {}
    ~Line() { cout << "~Linie\n"; } // destructor virtual
    void draw()                     // metoda virtuala
    {
        cout << "Linie"
             << "(";
        cout << xorig << ", " << yorig << ", " << int(co);
        cout << ", " << xdest << ", " << ydest;
        cout << ")\n";
    }
};
// Clasa Circle : cerc cu raza
class Circle : public Shape
{
    int raza;

public:
    Circle(int x, int y, Color c, int r) : raza(r), Shape(x, y, c) {}
    ~Circle() { cout << "~Cerc\n"; } // destructor virtual
    void draw()                      // metoda virtuala
    {
        cout << "Cerc"
             << "(";
        cout << xorig << ", " << yorig << ", " << int(co);
        cout << ", " << raza;
        cout << ")\n";
    }
};
// Clasa Text : text
class Text : public Shape
{
    char *str;

public:
    Text(int x, int y, Color c, const char *s) : Shape(x, y, c)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    ~Text()
    {
        delete[] str;
        cout << "~Text\n";
    }           // destructor virtual
    void draw() // metoda virtuala
    {
        cout << "Text"
             << "(";
        cout << xorig << ", " << yorig << ", " << int(co);
        cout << ", " << str;
        cout << ")\n";
    }
};

//header_3.h
class Vehicul
{
    int roti;
    float greutate;

public:
    virtual void mesaj()
    {
        cout << "Mesaj din clasa Vehicul\n";
    }
};
class Automobil : public Vehicul
{
    int incarcatura_pasageri;

public:
    void mesaj()
    {
        cout << "Mesaj din clasa Automobil\n";
    }
};
class Camion : public Vehicul
{
    int incarcatura_pasageri;
    float incarcatura_utila;

public:
    int pasageri()
    {
        return incarcatura_pasageri;
    }
};
class Barca : public Vehicul
{
    int incarcatura_pasageri;

public:
    int pasegeri()
    {
        return incarcatura_pasageri;
    }
    void mesaj()
    {
        cout << "Mesaj din clasa Barca\n";
    }
};

//#include <header_1.h>
//#include <header_2.h>
//#include <header_3.h>

//main_file.cpp
int main()
{
    Barca a;
    a.mesaj();
    Derivata1 b;
    Text c(1,2,Co_red,"Cerc1");
    c.draw();
    
    return 0;
}