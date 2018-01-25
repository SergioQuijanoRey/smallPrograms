#include <iostream>
#include <vector>
#include <cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Precision of the floating point numbers is stablished
typedef long double cordinate;

//FUNCTIONS
void startRandom(){
	srand(time(NULL));
}

cordinate randomInt(int min, int max){
     cordinate value =  min + rand() % (max +1 - min);
     return value;
}

cordinate calculateDistance(cordinate x1, cordinate y1, cordinate x2, cordinate y2){
	cordinate dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return dist;
}

//MAIN PROGRAM
int main(){
	const cordinate squareSide = 1000.0;
	const cordinate xCenter = squareSide / 2.0;
	const cordinate yCenter = squareSide / 2.0;
	const cordinate radius = squareSide / 2.0;
	int inside = 0;
	int repeatNumber;
	cordinate xIn;
	cordinate yIn;
	cordinate distance;
	cordinate PI;


	cout << "Introduce the number of tries: ";
	cin >> repeatNumber;

	for(int i = 0; i < repeatNumber; i++){
		xIn = randomInt(0, squareSide);
		yIn = randomInt(0, squareSide);


		distance = calculateDistance(xCenter, yCenter, xIn, yIn);
		if(distance < radius){
			inside++;
		}
	}

	PI = 4.0 * ((inside / repeatNumber) / ((squareSide * squareSide) / repeatNumber));
	cout << "The number PI equals " << PI << endl;
}