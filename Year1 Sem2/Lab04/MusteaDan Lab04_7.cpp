//Mustea Dan Lab04 Grupa 2013
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MAX 2000

ifstream fin ("MusteaDan Lab04_7.txt");

struct record{
	char name[MAX];
	char processor[MAX];
	long int frequency;
	int ram;
	float price;
};

int structCmpByName(const void *a, const void *b);
int structCmpByProcessor(const void *a, const void *b);
int structCmpByIdFrequency(const void *a, const void *b);
int structCmpByRam(const void *a, const void *b);
int structCmpByPrice(const void *a, const void *b);

int main(){
	int n;
	record array[MAX];
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>array[i].name;
		fin>>array[i].processor;
		fin>>array[i].frequency;
		fin>>array[i].ram;
		fin>>array[i].price;
	}
	//original list
	cout<<"====== Original list ======"<<endl;
	for(int i=0;i<n;i++){
		cout<<array[i].name<<" | ";
		cout<<array[i].processor<<" | ";
		cout<<array[i].frequency<<" |  ";
		cout<<array[i].ram<<" | ";
		cout<<array[i].price<<" | "<<endl;
	}cout<<endl;
	cout<<"====== Sorted lists ======"<<endl;
	//name sort
	qsort(array,n,sizeof(struct record),structCmpByName);
	for(int i=0;i<n;i++){
		cout<<array[i].name<<" | ";
	}cout<<endl;

	//processor sort
	qsort(array,n,sizeof(struct record),structCmpByProcessor);
	for(int i=0;i<n;i++){
		cout<<array[i].processor<<" | ";
	}cout<<endl;

	//frequency sort
	qsort(array,n,sizeof(struct record),structCmpByIdFrequency);
	for(int i=0;i<n;i++){
		cout<<array[i].frequency<<" | ";
	}cout<<endl;

	//ram sort
	qsort(array,n,sizeof(struct record),structCmpByRam);
	for(int i=0;i<n;i++){
		cout<<array[i].ram<<" | ";
	}cout<<endl;

	//price sort
	qsort(array,n,sizeof(struct record),structCmpByPrice);
	for(int i=0;i<n;i++){
		cout<<array[i].price<<" | ";
	}cout<<endl;

	fin.close();
	return 0;
}

int structCmpByName(const void *a, const void *b) { 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return strcmp(ia->name, ib->name);
}

int structCmpByProcessor(const void *a, const void *b) { 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return strcmp(ia->processor, ib->processor);
}

int structCmpByIdFrequency(const void *a, const void *b){ 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return (int)(ia->frequency - ib->frequency);
}

int structCmpByRam(const void *a, const void *b){ 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return (int)(ia->ram - ib->ram);
}
int structCmpByPrice(const void *a, const void *b){ 
    struct record *ia = (struct record*)a;
    struct record *ib = (struct record *)b;
    return (float)(ia->price - ib->price);
}
//Compile Data
/*
3
PC-1
AMD-Ryzen
350000
16
1499.99
PC-2
Intel-I9
420000
64
7000.00
PC-3
Intel-Pentium
210000
8
499.99
*/