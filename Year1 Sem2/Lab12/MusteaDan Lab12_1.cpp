//Mustea Dan Lab12 Group: 2013
#include <iostream>
using namespace std;

int main(){

cout<<"Insert two values which will be displayed in different base systems: ";
int val1,val2;
cin>>val1>>val2;
cout.width(15);
cout.fill('=');
cout.precision(10);
cout.setf(ios::right);
cout<<"dec:"<<val1<<" "<<val2<<endl;
cout.unsetf(ios::dec);
cout.setf(ios_base::hex);
cout.width(15);
cout.fill('=');
cout.unsetf(ios::right);
cout.setf(ios::left);
cout<<"hex:"<<val1<<" "<<val2<<endl;
cout.unsetf(ios::hex);
cout.setf(ios::oct);
cout.width(15);
cout.fill('=');
cout.unsetf(ios::left);
cout.setf(ios::right);
cout<<"oct:"<<val1<<" "<<val2<<endl;
cout.unsetf(ios::oct);

return 0;
}