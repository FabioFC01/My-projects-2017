#include <iostream>
#include <iomanip>

using namespace std;

inline double square(double x) {
	return x*x;
}

int main() {
	double a, b;
	double c = 13;

	a = square(5);			// 25
	b = square(4.5 + 7.5);	// 12*12 = 144

	cout << "a   = " << a << endl;
	cout << "b   = " << b << endl;
	cout << "c   = " << c;
	cout << " , c squared = " << square(c++) << endl;
	cout << "Now c = " << c << endl;

	system("pause");
	return 0;
}