#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include "Stats.h"

using namespace std;

double Avg(double vett[], int dim);
double Variance(double vett[], int dim, double avg);
double Standard_deviation(double vett[], int dim, double avg);
double Skewness(double vett[], int dim, double avg, double Standard_deviation);
void bubblesort(double vett[], int dim); double delta(double vett[], int dim);
double Min(double vett[]);
double Max(double vett[], int dim);
double Delta(double vett[], int dim);
double Q1(double vett[], int dim);
double Q2(double vett[], int dim);
double Q3(double vett[], int dim);
double IQR(double q1, double q3);

int main() {
	int i, n;
	double avg, variance, standard_deviation, skewness;
	double min, max, delta, iqr, q1, q2, q3;
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
	min = Min(vett);
	max = Max(vett, n);
	delta = Delta(vett, n);
	q1 = Q1(vett, n);
	q2 = Q2(vett, n);
	q3 = Q3(vett, n);
	iqr = IQR(q1, q3);

	//Cout the values
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "                              Analysis of the array" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "The minimum value is                  : " << setprecision(8) << min << endl;
	cout << "The maximum value is                  : " << setprecision(8) << max << endl;
	cout << "The average value is                  : " << setprecision(8) << avg << endl;
	cout << "The variance value is                 : " << setprecision(8) << variance << endl;
	cout << "The standard deviation value is       : " << setprecision(8) << standard_deviation << endl;
	cout << "The skewness value is                 : " << setprecision(8) << skewness << endl;
	cout << "Delta value is                        : " << setprecision(8) << delta << endl;
	cout << "Q1 value is                           : " << setprecision(8) << q1 << endl;
	cout << "Q2 value is                           : " << setprecision(8) << q2 << endl;
	cout << "Q3 value is                           : " << setprecision(8) << q3 << endl;
	cout << "IQR value is                          : " << setprecision(8) << iqr << endl;

	//Cout oredered array
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "                                Ordered array" << endl;
	for (i = 0; i < n; i++) {
		cout << setw(10) << left << i + 1 << setw(10) << left << vett[i] << endl;
	}
	cout << "-----------------------------------------------------------------------------------------" << endl;

	//end
	delete[] vett;
	system("pause");
	return 0;
}