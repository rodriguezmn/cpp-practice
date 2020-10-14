// Calculates interest

#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char** argv) {

	// Initialize variables 

	double principal{500};
	double rate{.02};
	double time{5};
	double interest;

	// Calculate interest

	interest = principal * rate * time;

	cout << interest << endl;

	return 0;
}