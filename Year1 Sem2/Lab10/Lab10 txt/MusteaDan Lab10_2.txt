//MusteaDan Lab10 Grupa 2013
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define MAX 1000

class base{
private:
    char array[MAX];
protected:
    char encrypt[MAX];
public:
    void Encrypt(){
        char key;
        int length;
        cout<<"Insert a charcter key to encrypt the message: ";
        cin>>key;
        length=strlen(this->array);
        for(int i=0;i<length;i++){
            encrypt[i]=(char)(key^array[i]);
        }
    }
    void Display(){
        cout<<"Original: "<<array<<endl
        <<"Encrypted: "<<encrypt<<" | numeral form: ";
        int length=strlen(encrypt);
        for(int i=0;i<length;i++){
            cout<<(int)encrypt[i]<<" ";
        }
        cout<<endl;
    }
    void SetArray(char *array){
        strcpy(this->array,array);
        Encrypt();
    }
};

class derived : public base{
private:
public:
    void Append(){
        ofstream fout ("date.out");
        fout<<encrypt;
        fout.close();
    }
};


int main(){
    char array[MAX];
    derived a;
    cout<<"Insert an array of characters: ";
    cin.get(array,MAX);
    cin.get();
    a.SetArray(array);
    cout<<"Choose an option for displaying the result (1-console display,2-file append display,0-exit)"<<endl;
    int option=0;
    cin>>option;
        
    switch(option){
        case 1:
            a.Display();
        break;
        case 2:
            a.Append();
        break;
        case 0:
            return 0;
        break;
        default:
            cout<<"Try again!"<<endl;

    }



    return 0;
}