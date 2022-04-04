const int MAX = 30; //nr. caractere
const int dim = 5;  //nr. obiecte implicit

#include <cstddef>
#include <cstring>

class Analize;
    class Pers
    {
        //date personale
        char nume[MAX];
        double greutate;
        int varsta;
        friend class Analize;
        //metoda de afisare

        void SetNume(){
            //the name variable cannot be incorrect since real names can have numbers and other characters in them as well ex:Elon Musks'son  
            cin>>this->nume;
        }
        void SetGreutate(){ 
            int weight;
            cin>>weight;
            while (weight<0)
            {
                cout<<"Invalid weight!\nIntroduce another value:";
                cin>>weight;
            }
            
            this->greutate=weight;
        }
        void SetVarsta(){
            int age;  
            cin>>age;
            while (age<0)
            {
                cout<<"Invalid weight!\nIntroduce another value:";
                cin>>age;
            }
            this->varsta=age;
        }
        Pers(){
            this->greutate=0;
            this->varsta=0;
            strcpy(this->nume," ");
        }
        Pers(const Pers &a){
            this->greutate=a.greutate;
            strcpy(this->nume,a.nume);
            this->varsta=a.varsta;
        }
        ~Pers(){
            delete[] nume;
            delete &greutate;
            delete &varsta;
        }
        Pers operator=(const Pers &a){
            this->varsta=a.varsta;
            this->greutate=a.greutate;
            strcpy(this->nume,a.nume);
        }
    public:
        void tip();
    }; // Pers
void Pers::tip()
{
    if (this)
        cout << "\nPersoana : " << nume << "\tGreutatea : " << greutate << "\tVarsta : " << varsta;
    else
        cout << "\nNu exista obiect ";
}
class Analize
{
    Pers *sir;
    int n;

public:
    void GetN(){
        cout<<n;
    }
    //constructori
    Analize()
    {
        n = dim;
        sir = new Pers[dim];
    }
    Analize(int nr)
    {
        n = nr;
        sir = new Pers[n];
    }
    Analize(const Analize &a){
        this->n=a.n;
        this->sir=a.sir;
    }
    ~Analize(){
        delete sir;
        delete &n;
    }
    //Supraincarcare [ ]
    Pers *operator[](char *);
    Pers *operator[](double);
    Pers *operator[](int);
    void introdu();
}; //Analize
void Analize::introdu()
{
    cout << "\nIntrodu date :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Numele persoanei   " << (i + 1) << " : ";
        sir[i].SetNume();
        cout << "Greutatea : ";
        sir[i].SetGreutate();
        cout << "Varsta : ";
        sir[i].SetVarsta();

    }
} //introdu
//Indexare dupa nume
Pers *Analize::operator[](char *nume)
{
    for (int i = 0; i < n; i++)
        if (strcmp(sir[i].nume, nume) == 0)
            return &sir[i];
    return NULL;
} //op[ ]nume
//Indexare dupa greutate
Pers *Analize::operator[](double gr)
{
    for (int i = 0; i < n; i++)
        if (sir[i].greutate == gr)
            return &sir[i];
    return NULL;
} //op[ ]greutate
//Indexare dupa index
Pers *Analize::operator[](int index)
{
    if ((index >= 1) && (index <= n))
        return &sir[index - 1];
    else
    {
        cout << "\nIndex gresit";
        return NULL;
    }
} //op[ ]index


