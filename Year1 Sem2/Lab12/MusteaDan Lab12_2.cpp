//Mustea Dan Lab12 Group: 2013
#include <iostream>

using namespace std;

int main(){

    int i;
    float f;
    char c;
    cout<<"Insert a int,float and char variable respectively: ";
    cin>>i>>f>>c;
    cout.setf(ios::dec);
    cout.width(5);
    cout.fill('i');
    cout<<i<<endl;
    cout.width(5);
    cout.fill('f');
    cout<<f<<endl;
    cout.width(5);
    cout.fill('c');
    cout<<c<<endl;

    return 0;
}