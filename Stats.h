double Avg(double vett[], int dim);
double Variance(double vett[], int dim, double avg);
double Standard_deviation(double vett[], int dim, double avg);
double Skewness(double vett[], int dim, double avg, double Standard_deviation);
void bubblesort(double vett[], int dim);
double Min(double vett[]);
double Max(double vett[], int dim);
double Delta(double vett[], int dim);
double Q1(double vett[], int dim);
double Q2(double vett[], int dim);
double Q3(double vett[], int dim);
double IQR(double q1, double q3);

double Avg(double vett[], int dim) {
	int i;
	double Avg = 0;

	for (i = 0; i < dim; i++) {
		Avg += vett[i];
	}
	return Avg / dim;
}

double Variance(double vett[], int dim, double Avg) {
	int i;
	double variance = 0;
	for (i = 0; i < dim; i++) {
		variance += pow((vett[i] - Avg), 2);
	}
	variance = variance / dim;
	return variance;
}

double Standard_deviation(double vett[], int dim, double Avg) {
	int i;
	double std = 0;
	for (i = 0; i < dim; i++) {
		std += pow(vett[i] - Avg, 2);
	}
	std = sqrt(std / dim);
	return std;
}

double Skewness(double vett[], int dim, double avg, double Standard_deviation) {
	double Skewness = 0;
	int i;
	for (i = 0; i < dim; i++) {
		Skewness += pow(((vett[i] - avg) / Standard_deviation), 3);
	}
	Skewness = Skewness / dim;
	return Skewness;
}

void bubblesort(double vett[], int dim) {
	int i, j;
	double temp;
	bool swap = true;
	j = 0;
	while (swap) {
		swap = false;
		for (i = 0; i < dim - j - 1; i++) {
			if (vett[i]>vett[i + 1]) {
				swap = true;
				temp = vett[i];
				vett[i] = vett[i + 1];
				vett[i + 1] = temp;
			}
		}
		j++;
	}
}

double Min(double vett[]) {
	//array need to be ordinated if you want
	//to run that function
	return vett[0];
}

double Max(double vett[], int dim) {
	//array need to be ordinated if you want
	//to run that function
	return vett[dim - 1];
}

double Delta(double vett[], int dim) {
	//array need to be ordinated if you want
	//to run that function
	return vett[dim - 1] - vett[0];
}

double Q1(double vett[], int dim) {
	//array need to be ordinated if you want
	//to run that function
	double q1, q, value;
	if (dim = 1)
		return vett[0];
	if (dim = 2)
		return vett[0] + (vett[1] - vett[0])*0.25;
	q1 = (dim + 1) * 0.25;
	if (q1 == (double)(int)q1)
		return vett[int(q1) - 1];
	q = q1;
	while (q > 1)
		q--;
	value = vett[int(q1 - 1)] + (vett[int(q1)] - vett[int(q1 - 1)]) * q;
	return value;
}

double Q2(double vett[], int dim) {
	//array need to be ordinated if you want
	//to run that function
	double q2, q, value;
	q2 = (dim + 1) * 0.5;
	if (q2 == (double)(int)q2)
		return vett[int(q2) - 1];
	q = q2;
	while (q > 1)
		q--;
	value = vett[int(q2 - 1)] + (vett[int(q2)] - vett[int(q2 - 1)]) * q;
	return value;
}

double Q3(double vett[], int dim) {
	//array need to be ordinated if you want
	//to run that function
	double q3, q, value;
	if (dim = 1)
		return vett[0];
	if (dim = 2)
		return vett[0] + (vett[1] - vett[0])*0.75;
	q3 = (dim + 1) * 0.75;
	if (q3 == (double)(int)q3)
		return vett[int(q3) - 1];
	q = q3;
	while (q > 1)
		q--;
	value = vett[int(q3 - 1)] + (vett[int(q3)] - vett[int(q3 - 1)]) * q;
	return value;
}

double IQR(double q1, double q3) {
	//array need to be ordinated if you want
	//to run that function
	return q3 - q1;
}