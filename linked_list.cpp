//Another review of linked list data structure
#include <iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

typedef node * linked_list;

class Linked_list {
public:
	Linked_list(node * fnode);
	int read (int index);
	void insert (int index, int value);
	void display ();
private:
	node * first_node;
};

Linked_list::Linked_list(node * fnode) {
	first_node = fnode;  
}

int Linked_list::read (int index) {
	node * pointer = first_node;
	int locator = 0;
	while (locator < index) {
		pointer = pointer->next;
		++locator;
		if (pointer == NULL) {
			return 0;	
		}
	}
	return pointer->data;
}

void Linked_list::insert (int index, int value) {


	node * pointer = first_node;
	int location = 0;

	//just in case separate this into insert a beginning
	if (index == 0) {
		node * new_node = new node;
		new_node->data = value;
		new_node->next = pointer;
		first_node = new_node;		
	}

	//insert in between
	while (location < index) {
		pointer = pointer->next;
		++location;
	}

	//insert at end

}

void Linked_list::display() {
	node * pointer = first_node;
	while (pointer != NULL) {
		cout << pointer->data << " ";
		pointer = pointer->next;
	}
	cout << endl;
}

int main (int argc, char ** argv) {

	node * unode = new node;
	unode->data = 9;

	node * dosnode = new node;
	dosnode->data = 18;

	node * tresnode = new node;
	tresnode->data = 95;

	node * quanode = new node;
	quanode->data = 5;

	node * quinode = new node;
	quinode->data = 34;

	unode->next = dosnode;
	dosnode->next = tresnode;
	tresnode->next = quanode;
	quanode->next = quinode;
	quinode->next = NULL;

	Linked_list our_linkedlist(unode);

	our_linkedlist.display();
	our_linkedlist.insert(0,3);
	our_linkedlist.display();

	return 0;
}