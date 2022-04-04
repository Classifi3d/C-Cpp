//MusteaDan Lab05 Grupa 2013
#include <iostream>
#include "strClass.h"

using namespace std;

#define MAX 20000

int main(){
    char array[]="test string for this problem\n";
    char a='a';
    cout<<"";
    //String strConstructor(array);
    String str;
    str.setString(array);
    cout<<str.getString();
    cout<<str.getLength()<<endl;
    cout<<str.getLastOccurance('e');
    cout<<endl;
    cout<<str.getStringUpper();
    cout<<str.getLastOccuranceUpper('E');
    cout<<endl;
    return 0;
}