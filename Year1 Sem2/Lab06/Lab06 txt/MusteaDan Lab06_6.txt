//MusteaDan Lab06 Grupa 2013
#include <iostream>
#include <math.h>
using namespace std;

class Triangle{
private:
    float a=0,b=0,c=0;
    bool TriangleCheck(){
        if(this->a+this->b>this->c){
            if(this->a+this->c>this->b){
                if(this->b+this->c>this->a){
                    return true;
                }
            }
        }
        return false;
    }
public:
    Triangle(){
        this->a=0;
        this->b=0;
        this->c=0;
    }
    Triangle(float a,float b,float c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    void SetAll(float a,float b,float c){
        a=this->a;
        b=this->b;
        c=this->c;
    }

    void GetAll(){
        cout<<this->a<<" "<<this->b<<" "<<this->c<<endl;
    }

    float Area(){
        if(TriangleCheck()==true){
            float p=(this->a+this->b+this->c)/2;
         return sqrt(p*(p-this->a)*(p-this->b)*(p-this->c));
        }else{
            cout<<"This is not a triangle"<<endl;
        }
    }

    float Perimiter(){
        if(TriangleCheck()==true){
            return this->a+this->b+this->c;
        }else{
            cout<<"This is not a triangle"<<endl;
        }
    }

    bool RightTriangle(){
        if(TriangleCheck()==true){
            int A=this->a,B=this->b,C=this->c;
            if(A>B && A>C){
                if(pow(A,2)==pow(B,2)+pow(C,2)){
                    cout<<"This is a right triangle"<<endl;
                    return true;
                }
            }else if(B>A && B>C){
                if(pow(B,2)==pow(A,2)+pow(C,2)){
                    cout<<"This is a right triangle"<<endl;
                    return true;
                }
            }else if(C>A && C>B){
                if(pow(C,2)==pow(A,2)+pow(B,2)){
                    cout<<"This is a right triangle"<<endl;
                    return true;
                }
            }
            cout<<"This is not a right triangle"<<endl;
            return false;
        }else{
            cout<<"This is not a triangle"<<endl;
        }  
    }
};

int main(){
    float s1,s2,s3;
    cout<<"Insert the values of a triangle"<<endl;
    cin>>s1>>s2>>s3;
    Triangle a(s1,s2,s3);
    cout<<a.Area()<<endl;
    cout<<a.Perimiter()<<endl;
    a.RightTriangle();

    return 0;
}