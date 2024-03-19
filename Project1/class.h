
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;
class ConvNet {
public:
	int stride = 0;
	vector<vector<vector<float>>> D1; // Data member for storing the output of layer L1, D1
	vector<vector<vector<float>>> D2; // Data member for storing the output of layer L2, D2
	vector<vector<vector<vector<float>>>> D3; // Data member for storing the convolution filters
	vector<float> D4; // Data member for storing the bias vector
	vector<vector<vector<float>>> D5; // Data member for storing the output of layer L3, D5
	vector<vector<vector<float>>> D6; // Data member for storing the output of layer L4, D6
	vector<vector<vector<float>>> D7; // Data member for storing the output of layer L5, D7
	vector<vector<vector<vector<float>>>> D8; // Data member for storing the convolution filters
	vector<float> D9; // Data member for storing the bias vector
	vector<vector<vector<float>>> D10; // Data member for storing the output of layer L6, D10
	vector<vector<vector<float>>> D11; // Data member for storing the output of layer L7, D11
	vector<vector<vector<float>>> D12; // Data member for storing the output of layer L8, D12
	vector<vector<vector<vector<float>>>> D13; // Data member for storing the convolution filters
	vector<float> D14; // Data member for storing the bias vector
	vector<vector<vector<float>>> D15; // Data member for storing the output of layer L9, D15
	vector<vector<vector<float>>> D16; // Data member for storing the output of layer L10, D16
	vector<float> D17; //Data member for storing the output of layer L11, D17
	vector<vector<vector<vector<float>>>> D18; // Data member for storing the convolution filters
	vector<float> D19; // Data member for storing the bias vector
	vector<float> D20; // Data member for storing the output of layer L12, D20

