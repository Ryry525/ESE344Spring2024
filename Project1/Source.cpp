
//Program for generating and reading input data for Project 1
// by Prof. Murali Subbarao, ESE 344

#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <fstream>
#include <vector>
#include "class.h"
using namespace std;

//Program for generating input data fore Project 1
// by Prof. Murali Subbarao, ESE 344

// generate random data for a 3d tensor
void data3d(int s1, int s2, int s3) {
	srand((unsigned int)time(NULL));// seed rand() with system time
	//Generating input for project 1
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++) {
				cout << (float)((rand() % 100) / 100.0) << "   ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// generate random data for a 2d tensor
void data2d(int s1, int s2) {
	srand((unsigned int)time(NULL));// seed rand() with system time
	//Generating input for project 1
	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++) {
			cout << (float)((rand() % 100) / 100.0) << "   ";
		}
		cout << endl;
	}
	cout << endl << endl;
}


// generate random data for a 4d tensor
void data4d(int s1, int s2, int s3, int s4) {

	srand((unsigned int)time(NULL));// seed rand() with system time

	//Generating input for project 1
	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					cout << (float)((rand() % 100) / 100.0) << "   ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// generate random data for a 1d vector 
void data1d(int s1, const string& filename) {
	ofstream outputFile(filename);
	if (outputFile.is_open()) {
		//Generating input for project 1
		for (int i1 = 0; i1 < s1; i1++) {
			float randomValue = (float)((rand() % 100) / 100.0);
			outputFile << randomValue << "   ";
		}
		outputFile << endl << endl;
		outputFile.close();
	}
}




// allocate memory for a 1d vector
void alloc1d(vector<float>& tn1d, int s1) {
	// allocate memory for a 1d tensor tn1d of size s1
	tn1d.resize(s1);
}

// read data for a 1d tensor
void read1d(vector<float>& tn1d, int s1) {
	for (int i1 = 0; i1 < s1; i1++)
	{
		cin >> tn1d[i1];
	}
}
// print data for a 1d tensor
void print1d(vector<float>& tn1d, int s1) {
	cout << endl << endl;
	for (int i1 = 0; i1 < s1; i1++)
	{
		cout << tn1d[i1] << "   ";
	}
	cout << endl << endl;
}

// allocate memory for a 2d tensor
void alloc2d(vector<vector<float>>& tn2d, int s1, int s2) {
	// allocate memory for a 2d tensor tn2d of size s1, s2
	tn2d.resize(s1);
	for (int i1 = 0; i1 < s1; i1++) {
		tn2d[i1].resize(s2);
	}
}

// read data for a 2d tensor
void read2d(vector<vector<float>>& tn2d, int s1, int s2) {

	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++)
		{
			cin >> tn2d[i1][i2];
		}
	}
}

// print data for a 2d tensor
void print2d(vector<vector<float>>& tn2d, int s1, int s2) {
	cout << endl << endl;
	for (int i2 = 0; i2 < s2; i2++) {
		for (int i1 = 0; i1 < s1; i1++)
		{
			cout << tn2d[i1][i2] << "   ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

// allocate memory for a 3d tensor
void alloc3d(vector<vector<vector<float>>>& tn3d, int s1, int s2, int s3) {
	// allocate memory for a 3d tensor tn3d of size s1, s2, s3
	tn3d.resize(s1);
	for (int i1 = 0; i1 < s1; i1++) {
		tn3d[i1].resize(s2);
		for (int i2 = 0; i2 < s2; i2++) {
			tn3d[i1][i2].resize(s3);
		}
	}
}

// read data for a 3d tensor
void read3d(vector<vector<vector<float>>>& tn3d, int s1, int s2, int s3) {
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++)
			{
				cin >> tn3d[i1][i2][i3];
			}
		}
	}
}

