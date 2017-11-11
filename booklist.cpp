//BookList 
//Binary Tree in Action
//Insert, Retrieve, Search, Delete
#include <iostream>
using namespace std;

struct tree_node {
	string book_title;
	int number;
	tree_node * left = NULL;
	tree_node * right = NULL;
} typedef book_node;

typedef book_node * book;
//===================== BOOKS =========================
class Books {
public:
	Books ();
	Books (book root);
	// book & root (); return a reference to pointer node
	book root ();
	void display (book node);
	void insert (string book_title, book node);
	void insert (int number, book node); //don't have the same signature
	void traverse (book node);
	void traverse_num (book node);
private:
	book root_book;
};

Books::Books () {
	root_book = NULL;
}

Books::Books (book root) {
	root_book = root;
}

//to return a reference to a pointer
// book & Books::root () {
// 	return root_book;
// }

book Books::root () {
	return root_book;
}


void Books::display (book node) {
	if (node == NULL) {
		return;
	}
	cout << node->book_title << endl;
	display (node->left);
	display (node->right);
}

void Books::insert (string book_title, book node) {
	if (root_book == NULL) {
		book new_book = new book_node;
		new_book->book_title = book_title;
		root_book = new_book;
		return;
	}
	if (book_title < node->book_title) {
		if (node->left == NULL) {
			book new_book = new book_node;
			new_book->book_title = book_title;
			node->left = new_book;
		} else {
			insert (book_title, node->left);
		}
	} else 
	if (book_title > node->book_title) {
		if (node->right == NULL) {
			book new_book = new book_node;
			new_book->book_title = book_title;
			node->right = new_book;
		} else {
			insert (book_title, node->right);
		}
	}
}

void Books::insert (int number, book node) {
	if (root_book == NULL) {
		book new_book = new book_node;
		new_book->number = number;
		root_book = new_book;
		return;
	}
	if (number < node->number) {
		if (node->left == NULL) {
			book new_book = new book_node;
			new_book->number = number;
			node->left = new_book;
		} else {
			insert (number, node->left);
		}
	} else 
	if (number > node->number) {
		if (node->right == NULL) {
			book new_book = new book_node;
			new_book->number = number;
			node->right = new_book;
		} else {
			insert (number, node->right);
		}
	}
}

void Books::traverse (book node) {
	if (node == NULL) {
		return;
	}
	if (node->left == NULL && node->right == NULL) {
		cout << node->book_title << endl;
		return;
	}
	traverse (node->left);
	cout << node->book_title << endl;
	traverse (node->right);
}

void Books::traverse_num (book node) {
	if (node == NULL) {
		return;
	}
	if (node->left == NULL && node->right == NULL) {
		cout << node->number << endl;
		return;
	}
	traverse_num(node->left);
	cout << node->number << endl;
	traverse_num (node->right);
}

//===================== BOOKLIST =========================
class BookList {
public:
	BookList ();
private:
};
//=======================================================

int main (int argc, char ** argv) {
	
	// Books books;
	// // book &root = books.root();

	// books.insert ("Miguel",books.root());
	// books.insert ("Browser",books.root());
	// books.insert ("Pogo",books.root());
	// books.insert ("Brackets",books.root());
	// books.insert ("Mantis",books.root());
	// books.insert ("Ongga",books.root());
	// books.insert ("Zeulyn",books.root());
	// books.insert ("Zanggo",books.root());
	
	// // books.display (books.root());

	// //inorder traversal
	// books.traverse (books.root());


	Books oather;
	oather.insert (4,oather.root());
	oather.insert (2,oather.root());
	oather.insert (1,oather.root());
	oather.insert (3,oather.root());
	oather.insert (6,oather.root());
	oather.insert (5,oather.root());
	oather.insert (7,oather.root());

	oather.traverse_num (oather.root());
	return 0;
}
