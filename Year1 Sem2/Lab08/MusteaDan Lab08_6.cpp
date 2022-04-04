//MusteaDan Lab08 Grupa 2013
#include <iostream>
#include <math.h>

using namespace std;

class Point{
    private:
        int x,y;
    public:
        int GetX(){
            return this->x;
        }
        int GetY(){
            return this->y;
        }
        void Set(int x,int y){
            this->x=x;
            this->y=y;
        }
        friend void Output(Point p1,Point p2);

};
void Output(Point p1,Point p2,int shapeType){
    float distanceBetweenTwoPoints=sqrt(pow(p1.GetX()-p2.GetX(),2)+pow(p1.GetY()-p2.GetY(),2));
    if(shapeType==1){//Circle
        cout<<"Area: "<<M_PI*distanceBetweenTwoPoints/2<<endl;
        cout<<"Perimeter: "<<M_PI*distanceBetweenTwoPoints<<endl;
    }
    if(shapeType==2){//Right Triangle
        int p3x=p1.GetX(),p3y=p2.GetY();
        cout<<"Area: "<<fabsf(((float)(p1.GetX()*p2.GetY()+p2.GetX()*p3y+p3x*p1.GetY()-p1.GetX()*p3y-p2.GetX()*p1.GetX()-p3x*p3x*p2.GetY())/2))<<endl;
        cout<<"Perimeter: "<<fabsf(sqrt(pow(p1.GetX()-p3x,2)+pow(p1.GetY()-p3y,2))+sqrt(pow(p3x-p2.GetX(),2)+pow(p3y-p2.GetY(),2))+distanceBetweenTwoPoints)<<endl;
    }
}

int main(){

    int x1,y1,x2,y2,shape;
    cout<<"Insert the coordinates of a point: "<<endl;
    cin>>x1>>y1;
    cout<<"Insert the coordinates of a point: "<<endl;
    cin>>x2>>y2;
    cout<<"Insert the shape 1=circle/2=right_triangle: "<<endl;
    cin>>shape;
    Point p1,p2;
    p1.Set(x1,y1);
    p2.Set(x2,y2);
    Output(p1,p2,shape);

    return 0;
}