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
    F1Pilot* p1=&a,*p2=&b,*p3=&c;
    a.SetAll();
    b.SetAll();
    c.SetAll();
    if(p1->GetBestTime()<p2->GetBestTime() && p1->GetBestTime()<p3->GetBestTime()){
        cout<<p1->GetName()<<" "<<p1->GetTeam()<<" "<<p1->GetAge()<<" "<<p1->GetBestTime()<<" "<<p1->PolePostionNrGet()<<endl;
    }
    if(p2->GetBestTime()<p1->GetBestTime() && p2->GetBestTime()<p3->GetBestTime()){
        cout<<p2->GetName()<<" "<<p2->GetTeam()<<" "<<p2->GetAge()<<" "<<p2->GetBestTime()<<" "<<p2->PolePostionNrGet()<<endl;
    }
    if(p3->GetBestTime()<p2->GetBestTime() && p3->GetBestTime()<p1->GetBestTime()){
        cout<<p3->GetName()<<" "<<p3->GetTeam()<<" "<<p3->GetAge()<<" "<<p3->GetBestTime()<<" "<<p3->PolePostionNrGet()<<endl;
    }


    return 0;
}
