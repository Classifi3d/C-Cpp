//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class Fraction{
    private:
        int a=0,b=0;
    public:
        void SetTop(int a){
            this->a=a;
        }
        void SetBottom(int b){
            this->b=b;
        }
        int GetTop(){
            return this->a;
        }
        int GetBottom(){
            return this->b;
        }
        double Simplify(){
            return ((double)this->a/this->b);
        }



};

int main(){
    Fraction x,y;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    //getters before setters
    cout<<" ===getters before setters ==="<<endl;
    cout<<x.GetTop()<<"/"<<x.GetBottom()<<endl;
    cout<<y.GetTop()<<"/"<<y.GetBottom()<<endl;
    //the setters
    x.SetTop(a);
    x.SetBottom(b);
    y.SetTop(c);
    y.SetBottom(d);
    //the getters after the setters
    cout<<" === the getters after the setters ==="<<endl;
    cout<<x.GetTop()<<"/"<<x.GetBottom()<<endl;
    cout<<y.GetTop()<<"/"<<y.GetBottom()<<endl;
    //simplified
    cout<<" === simplified ==="<<endl;
    cout<<x.Simplify()<<endl;
    cout<<y.Simplify()<<endl;

    
    return 0;
}