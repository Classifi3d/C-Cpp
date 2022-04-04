//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MAX 1000

ifstream fin ("MusteaDan Lab04_3.txt");

struct record{
	char firstName[MAX];
	char lastName[MAX];
	int idCode;
	int employmentDate;
};

int structCmpByFirstName(const void *a, const void *b);
int structCmpByLastName(const void *a, const void *b);
int structCmpByIdCode(const void *a, const void *b);
int structCmpByEmloymentDate(const void *a, const void *b);

int main(){
	int n;
	record array[MAX];
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>array[i].firstName;
		fin>>array[i].lastName;
		fin>>array[i].idCode;
		fin>>array[i].employmentDate;
	}
	//original list
	cout<<"====== Original list ======"<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i].firstName<<" | ";
		cout<<array[i].lastName<<" | ";
		cout<<array[i].idCode<<" |  ";
		cout<<array[i].employmentDate<<" | "<<endl;
	}cout<<endl;
	cout<<"====== Sorted lists ======"<<endl;
	//first name sort
	qsort(array,n,sizeof(struct record),structCmpByFirstName);
	for(int i=0;i<n;i++){
		cout<<array[i].firstName<<" | ";
	}cout<<endl;

	//last name sort
	qsort(array,n,sizeof(struct record),structCmpByLastName);
	for(int i=0;i<n;i++){
		cout<<array[i].lastName<<" | ";
	}cout<<endl;

	//id code sort
	qsort(array,n,sizeof(struct record),structCmpByIdCode);
	for(int i=0;i<n;i++){
		cout<<array[i].idCode<<" | ";
	}cout<<endl;

	//employment date sort
	qsort(array,n,sizeof(struct record),structCmpByEmloymentDate);
	for(int i=0;i<n;i++){
		cout<<array[i].employmentDate<<" | ";
	}cout<<endl;

	fin.close();
	return 0;
}

int structCmpByIdCode(const void *a, const void *b){ 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return (int)(ia->idCode - ib->idCode);
}

int structCmpByEmloymentDate(const void *a, const void *b){ 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return (int)(ia->employmentDate - ib->employmentDate);
}

int structCmpByFirstName(const void *a, const void *b) { 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return strcmp(ia->firstName, ib->firstName);
}
int structCmpByLastName(const void *a, const void *b) { 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return strcmp(ia->lastName, ib->lastName);
}

//Compile Data
/*
3
Dan
Mustea
36
20000605
Cristian
Bota
23
20000203
Denis
Zilai
69
20000418
*/