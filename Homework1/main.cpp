#include <iostream>
#include <float.h>
using namespace std; 

int main() {
	cout << "Enter 10 floating point numbers" << endl;
	double num[10], minimum = DBL_MAX, maximum = 0.0, mean = 0.0, stddev = 0.0;
	double sum = 0.0;
	int count = 0;

	for (int i = 0; i < 10; i++) {
		cout << "Enter number " << count << ": ";
		cin >> num[i];
		count++;
		sum = num[i] + sum;
		if (num[i] < minimum) {
			minimum = num[i];
		}
		else if (num[i] > maximum) {
			maximum = num[i];
		}
	}

	mean = sum / count;

	for (int i = 0; i < 10; i++) {
		stddev = stddev + pow((num[i] - mean),2);
	}
	stddev = sqrt(stddev / count);

	cout << "The mean of numbers is: " << mean << endl;
	cout << "The minimum of numbers is: " << minimum << endl;
	cout << "The maximum of numbers is: " << maximum << endl;
	cout << "The standard deviation of numbers is: " << stddev << endl;	

}

