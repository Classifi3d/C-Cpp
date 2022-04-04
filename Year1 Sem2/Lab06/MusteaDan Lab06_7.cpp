//MusteaDan Lab06 Grupa 2013
#include <iostream>

using namespace std;

class Safe{
    private:
        int cipher=0;
        int money=0;
		void SetMoney(int money){
			this->money+=money;
        }
		void GetMoney(int money){
			this->money-=money;
		}
		int SafeGetter(){
			return this->money;
		}
    public:
		Safe(int cipher){
			this->cipher=cipher;
		}
		void PutInSafe(int money,int cipher){
			if(this->cipher==cipher){
				SetMoney(money);
			}else{
				cout<<"Wrong Chiper";
			}
		}
		void GetFromSage(int money,int cipher){
			if(this->cipher==cipher){
				GetMoney(money);
			}else{
				cout<<"Wrong Chiper";
			}
		}
		int FundsLeft(int cipher){
			if(this->cipher==cipher){
				return SafeGetter();
			}else{
				return -1;
				cout<<"Wrong Chiper";
			}
		}

};

int main(){
	cout<<"Insert a cipher for setting up your bank account: "<<endl;
	int cip=0;
	cin>>cip;
	Safe account1 = Safe(cip);
	cout<<"Insert an amount of money to deposit: "<<endl;
	int amount1=0;
	cin>>amount1;
	account1.PutInSafe(amount1,cip);
	cout<<account1.FundsLeft(cip)<<endl;
	cout<<"Insert another amount of money to deposit: "<<endl;
	int amount2=0;
	cin>>amount2;
	account1.PutInSafe(amount2,cip);
	cout<<account1.FundsLeft(cip)<<endl;
	cout<<"Insert an amount of money to withdraw: "<<endl;
	int amount3=0;
	cin>>amount3;
	account1.GetFromSage(amount3,cip);
	cout<<account1.FundsLeft(cip)<<endl;	

    return 0;
}