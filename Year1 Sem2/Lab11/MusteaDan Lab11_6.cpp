//MusteaDan Lab11 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000

class Combine{
protected:
    char ar1[MAX];
    char ar2[MAX];
public:
    virtual char* Concat()=0;
    virtual char* Interlace()=0;
    virtual char* Revert()=0;
};

class Methods : public Combine{
private:
    char* strrev(char* array){
        int n=strlen(array);
        char rev[MAX];
        for(int i=0;i<n;i++){
            rev[n-i-1]=array[i];
        }
        rev[n+1]='\0';
        //cout<<rev<<endl;
        return rev;
    }
    char* interweave(char* array1,char* array2){
        int count[64]={0};
        int n=strlen(array1);

        for(int i=0;i<n;i++){
            if((array1[i]>='A' && array1[i]<='Z')||(array1[i]>='a' && array1[i]<='z')){
                count[array1[i]-'A']++;
            }
        }
        
        int m=strlen(array2);
        for(int i=0;i<m;i++){
            if((array2[i]>='A' && array2[i]<='Z')||(array2[i]>='a' && array2[i]<='z')){
                count[array2[i]-'A']++;
            }
        }
        /*for(int i=0;i<64;i++){
            cout<<(char)(i+'A')<<" "<<count[i]<<endl;
        }*/
        //cout<<n<<" "<<m<<endl;
        char combine[n+m+2];
        int k=0;
        for(int i=0;i<64;i++){
            while(count[i]>0){
                combine[k++]=(char)(i+'A');
                count[i]--;
            }
        }
        combine[n+m]='\0';
        //cout<<combine<<endl;
        return combine;
    }
public:
    Methods(char *a,char *b){
        strcpy(ar1,a);
        strcpy(ar2,b);
    }
    char* Concat(){
        return strcat(ar1,ar2);
    }
    char * Interlace(){
        return interweave(ar1,ar2);
    }
    char * Revert(){
        return strrev(ar1);
    }

};



int main(){
    char a[MAX],b[MAX];
    cout<<"Insert two character arrays you wish to modify: ";
    cin.get(a,MAX);
    cin.get();
    cin.get(b,MAX);
    cin.get();
    Methods x(a,b);
    cout<<x.Concat()<<endl;
    cout<<x.Revert()<<endl;
    cout<<x.Interlace()<<endl;

    return 0;
}