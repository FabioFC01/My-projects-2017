#include <iostream>
#include <iomanip>
#include <vector>
#include "Stats.h"

using namespace std;

double Avg(double vett[], int dim);
double Variance(double vett[], int dim, double avg);
double Standard_deviation(double vett[], int dim, double avg);
double Skewness(double vett[], int dim, double avg, double Standard_deviation);
void bubblesort(double vett[], int dim);

int main() {
	int i, n;
	double avg, variance, standard_deviation, skewness;
	cout << "Insert array dimension : ";
	do {
		cin >> n;
	} while (n < 0);

	double *vett = new double[n];

	for (i = 0; i < n; i++) {
		cout << "Insert number " << i + 1 << " : ";
		cin >> vett[i];
	}

	//Calculation
	avg = Avg(vett, n);
	variance = Variance(vett, n, avg);
	standard_deviation = Standard_deviation(vett, n, avg);
	skewness = Skewness(vett, n, avg, standard_deviation);
	bubblesort(vett, n);

	//Cout the values
	cout << "The average value is                  : " << setprecision(8) << avg << endl;
	cout << "The variance value is                 : " << setprecision(8) << variance << endl;
	cout << "The standard deviation value is       : " << setprecision(8) << standard_deviation << endl;
	cout << "The skewness value is                 : " << setprecision(8) << skewness << endl;

	//Cout oredered array
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "                                Ordered array" << endl;
	for (i = 0; i < n; i++) {
		cout << vett[i] << endl;
	}
	cout << "-----------------------------------------------------------------------------------------" << endl;

	//end
	delete[] vett;
	system("pause");
	return 0;
}