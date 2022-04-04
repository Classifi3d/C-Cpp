//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class Arithmetics{
    private:
        int a;
        float b;
    public:
        void SetArithmetics(int a,float b){
            this->a=a;
            this->b=b;
        }
        int GetArithmeticsA(){
            return this->a;
        }
        float GetArithmeticsB(){
            return this->b;
        }
        float Sum(){
            return this->a+this->b;
        }
        float Difference();
};

float Arithmetics::Difference(){
    int minus=this->a-this->b;
    if(minus<0){
          return (-1)*minus;
        }else{
           return minus;
    }
};

int main(){

    Arithmetics a,b,c;
    int x; float y;
    cin>>x>>y;  a.SetArithmetics(x,y);
    cin>>x>>y;  b.SetArithmetics(x,y);
    cin>>x>>y;  c.SetArithmetics(x,y);

    cout<<a.GetArithmeticsA()<<" "<<a.GetArithmeticsB()<<" - sum: "<<a.Sum()<<endl;
    cout<<b.GetArithmeticsA()<<" "<<b.GetArithmeticsB()<<" - difference: "<<b.Difference()<<endl;
    cout<<c.GetArithmeticsA()<<" "<<c.GetArithmeticsB()<<" - difference: "<<c.Difference()<<endl;

    return 0;
}