//Something in me itches again, it's the pointers
#include <iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

int main (int argc, char ** argv) {
	
	//the normal pointer
	int number = 18;
	int * num_pointer = &number;

	//the pointer to pointer
	//pointers stores the address of a value , so
	//pointer to pointer stores the address of the address of 
	//a pointer
	int f_number = 5;
	int * first_pointer = &f_number;
	int ** second_pointer = &first_pointer;

	cout << "Number: " << number << endl;
	cout << "Num Pointer Dereferenced: " << *num_pointer << endl;

	cout << "F Number: " << &f_number << endl;
	cout << "Second Pointer Dereferenced: " << &second_pointer << endl;	
	cout << "First Pointer Dereferenced: " << &first_pointer << endl;
	cout << "Second Pointer Dereferenced: " << *second_pointer << endl;	

	node * head = NULL;

	node * first = new node;
	first->data = 18;

	node * second = new node;
	second->data = 95;

	node * nullast = new node;
	nullast->data = 0;

	head = first;

	first->next = second;
	second->next = nullast;
	nullast->next = NULL;

	node ** cheater_pointer = &head;

	//aha! dereferencing a pointer to pointer is like this?
	cout << (*cheater_pointer)->data << endl;
	cout << first->data << endl;
	cout << *cheater_pointer << endl;

	return 0;
}