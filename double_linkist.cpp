//Double Linkist
//Because I love to combine names, it means doubly
//linked list. Not one but two pointers to the next
//and to the previous node, to add, both ends are null
#include <iostream>
using namespace std;

struct node {
	string data;
	node * prev;
	node * next;
};

class Double_Linkist {
public:
	Double_Linkist();
	Double_Linkist (node * front, node * rear);
	void insert_at_end (string value);
	node * remove_from_front ();
// private:
	node * first_node { NULL }; //the leftmost, if you imagine
	node * last_node { NULL }; //the rightmost, if you imagine
};

Double_Linkist::Double_Linkist() {
	node * first_node { NULL }; //the leftmost, if you imagine
	node * last_node { NULL }; //the rightmost, if you imagine	
}

Double_Linkist::Double_Linkist (node * front, node * rear) {
	first_node = front;
	last_node = rear;
}

void Double_Linkist::insert_at_end (string value) {
	node * new_node = new node;
	new_node->data = value;
	
	if (!first_node) {
		first_node = new_node;
		last_node = new_node;
	} else {
		new_node->prev = last_node;
		last_node->next = new_node;
		last_node = new_node;
		last_node->next = NULL;
		//i'm not sure but the new node has point to next a NULL
	}
}

node * Double_Linkist::remove_from_front () {
	node * removed_node = first_node;
	first_node = first_node->next;
	first_node->prev = NULL;
	//i'm not sure again but the the previous pointer should be NULL
	return removed_node;
}

class Queue {
public:
	Queue ();
	void enqueue (string value);
	void dequeue ();
	void tail ();
	void display ();
private:
	Double_Linkist queue;
};

Queue::Queue () {

};

void Queue::display () {
	node * pointer = queue.first_node;
	while (pointer != NULL) {
		cout << pointer->data << endl;
		pointer = pointer->next;
	}
}

void Queue::enqueue (string value) {
	queue.insert_at_end (value);
}

void Queue::dequeue () {
	queue.remove_from_front ();
}
//to do
void Queue::tail () {
	cout << queue.last_node->data;
}

int main (int argc, char ** argv) {

	Double_Linkist double_linkist;
	Queue this_queue;

	this_queue.enqueue ("once");
	this_queue.enqueue ("upon");
	this_queue.enqueue ("this");
	this_queue.enqueue ("moment");

	this_queue.display ();

	return 0;
}