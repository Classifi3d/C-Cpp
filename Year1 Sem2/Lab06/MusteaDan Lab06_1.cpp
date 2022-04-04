//MusteaDan Lab06 Grupa 2013
#include <iostream>

using namespace std;

class F1Pilot{
    private:
        char name[2048];
        char team[2048];
        int age;
        int best_time;
        int pole_postion_nr;
    public:
        void SetAll(){
            cin>>this->name;
            cin>>this->team;
            cin>>this->age;
            cin>>this->best_time;
            cin>>this->pole_postion_nr;
        }
        char* GetName(){
            return this->name;
        }
        char* GetTeam(){
            return this->team;
        }
        int GetAge(){
            return this->age;
        }
        int GetBestTime(){
            return this->best_time;
        }
        int PolePostionNrGet(){
            return this->pole_postion_nr;
        }
};

int main(){
    F1Pilot a,b,c;
    a.SetAll();
    b.SetAll();
    c.SetAll();
    if(a.GetBestTime()<b.GetBestTime() && a.GetBestTime()<c.GetBestTime()){
        cout<<a.GetName()<<" "<<a.GetTeam()<<" "<<a.GetAge()<<" "<<a.GetBestTime()<<" "<<a.PolePostionNrGet()<<endl;
    }
    if(b.GetBestTime()<a.GetBestTime() && b.GetBestTime()<c.GetBestTime()){
        cout<<b.GetName()<<" "<<b.GetTeam()<<" "<<b.GetAge()<<" "<<b.GetBestTime()<<" "<<b.PolePostionNrGet()<<endl;
    }
    if(c.GetBestTime()<b.GetBestTime() && c.GetBestTime()<a.GetBestTime()){
        cout<<c.GetName()<<" "<<c.GetTeam()<<" "<<c.GetAge()<<" "<<c.GetBestTime()<<" "<<c.PolePostionNrGet()<<endl;
    }


    return 0;
}
