//MusteaDan Lab06 Grupa 2013
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout ("MusteaDan Lab06_4.txt");

struct date{
    int day;
    int month;
    int year;
};

class DateClass{
    private:
        date dt;
    public:
        void SetAll(int day,int month,int year){
            this->dt.day=day;
            this->dt.month=month;
            this->dt.year=year;
        }

        void GetAll(){
            cout<<this->dt.day<<" "<<this->dt.month<<" "<<this->dt.year<<endl;
        }

        bool Valid(){
            if(this->dt.year>2020){
                return false;
            }
            if(this->dt.month>12){
                return false;
            }
            if(this->dt.day>31){
                return false;
            }
            return true;
        }

        void FileWrite(){
            if(Valid()==true){
                cout<<dt.month<<" "<<dt.day;
                for(int i=1;i<=this->dt.month;i++){//month
                    if(i==this->dt.month){
                        for(int j=1;j<this->dt.day;j++){
                            fout<<this->dt.year<<" "<<i<<" "<<j<<endl;      
                        }
                    }else{
                        for(int j=1;j<=31;j++){//day
                            fout<<this->dt.year<<" "<<i<<" "<<j<<endl;
                        }
                    }
                }
            }else{
                cout<<"INVALID DATE!"<<endl;
            }
        }
};

int main(){
    DateClass dt;
    DateClass* p=&dt;
    int day,month,year;
    cout<<"Insert the day/month/year: ";
    cin>>day>>month>>year;
    p->SetAll(day,month,year);
    p->GetAll();
    cout<<p->Valid()<<endl;
    p->FileWrite();
    cout<<endl;
    return 0;
}