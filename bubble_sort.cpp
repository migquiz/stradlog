//Bubble Sorting
//The number bubbles up into it's correct position.
//Arranges the position of values by comparing to 
//next value while it's not sorted

//Just like bubbles, the numbers work on their way
//up to their correct position until all are satisfied.

#include <iostream>
using namespace std;

void bubble_sort (int *num, int length) {
	
	bool sorted = false;
	//the array is sorted when no number in the array
	//is greater than it's succeeding number. lol. haha

	while (!sorted) {
		sorted = true;
		for (int i = 0; i < length; i++) {
			if (num [i] > num [i + 1]) {
				sorted = false;
				int temp = num [i];
				num [i] = num [i + 1];
				num [i + 1] = temp;
			}
		}
	}	
}

int main (int argc, char ** argv) {

	int num[10] = {95,4,23,5,18,0,22,13,9,1};
	int num_test_one [10]= {10,2,3,4,5,6,7,8,9,0};
	bubble_sort (num_test_one,10);

	for (int i = 0; i < 10; i++) {
		cout << num_test_one [i] << endl;
	}

	return 0;
}