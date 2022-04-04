//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define MAX 64
#define MAX_INT 21

class Student{
	private:
	char firstName[MAX], lastName[MAX],marks[MAX_INT];
    int group=0;
    float avgMark=0;
	public://,char* lastName,int *marks){
    ~Student(){
        cout<<"Memeory Dealocated"<<endl;
        delete[] firstName;
        delete[] lastName;
        delete[] marks;
    }
	void SetStudent(char* firstName,char * lastName,char * marks,int group){
		if(firstName!=NULL){
			strncpy(this->firstName,firstName,MAX-1);
		}else{
			strcpy(this->firstName,"REDACTED");
		}
		if(lastName!=NULL){
			strncpy(this->lastName,lastName,MAX-1);
		}else{
			strcpy(this->lastName,"REDACTED");
		}
        if(marks!=NULL){
			strncpy(this->marks,marks,MAX_INT-1);
		}else{
			strcpy(this->marks,"0");
		}
        this->group=group;

		SetAvgMark();
	}
    void SetAvgMark(){
        int n=strlen(this->marks);
        int sum=0;
        for(int i=0;i<n;i++){
            if(marks[i]>='a' && marks[i]<='z'){
                sum+=this->marks[i]-48;
            }
        }
        this->avgMark=(float)((float)sum/n);
    }
	void DisplayStudentAll(){
		cout<<this->firstName<<" "<<this->lastName<<" "<<this->avgMark<<" "<<this->group<<endl;
	}
	int GetAvgMark(){
		return this->avgMark;
	}
};

void ReadMarks(int n,char marks[MAX_INT]){
    int x;
    char MARK[MAX_INT]="";
    for(int i=0;i<n;i++){
        char ar[3];
        cin>>x;
        if(x>=10){
            ar[0]='1';
            ar[2]='0';
            ar[3]='\0';
        }else{
            ar[0]=(char)x;
            ar[1]='\0';
        }
        strcat(MARK,ar);
    }   
    strcpy(marks,MARK);
}

int partition(int order[MAX_INT],float mark[MAX_INT],int l,int h){
    float pivot=mark[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(mark[j]<pivot){
            i++;
            swap(mark[i],mark[j]);
            swap(order[i],order[j]);
        }
    }
    swap(mark[i+1],mark[h]);
    swap(order[i+1],order[h]);
    return (i+1);
}

void quickSort(int order[MAX_INT],float mark[MAX_INT],int l,int h){
    int pi;
    if(l<h){
        pi=partition(order,mark,l,h);
    }
    quickSort(order,mark,l,pi-1);
    quickSort(order,mark,pi+1,h);
}

int main(){
    Student* p;
    int n,order[MAX_INT];
    float mark[MAX_INT];
    cout<<"Insert the number of students you want to insert"<<endl;
    cin>>n;
    
    p=(Student*)malloc(n*sizeof(Student));
    if(p==NULL) exit(1);//terminates the program and returns 1 for error
    for(int i=0;i<n;i++){
        char firstName[MAX],lastName[MAX],marks[MAX_INT];
        int group,numOfMakrs=0;
        cout<<"Insert the information (firstname/lastname/num of mark/marks/group) for student "<<i+1<<": "<<endl;
        cin>>firstName;
        cin>>lastName;
        cin>>numOfMakrs;
        ReadMarks(numOfMakrs,marks);
        cin>>group;
        p[i].SetStudent(firstName,lastName,marks,group);
        p[i].DisplayStudentAll();
        order[i]=i;
        mark[i]=p[i].GetAvgMark();
    }
    
    quickSort(order,mark,0,n-1);
    for(int i=0;i<n;i++){
        p[order[i]].DisplayStudentAll();
    }

    free(p);

    return 0;
}

// 4 a b 4 9 8 7 8 2013 c d 3 9 10 10 2013 e f 4 2 1 5 6 2013 g h 3 6 5 6 2014