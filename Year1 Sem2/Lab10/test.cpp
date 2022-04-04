 #include<iostream>
  #include<cstring>
 using namespace std;

int main() {
	char array[100];
	cin>>array;
	char key;
	cin>>key;
	int length=strlen(array);
	cout<<key<<" "<<array<<" "<<length<<endl;
	for(int i=0;i<length;i++){
		cout<<array[i]<<" "<<key<<" "<<(char)(key^array[i])<<" - "<<(char)((key^array[i])^key)<<endl;
	}


  return 0;
} 