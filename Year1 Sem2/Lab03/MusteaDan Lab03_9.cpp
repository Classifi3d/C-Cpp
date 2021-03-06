#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MAX 1000

struct searchKey{
    char name[MAX];
    char path[MAX];
    int resolution;
    int bytes;
};

float similaritySystemStrings(char a[MAX],char b[MAX]){
    int lenA=strlen(a);
    int lenB=strlen(b);
    int maxLen=0;

    if(lenA>lenB){
        maxLen=lenA;
    }else{
        maxLen=lenB;
    }

    int differenceCounter=0;
    for(int i=0;i<maxLen;i++){
        if(a[i]!=b[i]){
            differenceCounter++;
        }
    }

    float similarityProcentile;
    similarityProcentile=((float)maxLen/(float)differenceCounter);
    return similarityProcentile;
}

float similaritySystemIntegers(int a,int b){
    int smallNum,highNum;
    if(a<b){
        smallNum=a;
        highNum=b;
    }else{
        smallNum=b;
        highNum=a;
    }

    float similiarityProcentile;
    similiarityProcentile=((float)smallNum/(float)highNum);
    return similiarityProcentile;
}

float similaritySystemSerachKey(searchKey A,searchKey B){
    float similarityOverall;
    similarityOverall=(float)((similaritySystemStrings(A.name,B.name)+
                               similaritySystemStrings(A.path,B.path)+
                               similaritySystemIntegers(A.bytes,B.bytes)+
                               similaritySystemIntegers(A.resolution,B.resolution)
                              )/4
                             );
    return similarityOverall;
}

void insertImages(char library[MAX][MAX],int &length){
    bool ok=true;
    cout<<"Insert the image name: ";
    char image[MAX];
    int counter=-1;
    while(ok==true){
        cin>>image;
        counter++;
        strcpy(library[counter],image);
        cout<<"Do you want to add another image?"<<endl;
        cin>>ok;
    }
    length=counter;
}

void insertImageCompareCritiria(searchKey A){
    cout<<"Insert the search parameters for the image you want to find"<<endl;
    //name
    cout<<"Insert a name: ";
    cin>>A.name;
    //path
    cout<<"Insert a path: ";
    cin>>A.path;
    //resolution
    cout<<"Insert a resolution: ";
    cin>>A.resolution;
    //bytes
    cout<<"Insert a number of bytes: ";
    cin>>A.bytes;
}

int length(char str[MAX]){
    int i=0;
    while(str[i]!='.' || str[i]!='\0'){
        i++;
    }
    return i;
}

char* transform(char nameOriginal[MAX]){
    char name[MAX];
    strcpy(name,nameOriginal);
    int dotPosition=length(name);
    name[dotPosition]='.';
    name[dotPosition+1]='t';
    name[dotPosition+2]='x';
    name[dotPosition+3]='t';
    name[dotPosition+4]='\0';
    return name;
}


int main(){
    searchKey A;
    char library[MAX][MAX],image[MAX];
    int length;
    insertImages(library,length);
    insertImageCompareCritiria(A);//search parameters
    length++;

    char nameSave[MAX];
    float procentileSave=0.1f;
    for(int i=0;i<length;i++){
        searchKey B;
        char currentImgFile[MAX];
        strcpy(currentImgFile,transform(library[i]));
        //!cout<<"Before fin"<<endl;
        ifstream fin (currentImgFile);
        //!cout<<"After fin"<<endl;
        fin>>B.name;
        fin>>B.path;
        fin>>B.resolution;
        fin>>B.bytes;
        float procentileCurrent;
        //!cout<<"Before similiratiy search"<<endl;
        procentileCurrent=similaritySystemSerachKey(A,B);
        if(procentileCurrent>procentileSave){
            procentileSave=procentileCurrent;
            strcpy(nameSave,library[i]);
        }
        fin.close();
    }

    cout<<"With the closest proximity score of: "<<procentileSave<<endl;
    ifstream imageOpen;
    imageOpen.open(nameSave);

    return 0;
}