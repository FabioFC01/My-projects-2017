#include <iostream>
#include <iomanip>

using namespace std;
int GCD (int a, int b);

int main(){
	int a,b;
	cout <<"Insert the bigger number : ";
	do{
		cin >> a;
	}while(a < 0);
	
	cout <<"Insert the smaller number : ";
	do{
		cin >> b;
	}while(b < 0 || b > a);
	
	cout <<"G.C.D. ( " << a << " ; " << b << " ) = " << GCD (a , b);
	
	return 0;
}

int GCD (int a, int b){
	if(a % b == 0){
		return b;
	}
	else{
		GCD (b , a%b);
	}
}
