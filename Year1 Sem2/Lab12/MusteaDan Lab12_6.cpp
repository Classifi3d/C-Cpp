//MusteaDan Lab12 Grupa 2013
#include <iostream>
#include <math.h>  
using namespace std;

class fraction{
    private:
        int gcd(int a, int b) { 
            if (a == 0)
            return b; 
            if (b == 0) 
            return a; 
            if (a == b) 
                return a; 
            if (a > b) 
                return gcd(a-b, b); 
            return gcd(a, b-a); 
        } 
    protected:
        int a,b;
    public:
        static int icount;
        /*void Simplify(){
                int div=gcd(a,b);
                a/=div;
                b/=div;
                cout<<"== Simplified =="<<endl;
        }*/
        void SetFraction(int a, int b){
            this->a=a;
            this->b=b;
        }
        double GetA(){
            return a;
        }
        double GetB(){
            return b;
        }
        void Display(){
				cout.unsetf(ios::right);
				cout.setf(ios::left);
				cout.width(10);
				cout.fill('*');
				cout<<this->a<<"/";
				cout.unsetf(ios::left);
				cout.setf(ios::right);
				cout.width(10);
				cout.fill('*');
				cout<<this->b<<endl;
				cout.unsetf(ios::right);
        }
        void DisplayIcount(){
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(15);
			cout.precision(15);
			cout.fill('$');
			cout<<icount<<endl;
			cout.unsetf(ios::left);
        }
        virtual void Simplify(){};
        fraction(){
            a=0;
            b=1;
			icount++;
        }
        fraction(int a,int b){
			icount++;
            if(b!=0){
                this->a=a;
                this->b=b;
            }else{
                cout<<"Invalid input!"<<endl;
            }
        }
        friend fraction operator+(fraction,fraction);
        friend fraction operator-(fraction,fraction);
        friend fraction operator*(fraction,fraction);
        friend fraction operator/(fraction,fraction);
	    friend ostream &operator<<(ostream &output, fraction &aux){
        	output <<"X: "<<aux.a<<" Y: "<<aux.b;
        	return output;
    	}
    	friend istream &operator>>(istream &input, fraction &aux){
        	input >>aux.a>>aux.b;
        	return input;
   		}

};
fraction operator +(fraction x,fraction y){
    fraction aux;
    aux.a=x.a*y.b+y.a*x.b;
    aux.b=y.b*x.b;
    return aux;
}

fraction operator -(fraction x,fraction y){
    fraction aux;
    aux.a=x.a*y.b-y.a*x.b;
    aux.b=y.b*x.b;
    return aux;
}

fraction operator *(fraction x,fraction y){
    fraction aux;
    aux.a=y.a*x.a;
    aux.b=y.b*x.b;
    return aux;
}

fraction operator /(fraction x,fraction y){
    fraction aux;
    aux.a=x.a*y.b;
    aux.b=x.b*y.a;
    return aux;
}

int fraction::icount=0;

int main(){
    int a,b;
	fraction x;
    cout<<"Insert the values of a fraction: ";
	cin>>x;
	x.SetFraction(a,b);
	x.DisplayIcount();
	fraction y;
    cout<<"Insert the values of a fraction: ";
	cin>>y;
	y.SetFraction(a,b);	
	y.DisplayIcount();
	fraction z;
	z=x+y;
	z.Display();
	z=x-y;
	z.Display();
	z=x*y;
	z.Display();
	z=x/y;
	z.Display();
	cout<<z<<endl;
	z.DisplayIcount();

    return 0;
}