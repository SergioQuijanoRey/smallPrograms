/*
	Description:
		Calculates the number PI using the Montecarlo's Method
	Author:
		Sergio Quijano Rey
		sergiquijano@gmail.com
	Version:
		v1.0 26th Jaunary 2018, first funtionaly version
*/
#include <iostream>
#include <vector>
#include <cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

//FUNCTIONS
void startRandom(){
	srand(time(NULL));
}

/*
	Generates a fractionary random number between 0 and 1
*/
long double randomOne(){
	long double num1 = rand();
	long double num2 = rand();
	long double result;

	if(num1 < num2){
		result = num1 / num2;
	}else{
		result = num2 / num1;
	}

	return result;
}

/*
	Generates a fractionary random number between 0 and max
*/
long double randomDouble(double max){
	double value = randomOne() * max;
 	return value;
}

long double calculateDistance(long double x1, long double y1, long double x2, long double y2){
	long double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return dist;
}

//MAIN PROGRAM
int main(){
	const long double squareSide = 10.0;
	const long double xCenter = squareSide / 2.0;
	const long double yCenter = squareSide / 2.0;
	const long double radius = squareSide / 2.0;
	long long int inside = 0;
	long double PI;

	long long int repeatNumber;
	long double xIn;
	long double yIn;
	long double distance;


	cout << "Introduce the number of tries: ";
	cin >> repeatNumber;

	for(int i = 0; i < repeatNumber; i++){
		xIn = randomDouble(squareSide);
		yIn = randomDouble(squareSide);
		cout << endl;


		distance = calculateDistance(xCenter, yCenter, xIn, yIn);
		if(distance < radius){
			inside++;
		}
	}
	
	PI = (long double)4.0 * (((long double) inside) / ((long double) repeatNumber));
	cout << "The number PI equals " << PI << endl;
}
