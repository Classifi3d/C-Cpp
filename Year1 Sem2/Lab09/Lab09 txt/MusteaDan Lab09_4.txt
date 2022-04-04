#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50



class Departament{
private:
    class Employee{
        private:
            char name[MAX];
            float salary;
        public:
            void SetEmplyee(char *name,int salary){
                strcpy(this->name,name);
                this->salary=salary;
            }
            int GetSalary(){
                return this->salary;
            }
            char* GetName(){
                return this->name;
            }

    }lista[MAX];
    int numOfEmplyees=0;
public:
    Departament(int n){
        this->numOfEmplyees=n;
    }
    Departament(){
        cout<<"Constructor called!"<<endl;
    }
    void operator[](int pos){
        Employee emp;
        emp=lista[pos-1];
        cout<<"Employee Nr. "<<pos-1<<" Salary:"<<emp.GetSalary()<<" Name:"<<emp.GetName()<<endl;
    }
    void * operator new(size_t size){
        cout<<"!Overloading new operator with size: "<<size<<endl;
        void *a = malloc(size);
        return a;
    }
    void operator delete(void *p){
        cout<<"!Overloading delete operator"<<endl;
        free(p);
    }
    void InsertEmployee(){
        char name[MAX];
        int salary;
        cout<<"Insert Name: ";
        cin>>name;
        cout<<"Insert Salary: ";
        cin>>salary;
        lista[numOfEmplyees].SetEmplyee(name,salary);
        numOfEmplyees++;
        //delete[] name;
    }
    void InsertMultipleEmpoyees(int n){
        int i=0;
        while(i<n){
            InsertEmployee();
            i++;
        }

    }
};




int main(){
cout<<"Inset the number of employees you wish to enter: ";
int n;
cin>>n;
Departament *a=new Departament();
a->InsertMultipleEmpoyees(n);
delete a;

}