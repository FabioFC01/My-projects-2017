#include <iostream>
#include <iomanip>

using namespace std;
bool prime_number(int a) {
	//declaration variables
	int n = 0;
	int i;

	//calculation
	for (i = 2; i < a-1; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	//output
	return true;
}

int main() {
	//declaration variables
	int n;
	int i = 0;
	int a = 2;
	bool b;

	//input variables
	cout << "Insert number of prime number that will be displayed :";
	cin >> n;
	//calculation
	while (i < n) {
		//searching a prime number
		b = prime_number(a);
		//counting prime numbers
		if (b == true) {
			if (i % 10 == 0) {
				cout << endl;
				cout << i+1 << " -> " << i+10 << " ----- "<< setw(12);

			}
			cout << setw(12) << a ;
			i++;
		}
		a++;
	}
	cout << endl;

	//stopping program
	system("pause");
	return 0;
}