	void M1(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D1.resize(32, vector<vector<float>>(32, vector<float>(3)));
			for (int i = 0; i < 32; i++) {
				for (int j = 0; j < 32; j++) {
					for (int k = 0; k < 3; k++) {
						file >> D1[i][j][k]; // Read input image data and initialize L1
					}
				}
			}
			file.close();
		}
	}

	void M2(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D3.resize(5, vector<vector<vector<float>>>(5, vector<vector<float>>(3, vector<float>(16))));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 16; l++) {
							file >> D3[i][j][k][l]; // Read convolution filters data and initialize D3
						}
					}
				}
			}
			file.close();
		}
	}

	void M3(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D4.resize(16);
			for (int i = 0; i < 16; i++) {
				file >> D4[i]; // Read bias vector data and initialize D4
			}
			file.close();
		}
	}

	void M4() {
		stride = 1;
		D2.resize(32, vector<vector<float>>(32, vector<float>(16)));
		for (int i = 0; i < 28; i++) { 
			for (int j = 0; j < 28; j++) { 
				for (int k1 = 0; k1 < 16; k1++) {
					D2[i][j][k1] = 0; // Initialize L2 to 0
					for (int l = 0; l < 5; l++) {
						for (int m = 0; m < 5; m++) {
							for (int n = 0; n < 3; n++) {
								D2[i][j][k1] += D1[i + l][j + m][n] * D3[l][m][n][k1]; // Convolution operation
							}
						}
					}
					D2[i][j][k1] += D4[k1]; // Add bias vector
				}
			}
		}
	}


	void M5() {
		D5.resize(32, vector<vector<float>>(32, vector<float>(16)));
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				for (int k = 0; k < 16; k++) {
					D5[i][j][k] = max(0.0f, D2[i][j][k]); // Compute D5(L3) using D2(L2)
				}
			}
		}
	}

	void M6() {
		stride = 2;
		D6.resize(16, vector<vector<float>>(16, vector<float>(16)));
		for (int k = 0; k < 16; k++) { // for each cross section k
			for (int m = 0, i = 0; m < 32; m += stride, i++) { //for row m
				for (int n = 0, j = 0; n < 32; n += stride, j++) { // for column n
					D6[i][j][k] = max({ D5[m][n][k], D5[m + 1][n][k], D5[m][n + 1][k], D5[m + 1][n + 1][k] }); // Compute D6(L4) using D5(L3)
				}
			}
		}
	}
	void M7(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D8.resize(5, vector<vector<vector<float>>>(5, vector<vector<float>>(16, vector<float>(20))));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 16; k++) {
						for (int l = 0; l < 20; l++) {
							file >> D8[i][j][k][l]; // Read convolution filters data and initialize D8
						}
					}
				}
			}
			file.close();
		}
	}
	void M8(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D9.resize(20);
			for (int i = 0; i < 20; i++) {
				file >> D9[i]; // Read bias vector data and initialize D9
			}
			file.close();
		}
	}

	void M9() {
		stride = 1;
		D7.resize(16, vector<vector<float>>(16, vector<float>(20)));
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				for (int k = 0; k < 20; k++) {
					D7[i][j][k] = 0; // Initialize L5 to 0
					for (int l = 0; l < 5; l++) {
						for (int m = 0; m < 5; m++) {
							for (int n = 0; n < 16; n++) {
								D7[i][j][k] += D6[i + l][j + m][n] * D8[l][m][n][k]; // Convolution operation
							}
						}
					}
					D7[i][j][k] += D9[k]; // Add bias vector
				}
			}
		}
	}

	void M10() {
		D10.resize(16, vector<vector<float>>(16, vector<float>(20)));
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				for (int k = 0; k < 20; k++) {
					D10[i][j][k] = max(0.0f, D7[i][j][k]); // Compute D10(L6) using D7(L5)
				}
			}
		}
	}

	void M11() {
		stride = 2;
		D11.resize(8, vector<vector<float>>(8, vector<float>(20)));
		for (int k = 0; k < 20; k++) { // for each cross section k
			for (int m = 0, i = 0; m < 16; m += stride, i++) { //for row m
				for (int n = 0, j = 0; n < 16; n += stride, j++) { // for column n
					D11[i][j][k] = max({ D10[m][n][k], D10[m + 1][n][k], D10[m][n + 1][k], D10[m + 1][n + 1][k] }); // Compute D11(L7) using D10(L6)
				}
			}
		}
	}

	void M12(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D13.resize(5, vector<vector<vector<float>>>(5, vector<vector<float>>(20, vector<float>(20))));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 20; k++) {
						for (int l = 0; l < 20; l++) {
							file >> D13[i][j][k][l]; // Read convolution filters data and initialize D13
						}
					}
				}
			}
			file.close();
		}
	}

	void M13(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D14.resize(20);
			for (int i = 0; i < 20; i++) {
				file >> D14[i]; // Read bias vector data and initialize D14
			}
			file.close();
		}
	}

	void M14() {
		stride = 1;
		D12.resize(8, vector<vector<float>>(8, vector<float>(20)));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 20; k++) {
					D12[i][j][k] = 0; // Initialize L8 to 0
					for (int l = 0; l < 5; l++) {
						for (int m = 0; m < 5; m++) {
							for (int n = 0; n < 20; n++) {
								D12[i][j][k] += D11[i + l][j + m][n] * D13[l][m][n][k]; // Convolution operation
							}
						}
					}
					D12[i][j][k] += D14[k]; // Add bias vector
				}
			}
		}
	}

	void M15() {
		D15.resize(8, vector<vector<float>>(8, vector<float>(20)));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 20; k++) {
					D15[i][j][k] = max(0.0f, D12[i][j][k]); // Compute D15(L9) using D12(L8)
				}
			}
		}
	}

	void M16() {
		stride = 2;
		D16.resize(4, vector<vector<float>>(4, vector<float>(20)));
		for (int k = 0; k < 20; k++) { // for each cross section k
			for (int m = 0, i = 0; m < 8; m += stride, i++) { //for row m
				for (int n = 0, j = 0; n < 8; n += stride, j++) { // for column n
					D16[i][j][k] = max({ D15[m][n][k], D15[m + 1][n][k], D15[m][n + 1][k], D15[m + 1][n + 1][k] }); // Compute D16(L10) using D15(L9)
				}
			}
		}
	}

	void M17(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D18.resize(4, vector<vector<vector<float>>>(4, vector<vector<float>>(20, vector<float>(10))));
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 20; k++) {
						for (int l = 0; l < 10; l++) {
							file >> D18[i][j][k][l]; // Read convolution filters data and initialize D18
						}
					}
				}
			}
			file.close();
		}
	}
	void M18(const string& inputFile) {
		ifstream file(inputFile);
		if (file.is_open()) {
			D19.resize(10);
			for (int i = 0; i < 10; i++) {
				file >> D19[i]; // Read bias vector data and initialize D19
			}
			file.close();
		}
	}

	void M19() {
		D17.resize(10);
		for (int i = 0; i < 10; i++) {
			D17[i] = 0; // Initialize D17 to 0
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 20; l++) {
						D17[i] += D16[j][k][l] * D18[j][k][l][i]; // Dot product operation
					}
				}
			}
			D17[i] += D19[i]; // Add bias vector
		}
	}

	void M20() {
		float sumOfSquares = 0.0f;
		for (int i = 0; i < 10; i++) {
			sumOfSquares += pow(D17[i], 2); // Calculate the sum of squares of each element in D17
		}
		float normalizationFactor = sqrt(sumOfSquares); // Calculate the square root of the sum of squares

		for (int i = 0; i < 10; i++) {
			D17[i] /= normalizationFactor; // Normalize each element in D17 by dividing it by the normalization factor
		}
	}

	void M21() {
		float sumExp = 0.0f;
		for (int i = 0; i < 10; i++) {
			sumExp += exp(D17[i]); // Calculate the sum of exponentials of each element in D17
		}

		for (int i = 0; i < 10; i++) {
			D20.push_back(exp(D17[i]) / sumExp); // Compute the softmax function for each element in D17
		}
	}

	void M22() {
		cout << "D20: " << endl;
		for (int i = 0; i < 10; i++) {
			cout << D20[i] << " "; // Print the output of layer L12
		}
		cout << endl;
	}
};
