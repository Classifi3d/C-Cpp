//MusteaDan Lab11 Grupa 2013
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

class Record{
public:
    char artist[MAX];
    char title[MAX];
    int duration; // in secounds
};

class Playlist{
private:
    Record *p;
protected:
    int n;
public:
    Playlist(){
        cout<<"Insert the number of songs in the playlist: ";
        int n;
        cin>>n;
        cout<<endl;
        p=(Record *)malloc((n+1)*sizeof(Record));
        if (p==NULL) exit (1);
        this->n=n;
    }
    ~Playlist(){
        //cout<<"Deconstructed!";
        free(p);
    }
    void SetAll(){
        cout<<"Insert the "<<n<<" songs you wish to be in the playlist following this formula (artist, title and then duration)"<<endl;
        char aux[MAX];
        for(int i=0;i<n;i++){
            cin>>aux;
            strcpy(p[i].artist,aux);
            cin>>aux;
            strcpy(p[i].title,aux);
            int duration;
            cin>>duration;
            p[i].duration=duration;
        }
    }
    void Set(Record &aux,int index){
        p[index]=aux;
    }
    Record Get(int index){
        return p[index];
    }
    void Display(){
        for(int i=0;i<n;i++){
            cout<<p[i].artist<<" "<<p[i].title<<" "<<p[i].duration<<endl;
        }
        cout<<endl;
    }
    virtual void Sort(int n)=0;//1-title 2-artist 3-duration
};

class PlaylistImplementation : public Playlist{
public:
    //using Playlist::Playlist;
    PlaylistImplementation():Playlist(){
    }
    void Sort(int c){
        if(c==1){
            Record a,b;
            for(int i=0;i<n-i-1;i++){
                for(int j=0;j<n-i-1;j++){
                    a=Get(j);
                    b=Get(j+1);
                    if(strcmp(a.title,b.title)){
                        Set(b,j);
                        Set(a,j+1);
                    }
                }
            }
        }else if(c==2){
            Record a,b;
            for(int i=0;i<n-i-1;i++){
                for(int j=0;j<n-i-1;j++){
                    a=Get(j);
                    b=Get(j+1);
                    if(strcmp(a.artist,b.artist)){
                        Set(b,j);
                        Set(a,j+1);
                    }
                }
            }
        }else if(c==3){
            Record a,b;
            for(int i=0;i<n-i-1;i++){
                for(int j=0;j<n-i-1;j++){
                    a=Get(j);
                    b=Get(j+1);
                    if(a.duration>b.duration){
                        Set(b,j);
                        Set(a,j+1);
                    }
                }
            }
        }
        

    }
};



int main(){
    //Playlist x(n);
    PlaylistImplementation a;
    a.SetAll();
    cout<<endl;
    a.Display();
    int c;
    cout<<"Choose one of three sorting methods to be applied to the playlist (1-title 2-artist 3-duration): ";
    cin>>c;
    a.Sort(c);
    a.Display();


    return 0;
}