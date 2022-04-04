//MusteaDan Lab08 Grupa 2013
#include <iostream>

using namespace std;

class CurrentHour{
    private:
    int hour,minute,second;
    public:
    void Set(int hour,int minute,int second){
        this->hour=hour;
        this->minute=minute;
        this->second=second;
    }
    int GetHour(){
        return this->hour;
    }
    int GetMinute(){
        return this->minute;
    }
    int GetSecond(){
        return this->second;
    }
    void Display(){
        cout<<this->hour<<" "<<this->minute<<" "<<this->second<<endl;
    }
    friend CurrentHour Copy(const CurrentHour &TIME);
};

CurrentHour Copy(const CurrentHour &TIME){
        CurrentHour NEW;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        NEW.hour=ltm->tm_hour-3;//local time minus the time difference
        NEW.minute=TIME.minute;
        NEW.second=TIME.second;
        return NEW;
}

int main(){
    CurrentHour a,b,aux;
    int hour,minute,second;
    cout<<"Insert the hour/minute/secound: ";
    cin>>hour>>minute>>second;
    a.Set(hour,minute,second);
    b=Copy(a);
    a.Display();
    b.Display();
    
    
    return 0;
}