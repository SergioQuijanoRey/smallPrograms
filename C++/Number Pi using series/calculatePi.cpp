#include <iostream>
#include <cmath>
using namespace std;

/*
Author:
    Sergio Quijano Rey
    sergiquijano@gmail.com
Description:
    The program calculates the number Pi using the wide known Basilea's serie
Version:
    v1.0 7th November 2017: first functionally version of the program
*/

long double calculatePi(int limit){
    double sum = 0;
    long double pi;

    for(int i = 1; i < limit; i++){
        sum = sum + (1.0 / (i * i));
    }

    pi = sqrt(6.0 * sum);
    return pi;
}

int main(){
    int top;

    cout << "Introduce the limit of the calculations: ";
    cin >> top;

    long double PI = calculatePi(top);
    cout << "The value of Pi calculated through " << top << " iterations is: " << PI << endl;

    return 0;
}
