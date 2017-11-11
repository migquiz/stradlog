//Stacks
//End is the key to everything, you can only
//insert,remove and read from this thing.
//Here is a linting exercise

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Linter {
public:
	Linter();
	void lint (string expression);
	bool isOpeningBrace (char token);
	bool isClosingBrace (char token);
	void peakTheStack ();
private:
	void seeTheStack ();
	stack<char> foo_stack;
	map<char,char> braces = {
		{')','('},{']','['},{'}','{'}
	};
};

Linter::Linter() {
	foo_stack = {};
}

void Linter::peakTheStack () {
	if (foo_stack.empty()) {
		cout << "EMPTY KAPITAN" << endl;
	} else {
		cout << foo_stack.top() << endl;
	}
}

bool Linter::isOpeningBrace (char token) {
	string opening_braces = "({[";
	for (char brace : opening_braces) {
		if (brace == token) {
			return true;
		}
	}
	return false;
}

bool Linter::isClosingBrace (char token) {
	string closing_braces = ")}]";
	for (char brace : closing_braces) {
		if (brace == token) {
			return true;
		}
	}
	return false;
}

void Linter::lint (string expression) {
	for (char token : expression) {
		//let's try to put the opening braces first in the stack
		if (isOpeningBrace(token)) {
			foo_stack.push (token);
		} else if (isClosingBrace(token)) { 
		//if the token is closing brace
			//if the closing brace matches the opening brace then pop
			//we have to check first if the stack is not empty first
			//if fails we don't have to check the top
			if ((!foo_stack.empty()) && braces[token] == foo_stack.top()) {
				//if there a match with the opening brace
				//yes then pop the opening brace in the stack
				foo_stack.pop();
			} else {
				//else there's no matching opening brace
				//return error
				cout << "ERROR:::::::::::ERROR:::NO::MATCHING::OPENING::BRACE" << endl;
			}
		}
	}
	if (!foo_stack.empty()) {
		cout << "ERORR:::LEFTOVER:: " << foo_stack.top() << endl;
	}
}

int main (int argc, char ** argv) {

	//try to extract the tokens on a string first
	Linter foo_linter;
	foo_linter.lint ("((}]]))");
	foo_linter.peakTheStack();

	return 0;
}