//MusteaDan Test
#include <iostream>

using namespace std;

#define MAX 10

class Complex{
    private:
    int length;
    int *real,*imag;
    public:
    Complex(){
        //no parameters
        this->length=MAX;
        this->real=new int[MAX];
        this->imag=new int[MAX];
    }
    Complex(int length){
        //parameters
        this->length=length;
        this->real=new int[length];
        this->imag=new int[length];
    }
    Complex(const Complex &a){
        this->length=a.length;
        for(int i=0;i<a.length;i++){
            this->real[i]=real[i];
        }
        for(int i=0;i<a.length;i++){
            this->imag[i]=imag[i];
        }
    }
    void SetLength(int length){
        this->length=length;
    }
    int GetLength(){
        return this->length;
    }
    void SetRealAndImag(int* real,int* imag){
        for(int i=0;i<this->length;i++){
            this->real[i]=real[i];
        }
        for(int i=0;i<this->length;i++){
            this->imag[i]=imag[i];
        }

    }
    void Display(){
        for(int i=0;i<this->length;i++){
            cout<<"real: "<<this->real[i]<<" imag: "<<this->imag[i]<<endl;
        }    cout<<"========================"<<endl;
    }
    Complex Sum(const Complex &a,int newLength){
        Complex result;
        for(int i=0;i<newLength;i++){
            result.imag[i]=a.imag[i]+this->imag[i];
            result.real[i]=a.real[i]+this->real[i];
        }
        result.length=newLength;
        return result;
    }
    Complex Sub(const Complex &a,int newLength){
        Complex result;
        for(int i=0;i<newLength;i++){
            result.imag[i]=this->imag[i]-a.imag[i];
            result.real[i]=this->real[i]-a.real[i];
        }
        result.length=newLength;
        return result;
    }
    /*
    void SortArrayAsc(){
        qsort(this->real,this->length,sizeof(int),intCompare);
    }
    void SortArrayDesc(){
        quick_sort_desc(this->imag,0,this->length-1);
    }*/
    
};

int intCompare(const void *a,const void *b);
int SmallestLength(int a,int b);
void quick_sort_desc(int array[MAX],int start,int end);
int partition(int array[MAX],int start,int end);
int main(){

    Complex a,b,c,d;
    srand(NULL);
    int n,m;
    //first object random generated arrays
    cout<<"Insert the length of the generated arrays(max 10): ";
    cin>>n;
    if(n>10&&n>0){
        n=10;
    }
    int imag1[MAX],real1[MAX];
    for(int i=0;i<n;i++){
        imag1[i]=rand()%1000;
        real1[i]=rand()%1000;
    }
    a.SetLength(n);
    a.SetRealAndImag(real1,imag1);
    a.Display();
    //second object random generated arrays
    cout<<"Insert the length of the generated arrays(max 10): ";
    cin>>m;
    if(m>10&&m>0){
        m=10;
    }
    int imag2[MAX],real2[MAX];
    for(int i=0;i<m;i++){
        imag2[i]=rand()%1000;
        real2[i]=rand()%1000;
    }
    b.SetLength(m);
    b.SetRealAndImag(real2,imag2);
    b.Display();
    int len=SmallestLength(a.GetLength(),b.GetLength());//smallest length of the two arrays
    /*b.SortArrayDesc();
    a.Display();
    b.Display();*/
    c=a.Sum(b,len);
    c.Display();
    //ascending sort
    qsort(real1,len,sizeof(int),intCompare);
    qsort(imag1,len,sizeof(int),intCompare);
    a.SetLength(len);
    a.SetRealAndImag(real1,imag1);
    //descending sort
    quick_sort_desc(imag2,0,len-1);
    quick_sort_desc(real2,0,len-1);
    b.SetLength(len);
    a.SetRealAndImag(real2,imag2);
    d=a.Sub(b,len);
    //sorted arrays sum
    cout<<"==== Sorted arrays ===== "<<endl;
    d.Display();
    

    return 0;
}

int SmallestLength(int a,int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
}

int intCompare(const void *a,const void *b){
	int A=*(int *)a;
	int B=*(int *)b;
	return A-B;
}

void quick_sort_desc(int *array,int start,int end){
	if(start<end){
		int index=partition(array,start,end);
		quick_sort_desc(array,start,index);
		quick_sort_desc(array,index+1,end);
	}
}

int partition(int *array,int start,int end){
	int index=array[start];
	int i=start;
	for(int j=start+1;j<=end;j++){
		if(array[j]>index){
			i++;
			int aux=array[i];
			array[i]=array[j];
			array[j]=aux;
		}
	}
	int aux=array[i];
	array[i]=array[start];
	array[start]=aux;
	return i;
}