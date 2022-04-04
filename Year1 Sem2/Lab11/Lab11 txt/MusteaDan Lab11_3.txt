#include <iostream>
using namespace std;

class Vehicul
{
    int roti;
    float greutate;

public:
    void SetGreutate(float greutate){
        this->greutate=greutate;
    }
    float GetGreutate(){
        return this->greutate;
    }
    void SetRoti(int roti){
        this->roti=roti;
    }
    int GetRoti(){
        return this->roti;
    }
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

int main()
{
    // apel direct, prin intermediul unor obiecte specifice
    Vehicul monocicleta;
    Automobil ford;
    Camion semi;
    Barca barca_de_pescuit;
    monocicleta.mesaj();
    ford.mesaj();
    semi.mesaj(); //din Vehicul ca si CB
    barca_de_pescuit.mesaj();
    // apel prin intermediul unui pointer specific
    Vehicul *pmonocicleta;
    Automobil *pford;
    Camion *psemi;
    Barca *pbarca_de_pescuit;
    cout << "\n";
    pmonocicleta = &monocicleta;
    pmonocicleta->mesaj();
    pford = &ford;
    pford->mesaj();
    psemi = &semi;
    psemi->mesaj(); //din CB
    pbarca_de_pescuit = &barca_de_pescuit;
    pbarca_de_pescuit->mesaj();
    // apel prin intermediul unui pointer catre un obiect al clasei de baza
    cout << "\n";
    pmonocicleta = &monocicleta;
    pmonocicleta->mesaj();            //Vehicul
    pmonocicleta = &ford;             //upcasting
    pmonocicleta->mesaj();            //Automobil
    pmonocicleta = &semi;             //upcasting
    pmonocicleta->mesaj();            //Vehicul
    pmonocicleta = &barca_de_pescuit; //upcasting
    pmonocicleta->mesaj();
    
    Camion *OptimusPrime;
    OptimusPrime->SetRoti(10);
    OptimusPrime->SetGreutate(15000);
    cout<<OptimusPrime->GetRoti()<<" "<<OptimusPrime->GetGreutate()<<endl;

    return 0;
}