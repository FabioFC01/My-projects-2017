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
	while(a!=b){
		if(a > b){
			a = a-b;
		}
		if(b > a){
			b = b-a;
		}
	}
	return a;
}
