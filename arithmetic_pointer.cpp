//I have watched the cs50 about pointer
//arithmetic and have to give it a try
#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

	int num[10] = {2,4,3,12,6,23,12,64,64,3};
	int * pointer_num = num;

	//find this funny in my part. LOL . haha
	cout << * (++(++(++pointer_num))) << endl;

	//inserting a number in array
	//beginning . N + 1 steps

	//i need to build a new array with one cell more
	//than the original array
	int input_num = 0;
	int size = 0;
	int input_arr[size];
	
	cout << "Enter Numbers to be inserted in array: ";
	cin >> input_num;
	while (input_num) {
		size++;
		input_arr[size];
		input_arr[size - 1] = input_num;
		cin >> input_num;
	}

	//copy the values in the original array to new array
	int new_size = 10 + size;
	num[new_size];

	for (int i = 0; i < size; i++) {
		num[10+i] = input_arr[i];
	}

	for (int i = 0; i < new_size; i++) {
		cout << num[i] << endl;
	}

	return 0;
}