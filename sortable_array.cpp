//Sortable Array
//contains a partitioning mechanism
//that is necessary for quicksort
#include <iostream>
using namespace std;

class SortableArray {
public:
	SortableArray (int num[],int size);
	void display ();
	int partitioner (int left_pt, int right_pt);
	void quicksort(int left_index, int right_index);
	int quickselect (int kth_position, int left_index, int right_index);
private:
	int arr_num[6];
	void swap (int a_pointer, int b_pointer);
};

SortableArray::SortableArray (int num[],int size) {
	for (int i = 0; i < size; i++) {
		arr_num[i] = num[i];		
	}
}

void SortableArray::quicksort (int left_index, int right_index) {
	//when the sub array has 0 element return
	if (right_index - left_index <= 0) {
		return;
	}
	int pivot_position = partitioner (left_index,right_index);
	quicksort (left_index, pivot_position - 1);
	quicksort (pivot_position + 1, right_index);
}

int SortableArray::quickselect (int kth_position, int left_index, int right_index) {
	if (right_index - left_index <= 0) {
		return arr_num[left_index];
	}
	int pivot_position = partitioner (left_index, right_index);
	if (kth_position > pivot_position) {
		quickselect (kth_position, pivot_position + 1, right_index);
	} else if (kth_position < pivot_position) {
		quickselect (kth_position, left_index, pivot_position - 1);
	} else {
		return arr_num [pivot_position];
	}
}

void SortableArray::swap (int a_pointer, int b_pointer) {

	int temp = arr_num[a_pointer];
	arr_num[a_pointer] = arr_num[b_pointer];
	arr_num[b_pointer] = temp;
}

int SortableArray::partitioner (int left_pt, int right_pt) {
	int pivot_num = arr_num[right_pt];
	int pivot_position  = right_pt;

	--right_pt;

	while (true) {
		//to find the number that is greater than the pivot number
		while (arr_num[left_pt] < pivot_num) {
			++left_pt;
		}
		//to find the number that is less than the pivot number
		while (arr_num[right_pt] > pivot_num) {
			--right_pt;
		}
		//to perform a swap
		if (left_pt >= right_pt) {
			break;
		} else {
			swap (left_pt,right_pt);
		}
	}

	swap (left_pt, pivot_position);
	return left_pt;
}

void SortableArray::display () {
	for (int i = 0; i < 6; i++) {
		cout << arr_num[i];
	}
}

int main (int argc, char ** argv) {
	
	int size = 6;
	int test_data [6] {2,5,2,3,6,3};
	SortableArray sortable_array(test_data,size);
	sortable_array.display();
	cout << endl;
	sortable_array.quicksort(0,5);
	sortable_array.display();
	cout << endl;
	cout << sortable_array.quickselect (3,0,size - 1);
	
	return 0;
}