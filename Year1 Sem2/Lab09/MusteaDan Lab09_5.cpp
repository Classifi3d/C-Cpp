#include <iostream>
#include <cstring>
#include<stdarg.h>
using namespace std;

#define MAX 50

int myFunction(int n_args, ...)
{
    va_list arguments;
    va_start(arguments, n_args);
    int product=va_arg(arguments, int);
    for(int i = 1; i < n_args; i++) {
        product*=va_arg(arguments, int);
    }
    va_end(arguments);
    return product;
}

int main(){
//the first paramater is the number of paramaters entered after than one!!!
cout<<myFunction(5,2,3,4,5,6)<<endl;
cout<<myFunction(1,2)<<endl;

}