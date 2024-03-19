#include <iostream>
#include <float.h>
#include <fstream>
using namespace std;

int main() {
    double num[10], minimum = DBL_MAX, maximum = 0.0, mean = 0.0, stddev = 0.0;
    double sum = 0.0;
    int count = 0;

    ifstream fin;
    ofstream fout;
    fin.open("inputfile.txt");
    fout.open("output.txt");

    if (!fin) {
        cerr << "cannot open " << "inputfile.txt" << endl;
        exit(1);
    }
    if (!fout) {
        cerr << "cannot open " << "outp1.txt" << endl;
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        fin >> num[i];
        cout << num[i] << endl;
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
        stddev = stddev + pow((num[i] - mean), 2);
    }
    stddev = sqrt(stddev / count);

    fout << "The mean of numbers is: " << mean << endl;
    fout << "The minimum of numbers is: " << minimum << endl;
    fout << "The maximum of numbers is: " << maximum << endl;
    fout << "The standard deviation of numbers is: " << stddev << endl;

    fin.close();
    fout.close();
}
