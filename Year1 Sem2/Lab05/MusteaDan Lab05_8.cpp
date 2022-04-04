//MusteaDan Lab05 Grupa 2013
#include <iostream>

using namespace std;

class Complex{
    class complexNumbers{
        private:
            int real,imag;
        public:
            void SetComplexNumber(int a,int b){
                this->real=a;
                this->imag=b;
            }
			int GetReal(){
				return real;
			}
            int GetImag(){
                return imag;
            }
    };
	private:
		complexNumbers x,y;
    public:
		void Set(int a,int b,int c,int d){
			this->x.SetComplexNumber(a,b);
			this->y.SetComplexNumber(c,d);
		}
		void Sum(){
			int SumR=x.GetReal()+y.GetReal();
			int SumI=x.GetImag()+y.GetImag();
			cout<<"sum result is real: "<<SumR<<" | imag: "<<SumI<<endl;
		}
		int Difference(){
			int minusR=this->x.GetReal()-this->y.GetReal();
			int minusI=this->x.GetImag()-this->x.GetImag();
			cout<<"diffrenece result is real: "<<minusR<<" | imag: "<<minusI<<endl;

		}
		int Multiplication(){
			int multi1=this->x.GetReal()*this->y.GetReal();
			int multi2=(this->x.GetReal()*this->y.GetImag())+(this->x.GetImag()*this->y.GetReal());
			int multi3=this->x.GetImag()*this->x.GetImag();
			multi3*=(-1);
			cout<<"multiplication result is real: "<<multi1+multi3<<" | imag: "<<multi2<<endl;
		}
		float Division(){
			float div1=((float)this->x.GetReal()/this->y.GetReal() )+ ((float)this->x.GetImag()/this->x.GetImag());
			float div2=((float)this->x.GetReal()/this->y.GetImag())+((float)this->x.GetImag()/this->y.GetReal());
			cout<<"division result is real: "<<div1<<" | imag: "<<div2<<endl;
    	}
};


int main(){
    cout<<"Insert the set of values of 2 complex numbers: ";
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
	Complex pair;
	pair.Set(a1,a2,b1,b2);
	pair.Sum();
	pair.Difference();
	pair.Multiplication();
	pair.Division();

    return 0;
}