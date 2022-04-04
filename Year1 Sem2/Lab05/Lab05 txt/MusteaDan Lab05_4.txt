//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class Number{
    private:
    public:
        int val=0;
        int sum(int externalNum){
            return val+externalNum;
        }
        int sumExt(int externalNum);
};

int Number::sumExt(int externalNum){
return val+externalNum;
};

int main(){

    Number n1,n2;
    Number* p=&n1;
    cout<<"Insert the values for the two numbers: ";
    cin>>p->val>>n2.val;
    cout<<"The numbers are: "<<p->val<<" and "<<n2.val<<", and their sum is "<<n2.sum(p->val)<<" (or with the 2nd method "<<n2.sumExt(p->val)<<")"<<endl;

    return 0;
}