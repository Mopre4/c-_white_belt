#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream input("input.txt");
	double num;
	if (input) {
		while (input >> num) {
			cout << fixed <<  setprecision(3) << num << endl;
		}
		
	}
}
