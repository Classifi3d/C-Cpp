//MusteaDan Lab08 Grupa 2013
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 128
#define MAX_SMALL 64

class BookIndustry{
    private:
    class Product{
        private:
        char name[MAX_SMALL],editorialHouse[MAX_SMALL];
        int numOfPages=0,numOfCopies=0;
        float price=0;
        public: 
        void CreateProduct(char name[MAX_SMALL],char editorialHouse[MAX_SMALL],int numOfPages, int numOfCopies,float price){
            strcpy(this->name,name);
            strcpy(this->editorialHouse,editorialHouse);
            this->numOfPages=numOfPages;
            this->numOfCopies=numOfCopies;
            this->price=price;
        }
        char* GetEditorialHouse(){
            //get the name of the editorial house of the product
            return this->editorialHouse;
        }
        int GetNumOfPages(){
            //get the number of pages of a product
            return this->numOfPages;
        }
        int GetNumOfCopies(){
            //get the number of copies of a prodcut
            return this->numOfCopies;
        }
        float GetPrice(){
            //get the price of a product
            return this->price;
        }
    }Products[MAX];
    int n=0;//the number of products in the book industry
    int unique=0;//nonReaptingNumberOfEditingHouses
    static float VAT_value;
    double value[MAX];//the income of each unique editorial house
    int valueIndex[MAX];//the index of the first product encounter(and unique) so it can be use to reference the name of the editorial house
    bool visited[MAX];//a visited checked array so that the editorial houses don't repete
    void OrderWhileInsert(double NewValue,int i){
        //TODO orders the value vector with each calculation of a editorial house
        int k=0;//order dimension
        
    }
    public:
    BookIndustry();//constructor without paramter
    BookIndustry(int n){
        //constructor with parameter setting the total number of products in the book industry
        this->n=n;
    }
    void SetDimension(int n){
        //set the total number of products in the book industry
        this->n=n;
    }
    static void ModifyVAT(int NewVAT){
        VAT_value=NewVAT;
    }
    void CreateBookProduct(int index,char name[MAX_SMALL],char editorialHouse[MAX_SMALL],int numOfPages, int numOfCopies,float price){
        //auxiliary function for passing the information just inserted (read) to the Products array 
        Products[index].CreateProduct(name,editorialHouse,numOfPages,numOfCopies,price);
    }
    friend void ReadAllProducts(int n,BookIndustry &bk);//the friend array that reads the data from the keyboard
    int GetIncomeAll(){
        //total income and avg value per page (with VAT)
        //clear the current value array and unmarking the visited array
        for(int i=0;i<MAX;i++){
            value[i]=NULL;
            visited[i]=false;
        }
        int unique=0;//number of non reapeating editorial houses
        long double incomeAll;//the sum of all income of all the non repeating editorial houses
        for(int i=0;i<n;i++){
            char editorialHouse[MAX_SMALL];
            unique++;
            strcpy(editorialHouse,Products[i].GetEditorialHouse());
            for(int j=0;j<n;j++){//So that the editorials won't appear multiple times 
                if(strcmp(Products[j].GetEditorialHouse(),editorialHouse)==0){
                    visited[j]=true;
                }
            }
            double income=((float)Products[i].GetNumOfCopies()*Products[i].GetNumOfPages()*Products[i].GetPrice()*VAT_value);
            incomeAll+=income;
            OrderWhileInsert(income,i);
            this->unique=unique;
            return incomeAll;
        }

    }
    void GetPrintingHouseIncome(){
        //prints in descening order of income all editorial houses
        int nonReaptingNumberOfEditingHouses=unique;
        for(int i=0;i<nonReaptingNumberOfEditingHouses;i++){
        cout<<"Editorial House: "<<Products[valueIndex[i]].GetEditorialHouse()<<" - Income: "<<value[i]<<endl; 
        }
    }

};

float BookIndustry::VAT_value;

void ReadAllProducts(int n,BookIndustry &bk){
    char name[MAX_SMALL],editorialHouse[MAX_SMALL];
    int numOfPages=0,numOfCopies=0;
    float price=0;
    for(int i=0;i<n;i++){
        cout<<"Insert the names of the book and editorial house, number of pages and copies; and the price: "<<endl;
        cin>>name>>editorialHouse>>numOfPages>>numOfCopies>>price;
        bk.CreateBookProduct(i,name,editorialHouse,numOfPages,numOfCopies,price);
    }
}


int main(){
    int n;
    cout<<"Insert total the number of products you may wish to introduce to the kiosk: "<<endl;
    cin>>n;
    BookIndustry a(n);
    ReadAllProducts(n,a);
    //! USE THE CLASS METHODS AND DISPLAY THE RESULTS


    return 0;
}