//MusteaDan Lab08 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

class Motherboard{
    private:
    char processorName[128];
    public:
    class Calculator{
        private:
        int RAM_memory;
        public:
        void Set(int amount){
            this->RAM_memory=amount;
        }
        int Get(){
            return this->RAM_memory;
        }
        friend void ServiceTechnician(int amountOfRam,char procName);
    };
    void ServiceTechnician(int amountOfRam,char* procName,Calculator &C){
        strcpy(this->processorName,procName);
        C.Set(amountOfRam);
    }
    void Display(Calculator C){
        cout<<this->processorName<<" "<<C.Get()<<endl;
    }
};

int main(){
    Motherboard M;
    Motherboard::Calculator C;
    M.Display(C);
    M.ServiceTechnician(16,"AMD RYZEN 7",C);
    M.Display(C);
    return 0;
}