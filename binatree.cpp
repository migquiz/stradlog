//Binary Tree
#include <iostream>
#include <stack>
using namespace std;

struct tree_node {
	int data;
	tree_node * left = NULL;
	tree_node * right = NULL;
};

class Binatree {
public:
	Binatree () {};
	Binatree (tree_node * _root);
	tree_node * getroot ();
	bool search (int data_value, tree_node * node);
	void insert (int data_value, tree_node * node);
	void display (tree_node * node);
	tree_node * deletion (int data_value , tree_node * node);
	tree_node * lift (tree_node * node, tree_node * node_delete);
private:
	tree_node * root = NULL;
};

// Binatree::Binatree () {};

Binatree::Binatree (tree_node * _root) {
	root = _root;
}

tree_node * Binatree::getroot () {
	return root;
}

void Binatree::display (tree_node * node) {
	
	if (node == NULL) {
		return;
	}

	cout << node->data << endl;

	display (node->left);
	display (node->right);
}

tree_node * Binatree::deletion (int data_value, tree_node * node) {
	//the nodes in here retain the same value over the runtime stack 
	//unless it is overwritten in the condition
	if (node == NULL) {
		return NULL;
	} else if (data_value < node->data) { 
		//left sub tree assigned
		node->left = deletion (data_value, node->left);
		return node; //return the very first node passed
	} else if (data_value > node->data) {
		//same here
		node->right = deletion (data_value, node->right);
		return node; //the same node but changed
	} else if (data_value == node->data) {
		if (node->left == NULL) {
			//we're returning a right subtree if existent
			//else null , deletion happens here
			return node->right;
		} else if (node->right == NULL) {
			return node->left;
		} else {
			//we go to the right then left to find the
			//least greater value
			node->right = lift (node->right, node);
			return node;
		}
	}
}

tree_node * Binatree::lift (tree_node * node, tree_node * node_delete) {
	//to find the successor node
	if (node->left) {
		//it's left in here
		//if successor has a right child (below)
		//it'll be a left child of the succesor
		node->left = lift (node->left , node_delete);
		//the left most bottom node
		return node; 
	} else {
		//the successor node has been found
		node_delete->data = node->data;
		//right node will be returned if the successor node has it
		return node->right;
	}
}

void Binatree::insert (int data_value, tree_node * node) {
	
	if (node == NULL) {
		tree_node * new_node = new tree_node;
		new_node->data = data_value;
		root = new_node;
		return;	
	}
	
	// if (node->data == data_value) {
	// 	return;
	// }

	if (node->data > data_value) {
	// cout << node << endl;
		if (node->left == NULL) {
			tree_node * left_node  = new tree_node;
			left_node->data = data_value;
			node->left = left_node;
		} else {
			insert (data_value, node->left);
		}
	}
	// else 
	if (node->data < data_value) {
		if (node->right == NULL) {
			tree_node * right_node  = new tree_node;
			right_node->data = data_value;
			node->right = right_node;
		} else {
			insert (data_value, node->right);
		}	
	}
}

bool Binatree::search (int data_value, tree_node * node) {
	if (node == NULL) {
		cout << "no" << endl;
		return false;
	}
	if (node->data == data_value) {
		cout << "yes" << endl;
		return true;
	}
	if (node->data > data_value) {
		search (data_value, node->left);
	}
	if (node->data < data_value) {
		search (data_value, node->right);
	}
}

int main (int argc, char ** argv) {

	// tree_node * _root = new tree_node;
	// tree_node * uno_first = new tree_node;
	// tree_node * uno_second = new tree_node;
	// tree_node * dos_first = new tree_node;
	// tree_node * dos_second = new tree_node;
	// tree_node * dos_third = new tree_node;
	// tree_node * dos_fourth = new tree_node;

	// _root->data = 10;
	// uno_first->data = 5;
	// uno_second->data = 25;
	// dos_first->data = 2;
	// dos_second->data = 6;
	// dos_third->data = 11;
	// dos_fourth->data = 28;

	// _root->left = uno_first;
	// _root->right = uno_second;
	// uno_first->left = dos_first;
	// uno_first->right = dos_second;
	// uno_second->left = dos_third;
	// uno_second->right = dos_fourth;

	// Binatree good (_root);

	// tree_node * node_pointer = good.getroot();
	// stack<tree_node *> nodes;
	// nodes.push (node_pointer);

	//trying to traverse the binary through a stack
	// while (!nodes.empty()) {
	// 	tree_node * curr_node = nodes.top();
	// 	cout << curr_node->data << endl;
	// 	nodes.pop();
	// 	if (curr_node->left != NULL) nodes.push(curr_node->left);
	// 	if (curr_node->right != NULL) nodes.push(curr_node->right);
	// }

	Binatree good;
	
	good.insert (6,good.getroot());
	
	good.display (good.getroot());
	
	return 0;
}