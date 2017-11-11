//Selection Sorting
//Once a number encounters a lower value
//take the position then
//than itself it swaps position with that number
//then starts with the next while it's not the end

//Works by swapping the least value on the array
//by going through it.

#include <iostream>
using namespace std;

void selection_sort (int *num, int length) {
	for (int i = 0; i < length; i++) {
		int low_num_index = i;

		for (int j = i+1; j < length; j++) { //start with
			//the next value,right?
			if (num[j] < num [low_num_index]) {
				low_num_index = j;
			}
		} //when it reaches or traverse at the end
		//we now know the positions to be swapped
		//then we will start at the next position
		//using the outer loop
		if (low_num_index != i) {
			int temp = num [i];
			num [i] = num [low_num_index];
			num [low_num_index] = temp;
		}
	}
}

int main (int argc, char ** argv) {

	int num[10] = {95,4,23,5,18,0,22,13,9,1};
	selection_sort (num, 10);
	for (int i = 0; i < 10; i++) {
		cout << num [i] << endl;
	}
	return 0;
}