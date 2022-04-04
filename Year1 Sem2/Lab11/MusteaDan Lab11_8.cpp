//MusteaDan Lab11 Grupa 2013
#include <iostream>
#include <math.h>

using namespace std;

class Point{
public:
    int x,y;
    void Set(int x,int y){
        this->x=x;
        this->y=y;
    }
    int GetX(){
        return this->x;
    }
    int GetY(){
        return this->y;
    }
    void Display(){
        cout<<x<<" "<<y<<endl;
    }
};

class AbstractQuadrilateral{
protected:
    Point a,b,c,d;
public:
    AbstractQuadrilateral(){
        cout<<"Insert the coordinates of the 4 points that make the quadrilateral (following the x,y format): ";
        int x,y;
        cin>>x>>y;
        a.Set(x,y);
        cin>>x>>y;
        b.Set(x,y);
        cin>>x>>y;
        c.Set(x,y);
        cin>>x>>y;
        d.Set(x,y);
    }
    virtual double Area()=0;
    virtual double Perimeter()=0;
    double distance(Point a, Point b){
        return abs(sqrt((a.x-b.x)*(a.x-b.x)-(a.y-b.y)*(a.y-b.y)));  
    }
};

class ActualQuadrilateral : public AbstractQuadrilateral{
public:
    double Area(){
        return (1/2) * ((a.x*b.y + b.x*c.y + c.x*d.y + d.x*a.y)- (b.x*a.y + c.x*b.y + d.x*c.y + a.x*d.y));
    }
    double Perimeter(){   
        return distance(a,b)+distance(b,c)+distance(c,d)+distance(d,a);
    }
    bool DetermineShape(){
        double x,y,z,t;
        x=distance(a,b);
        y=distance(c,b);
        z=distance(c,d);
        t=distance(a,d);
        if (x==y==z==t){
            cout<<"Square!"<<endl;
        }else if(x==y && z==t){
            cout<<"Rectangle!"<<endl;
        }else if(x==t && z==y){
            cout<<"Rectangle!"<<endl;
        }else if(x==z && t==y){
            cout<<"Rectangle!"<<endl;
        }else{
            cout<<"Irregularr Convex Quadrilateral!"<<endl;
        }
    }
};


int main(){
    ActualQuadrilateral a;
    cout<<a.Perimeter();
    cout<<a.Area();

    return 0;
}