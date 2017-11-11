//Simple Countdown Exercise
//Using Recursion
#include <iostream>
#include <stdlib.h>
using namespace std;

void countdown (int number) {
	
	if (number == 0) {
		return;
	}
	
	cout << number << " " ;
	system("sleep 1s");
	countdown (number - 1);
}

int factorial (int number) {
	if (number == 1) {
		return 1;
	}
	if (number == 0) {
		return 0;
	}
	return factorial (number - 1) * number;
}

int main (int argc, char ** argv) {
	countdown (10);
	cout << factorial (10) << endl;
	return 0;
}