#include <iostream>

using namespace std;


int main(){
    char textstring[sizeof(char)];
    cin>>textstring;

    int bin=0;
    for(int i=strlen(textstring);i>=0;i--){
        if(textstring[i]=='(') bin=pow(10,i)*1+bin;
        if(textstring[i]==')') bin=pow(10,i)*0+bin;
    }

    cout<<bin;

    return 0;
}