//All of ordered array functions and features
//search, insert (i hope it's right), display
//binary search
#include <iostream>
using namespace std;

//it's a bit long , isn't it e'.?
void insertion(int num [], int size, int to_be_inserted) {

	int upSize = size + 1;
	int position = 0;
	
	for (int i = 0; i < size; i++) {
		if (num[i] >= to_be_inserted) {
			position = i ;
			break;
		}
		if (i == size - 1) {
			position = size;
			break;
		}
	}
	
	cout << "Position: " << position << endl;
	cout << "Size: "<< size << endl;

	num[upSize];//add another slot
	
	for (int i = size - 1; i >= position ; i--) {
		num[i+1] = num [i];
	}

	num[position] = to_be_inserted;
} 

void just_display (int num[], int size){
	for (int i = 0; i < size; i++) {
		cout << num[i] << endl;
	}
}

bool search (int num[], int size, int to_be_searched) {
	for (int i = 0; i < size; i++) {
		if (num[i] == to_be_searched) {
			cout << "Found at : " << i << endl;
			return true;
		} else if (num[i] > to_be_searched || i == size - 1) {
			cout << "Not Found : " << endl;
			break;
			return false;
		}
	}
}

int binary_search (int num[], int size , int value) {

	int lower_bound =  0;
	int upper_bound = size - 1;

	while (lower_bound <= upper_bound) {
		int midpoint = (lower_bound + upper_bound) / 2;
		int value_mid = num [midpoint];
		if (value < value_mid) {
			upper_bound = midpoint - 1;
		} else if (value > value_mid) {
			lower_bound = midpoint + 1;
		} else if (value == value_mid) {
			return midpoint;
		}
	}
	return false;
}

int main (int argc, char ** argv) {
	//if this is an ordered array	
	int size = 10;
	int num[10] {10,20,30,40,50,60,70,80,90,100};
	//insertion
	int * refarr = num;
	insertion(refarr, size, 550); //array was passed as a referenced
	//side effects occur
	//search
	search(num, size + 1, 1550);
	//display
	just_display(num, size + 1);
	return 0;
}