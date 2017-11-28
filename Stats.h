double Avg(double vett[], int dim);
double Variance(double vett[], int dim, double avg);
double Standard_deviation(double vett[], int dim, double avg);
double Skewness(double vett[], int dim, double avg, double Standard_deviation);
void bubblesort(double vett[], int dim);

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