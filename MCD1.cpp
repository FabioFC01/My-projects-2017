#include <iostream>

using namespace std;

int GCD(int a,int b);

int main() {
	int a,b,result;
	cout <<"Inserirt first number : ";
	cin >> a;
	cout <<"Insert second number  : ";
	cin >> b;
	
	result = GCD(a,b);
	cout <<"GCD ( " << a << " ; " << b << " ) = " << result << endl;
	return 0;  
}

int GCD(int a,int b) {
	if(a!=b){
		if(a > b){
			GCD (a-b,b);
		}
		else{
			GCD(a,b-a);
		}
	}
	else{
		return a;
	}
}
