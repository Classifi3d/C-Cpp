//MusteaDan Lab08 Grupa 2013
#include <iostream>

using namespace std;

class Count{
    public:
    int var;
    static int var_stat;
    Count(){
        this->var_stat++;
    }
    void GetVarStat(){
        cout<<this->var_stat<<endl;
    }

};

int Count::var_stat;

int main(){
    Count c1,c2,c3;
    c3.GetVarStat();

    return 0;
}