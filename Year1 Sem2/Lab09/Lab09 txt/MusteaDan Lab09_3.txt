#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100



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
    void operator[](int pos){
        Employee emp;
        emp=lista[pos-1];
        cout<<"Employee Nr. "<<pos-1<<" Salary:"<<emp.GetSalary()<<" Name:"<<emp.GetName()<<endl;
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
    void InsertMultipleEmpoyees(){
        int n;
        cout<<"Insert the number of emplyee you wish to enter: ";
        cin>>n;
        while(n>0){
            InsertEmployee();
            n--;
        }

    }
};




int main(){

Departament a;
a.InsertMultipleEmpoyees();
a[1];
}