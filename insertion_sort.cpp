//Insertion Sorting
//Works by comparing the next value to the left
//while it's not the end of an array

//To make an insertion, a gap must be made first
//then if the value is greater than it's left
//shift until it's not. Sort when it meets the end.

#include <iostream>
using namespace std;

void insertion_sort (int *num, int length) {
	for (int i = 0; i < length; i++) {
		
		//start with the second element for comparison
		int index = i + 1;
		int position = index;
		//this is where the comparison against happens.
		int temp_value = num [position];

		//is to shift to right unless a lower value was encountered
		while (position > 0 && num[position - 1] > temp_value) {
			num [position] = num [position - 1];
			position = position - 1;
		}

		num [position] = temp_value;

	}
}

int main (int argc, char ** argv) {

	int num [5] = {1,2,3,4,5};
	insertion_sort (num,5);
	for (int i = 0; i < 5; i++) {
		cout << num [i] << endl;
	}

	return 0;
}