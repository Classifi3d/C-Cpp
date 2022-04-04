//MusteaDan Lab07 Grupa 2013
#include <iostream>
#include <math.h>
using namespace std;

class Points{
    private:
		float x,y,z;
		float GetDistance(float x1,float y1,float z1,float x2,float y2,float z2){
			return pow((pow((x2 - x1),2) + pow((y2 - y1),2) + pow((z2 - z1),2)) , (float)1/2);
		}
	public:
		void SetPoint(float x,float y,float z){
			this->x=x;
			this->y=y;
			this->z=z;
		}
		float GetPoint(float &x, float &y, float &z){
			x=this->x;
			y=this->y;
			z=this->z;
		}
		float DisplayPoint(){
			cout<<this->x<<" "<<this->y<<" "<<this->z<<endl;
		}
		bool IsPointInLineBetweeenTwoPoints(Points a,Points b){
			float x1,x2,x3,y1,y2,y3,z1,z2,z3;
			x3=this->x;
			y3=this->y;
			z3=this->z;
			a.GetPoint(x1,y1,z1);
			b.GetPoint(x2,y2,z2);
			float d1,d2,d3;
			d1=GetDistance(x1,y1,z1,x2,y2,z2);
			d2=GetDistance(x1,y1,z1,x3,y3,z3);
			d3=GetDistance(x2,y2,z2,x3,y3,z3);
			if(d1==d2+d3){
				return true;
			}else{
				return false;
			}
		}
		void MovePoint(float &x, float y, float z){
			this->x+=x;
			this->y+=y;
			this->z+=z;

		}
};

void ReadCoordinates(float &x,float &y,float &z){
	cout<<"Insert the x/y/x coordinates for the point"<<endl;
	cin>>x>>y>>z;
}

int main(){
	Points a,b,c;

	float x,y,z;
	ReadCoordinates(x,y,z);
	a.SetPoint(x,y,z);
	ReadCoordinates(x,y,z);
	b.SetPoint(x,y,z);
	ReadCoordinates(x,y,z);
	c.SetPoint(x,y,z);
	cout<<"The point is/not colliniar and in between the 2 points: "<<c.IsPointInLineBetweeenTwoPoints(a,b)<<endl;
	c.DisplayPoint();
	ReadCoordinates(x,y,z);
	c.MovePoint(x,y,z);
	c.DisplayPoint();


    return 0;
}