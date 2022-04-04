//MusteaDan Lab08 Grupa 2013
#include <iostream>

using namespace std;

class Count{
    private:
        static int var_stat;
    public:
    Count(){
        this->var_stat++;
    }
    void GetVarStat(){
        cout<<this->var_stat<<endl;
    }
    int GetPrivateVarStat(){
        return this->var_stat;
    }

};

int Count::var_stat;

int main(){
    Count c1,c2,c3;
    c3.GetVarStat();//original
    cout<<c3.GetPrivateVarStat()<<endl;//private

    return 0;
}