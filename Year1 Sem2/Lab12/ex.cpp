//Mustea Dan Lab12 Group: 2013
#include <iostream>
using namespace std;
const int dim =30;
int main( )
{
// afisarea valorilor folosind poziţionarile implicite
cout<< 123.33 <<" salut! " << 100 <<'\n';
cout<< 10 << ' ' << -10 <<'\n';
cout << 100.01 <<'\n';
cout << 100.0 <<'\n';
cout<<"==================="<<endl;
// schimbam formatul
cout.unsetf(ios::dec);
cout.setf( ios_base::hex);
cout <<1024<< " "<<-1024<<endl;
cout.setf (ios::showpos);
cout <<1024<< " "<<-1024<<endl;
cout.setf (ios::showbase);
cout <<1024<< " "<<-1024<<endl;
cout.setf(ios::scientific);
cout <<1024.1<< " "<<-1024.1<<endl;
cout.unsetf(ios::scientific);
cout.setf(ios::dec|ios::showpoint);
cout <<1024<< " "<<-1024<<endl;
//alinieri
cout.width(dim);
cout.fill('*');
cout.setf(ios::right);
cout<<"Aliniere dreapta"<<'\n';
cout.unsetf(ios::right);
cout.width(dim);
cout.fill('*');
cout.setf(ios::left);
cout<<"Aliniere stanga"<<'\n';
return 0;
}