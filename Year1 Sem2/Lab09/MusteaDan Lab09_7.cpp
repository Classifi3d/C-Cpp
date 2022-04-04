#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class Student{
private:
    char name[MAX];
    int* marks;
    int nr_marks;
public:
    Student(char* name,int* marks,int nr_marks){
        //constructor with paramtesrs
        strcpy(name,this->name);
        this->marks=marks;
        this->nr_marks=nr_marks;

    }
    Student(Student &a){
        //copy constructor
        strcpy(a.name,this->name);
        this->marks=a.marks;
        this->nr_marks=a.nr_marks;
    }
    /*~Student(){
        delete marks;
        delete &nr_marks;
        delete[] name;
    }*/
    void operator=(Student &a){
        //assign operator overload
        strcpy(a.name,this->name);
        this->marks=a.marks;
        this->nr_marks=a.nr_marks;
    }
    void MarkSetting(int* marks){
        this->marks=marks;
    }
    void Display(){
        cout<<"name:"<<name<<" "
        <<"number of marks: "<<nr_marks<<" "
        <<"marks: ";
        for(int i=0;i<nr_marks;i++){
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }




};

void readInfo(char* name,int *marks,int &n){

    cout<<"Insert the number of marks: ";
    cin>>n;
    cout<<"Insert the "<<n<<" marks: ";
    for(int i=0;i<n;i++){
        cin>>marks[i];
    }
    cout<<"Insert your name: ";
    cin>>name;
}

int main(){
    int marks[MAX],n;
    char name[MAX];
    readInfo(name,marks,n);
    cout<<endl;
    Student a(name,marks,n);
    a.Display();
    Student b(a);
    b.Display();
    readInfo(name,marks,n);
    cout<<endl;
    Student c(name,marks,n);
    c.Display();
    c=a;
    cout<<"AFTER ASSIGN!"<<endl;
    c.Display();
    
    return 0;
}