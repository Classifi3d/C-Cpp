//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class Operations{
    private:
    public:
        int x,y;
        int plus(){
            return this->x+this->y;
        }
        int minus(){
            int minus=this->x-this->y;
            if(minus<0){
                return (-1)*minus;
            }else{
                return minus;
            }
        }
        int multiplication(){
            return this->x*this->y;
        }
        float divison(){
            if(y!=0){
                return (float)this->x/this->y;
            }else{
                try{
                    return this->x/this->y;
                }
                catch(int e){
                    return e;
                }
            }
        }
};


int main(){
    Operations a;
    cin>>a.x>>a.y;
    cout<<a.plus()<<endl;
    cout<<a.minus()<<endl;
    cout<<a.multiplication()<<endl;
    cout<<a.divison()<<endl;


    return 0;
}