//MusteaDan Lab05 Grupa 2013
#include <iostream>
#include "strClass.h"

using namespace std;

#define MAX 10

int main(){
    char array[MAX];
    cin.get(array,MAX);
    cin.get();
    char target;
    cin>>target;
    cout<<"";

    String str;
    str.setString(array);
    cout<<"========================="<<endl;
    cout<<"length: "<<str.getLength()<<endl;
    cout<<"last occurance: "<<str.getLastOccurance(target)<<endl;
    cout<<"upper:"<<str.getStringUpper()<<endl;
    cout<<"upper last occurance: "<<str.getLastOccuranceUpper(target)<<endl;
    return 0;
}