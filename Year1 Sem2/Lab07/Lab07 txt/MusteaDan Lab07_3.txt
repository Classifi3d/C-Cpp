//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500

class Student{
	private:
	char firstName[MAX], lastName[MAX];
	int marks;
	public://,char* lastName,int *marks){
	void SetStudent(char* firstName,char * lastName,int marks){
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
		this->marks=marks;
	}
	void GetStudentAll(){
		cout<<this->firstName<<" "<<this->lastName<<" "<<marks<<endl;
	}
	int GetMark(){
		return this->marks;
	}

};

void HighestThree(Student studentList[MAX],int n){
	int high[3]={0};
	int ind[3]={0};
	int aux=0;
	for(int i=0;i<n;i++){
		aux=studentList[i].GetMark();
		if(aux>high[2]){
			high[0]=high[1];
			high[1]=high[2];
			high[2]=aux;
			ind[0]=ind[1];
			ind[1]=ind[2];
			ind[2]=i;
		}else if(aux>high[1]){
			high[0]=high[1];
			high[1]=aux;
			ind[0]=ind[1];
			ind[1]=i;
		}else if(aux>high[0]){
			high[0]=aux;
			ind[0]=i;
		}
	}
	cout<<"First place: ";studentList[ind[2]].GetStudentAll();
	cout<<"Second place: ";studentList[ind[1]].GetStudentAll();
	cout<<"Third place: ";studentList[ind[0]].GetStudentAll();
}

void FailedExam(Student studentList[MAX],int n){
	for(int i=0;i<n;i++){	
		if(studentList[i].GetMark()<5){
			studentList[i].GetStudentAll();
		}
	}
}


int main(){
	Student studentList[1024];
	char firstName[MAX],lastName[MAX];
	int n,marks;
	cout<<"Insert the number of students in the group"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Insert the first name"<<endl;
		cin>>firstName;
		cout<<"Insert the last name"<<endl;
		cin>>lastName;
		cout<<"Insert the mark"<<endl;
		cin>>marks;
		studentList[i].SetStudent(firstName,lastName,marks);
	}
	cout<<"======== Highest Students ========"<<endl;
	HighestThree(studentList,n);
	cout<<"======== Failed Students ========="<<endl;
	FailedExam(studentList,n);
    return 0;
}