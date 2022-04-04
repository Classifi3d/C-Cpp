//Mustea Dan Lab12 Group: 2013
#include <iostream>

using namespace std;

int main(){
    srand(2);
    
    float avg=0,treshold,mem[10];
    treshold=(float)rand()/1000000;//the treshold previously defined
    for(int i=0;i<10;i++){
        mem[i]=(float)rand();//data from the hardware device
        mem[i]/=1000000;
        avg+=mem[i];
    }
    avg/=10;
    if(avg>treshold){//data being displayed in detalied fromat (float with 8 digit precision)
        for(int i=0;i<10;i++){
            cout.precision(8);
            cout<<mem[i]<<endl;
        }
    }

    return 0;
}