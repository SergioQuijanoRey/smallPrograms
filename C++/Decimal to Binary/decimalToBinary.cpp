/*
Autor:
	Sergio Quijano Rey
	sergiquijano@gmail.com
Version:
	v1.0 17th October, 2017
Program Description:
	Given a number in base ten, the program returns the number in base two (binary)
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int convertToBinary(int decimalNumber);

int main(){
	int decimalNumber;
	int binaryNumber;
	
	cout << "Introduce a number in base ten: ";
	cin >> decimalNumber;

	binaryNumber = convertToBinary(decimalNumber);

	cout << "\tDecimal Number: " << decimalNumber << endl;
	cout << "\tBinary Number: " << binaryNumber << endl;
}

//Returns the binary expression of a decimal number through an integer
int convertToBinary(int decimalNumber){
	int binaryNumber = 0;
	int i = 0;
	long unsigned int maxIterations = pow(10,10);

	int remainder;
	int dividend = decimalNumber;
	
	while(true){
		remainder = dividend % 2;
		binaryNumber = binaryNumber + pow(10, i) * remainder;
		dividend = dividend / 2;

		i++;

		//Division algorithm ends at 1 / 2
		if(dividend == 1){
			binaryNumber = binaryNumber + pow(10, i) * dividend;
			return binaryNumber;
		}
		
		//The loop went over the established maximum of iterations
		if(i > maxIterations){
			cout << "Overflow" << endl;
			return -1;
		}
	}
}