// print data for a 3d tensor
void print3d(vector<vector<vector<float>>>& tn3d, int s3, int s2, int s1) {
	cout << endl << endl;
	for (int i3 = 0; i3 < s3; i3++) {
		for (int i2 = 0; i2 < s2; i2++) {
			for (int i1 = 0; i1 < s1; i1++)
			{
				cout << tn3d[i3][i2][i1] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

// allocate memory for a 4d tensor tn4d of size s1, s2, s3, s4
void alloc4d(vector<vector<vector<vector<float>>>>& tn4d, int s1, int s2, int s3, int s4) {

	tn4d.resize(s1);

	for (int i1 = 0; i1 < s1; i1++) {
		tn4d[i1].resize(s2);
		for (int i2 = 0; i2 < s2; i2++) {
			tn4d[i1][i2].resize(s3);
			for (int i3 = 0; i3 < s3; i3++)
			{
				tn4d[i1][i2][i3].resize(s4);
			}
		}
	}
}

// read a 4d tensor tn4d of size s1, s2, s3, s4
void read4d(vector<vector<vector<vector<float>>>>& tn4d, int s1, int s2, int s3, int s4) {

	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					cin >> tn4d[i1][i2][i3][i4];
				}
			}
		}
	}
}

// print a 4d tensor tn4d of size s1, s2, s3, s4
void print4d(vector<vector<vector<vector<float>>>>& tn4d, int s4, int s3, int s2, int s1) {
	cout << endl << endl;
	for (int i4 = 0; i4 < s4; i4++) {
		for (int i3 = 0; i3 < s3; i3++) {
			for (int i2 = 0; i2 < s2; i2++) {
				for (int i1 = 0; i1 < s1; i1++) {
					cout << tn4d[i4][i3][i2][i1] << "   ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

//Main program
int main()
{
	char c;
	ConvNet net;
	string image = "Test_image.txt"; //Test_image.txt 
	string weight = "CNN_weights.txt"; //Test_image.txt 
	string bias1 = "bias1.txt";
	string bias2 = "bias2.txt";
	string bias3 = "bias3.txt";
	string bias4 = "bias4.txt";
	srand((unsigned int)time(NULL)); // seed rand() with system time
	data1d(16, bias1);
	data1d(20, bias2);
	data1d(20, bias3);
	data1d(10, bias4);
	net.M1(image);
	print3d(net.D1, 32, 32, 3);
	cout << "Layer 1 printed." << endl;
	//D3
	net.M2(weight);
	print4d(net.D3, 5, 5, 3, 6);
	//D4
	net.M3(bias1);
	cout << "Bias1: ";
	print1d(net.D4, 16);
	//D2
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M4();
	print3d(net.D2, 32, 32, 16);
	cout << "Layer 2 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M5();
	print3d(net.D5, 32, 32, 16);
	cout << "Layer 3 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M6();
	print3d(net.D6, 16, 16, 16);
	cout << "Layer 4 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M7(weight);
	print4d(net.D8, 5, 5, 16, 20);
	net.M8(bias2);
	cout << "Bias2: ";
	print1d(net.D9, 20);
	net.M9();
	print3d(net.D7, 16, 16, 20);
	cout << "Layer 5 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M10();
	print3d(net.D10, 16, 16, 20);
	cout << "Layer 6 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M11();
	print3d(net.D11, 8, 8, 20);
	cout << "Layer 7 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M12(weight);
	print4d(net.D13, 5, 5, 20, 20);
	net.M13(bias3);
	cout << "Bias3: ";
	print1d(net.D14, 20);
	net.M14();
	print3d(net.D12, 8, 8, 20);
	cout << "Layer 8 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M15();
	print3d(net.D15, 8, 8, 20);
	cout << "Layer 9 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M16();
	print3d(net.D16, 4, 4, 20);
	cout << "Layer 10 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M17(weight);
	print4d(net.D18, 4, 4, 20, 10);
	net.M18(bias4);
	cout << "Bias4: ";
	print1d(net.D19, 10);
	net.M19();
	cout << "Model output(D17):";
	print1d(net.D17, 10);
	cout << "Layer 11 printed." << endl;
	cout << "Press any key to continue..." << endl;
	cin >> c;
	net.M20();
	cout << "Normalized output(D17):";
	print1d(net.D17, 10);
	net.M21();
	cout << "Output of CNN:";
	net.M22();
	ofstream output("output_file.txt");
	if (output.is_open()) {
		float sum = 0.0f;
		output << "The output of the CNN is: \n";
		for (int i = 0; i < 10; i++) {
			output << net.D20[i] << "   ";
		}
		for (int i = 0; i < 10; i++) {
			sum += net.D20[i];
		}
		output << "\nThe sum of the output is: " << sum;
		output.close();
	}
}

