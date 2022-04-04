//MusteaDan Lab05 Grupa 2013
#include <iostream>
#include <math.h>

using namespace std;

struct CircleStruct{
    int radius;
};

class CircleClass{
    private: 
        int radius;
    public:
        CircleClass(int a){
            radius=a;
        }
        int getRadius(){
            return radius;
        }

        int area(){
            return M_PI*radius*radius;
        }
        int circumference(){
            return M_PI*2*radius;
        }
        ~CircleClass(){
            //delete &radius;
            radius=0;
        };
};

int main(){
    struct CircleStruct c1,c2;
    cout<<"Input the values for the struct circle c1 and c2"<<endl;
    cin>>c1.radius>>c2.radius;
    cout<<"Circle one's area and circumference are "<<(M_PI*c1.radius*c1.radius)<<" and "<<(2*M_PI*c1.radius)<<endl;
    int c2Diameter=(2*c2.radius);
    cout<<"Circlwe two's area and circumfere6nce are "<<(M_PI/4)*c2Diameter*c2Diameter<<" and "<<c2Diameter*M_PI<<endl;

    int x;
    cout<<"Input the value of the radius for circle class"<<endl;
    cin>>x;
    CircleClass C1(x),C2();
    cout<<"radius: "<<C1.getRadius()<<endl;
    cout<<"circumference: "<<C1.circumference()<<endl;
    cout<<"area: "<<C1.area()<<endl;
    cout<<"Insert an area to redefine a circle's area: ";
    //int y,*yp; cin>>y;

    //cout<<"The modified area is "<<C2.area<<endl;


    return 0;
}