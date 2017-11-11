//Print Manager utilizing the power of Queue
#include <iostream>
#include <queue>
using namespace std;

class PrintManager {
public:
	PrintManager();
	void enqueue_printjob (string file_name); 
	void run ();
private:
	queue<string> print_queue;
	void print(string file_name);
};

PrintManager::PrintManager() {
	print_queue = {};
}

void PrintManager::enqueue_printjob (string file_name) {
	print_queue.push(file_name);
}

void PrintManager::run() {
	cout << "========== Printing ==========" << endl;
	while (!print_queue.empty()) {
		print(print_queue.front());
		print_queue.pop();
	}
	cout << "=========== DONE !! ==========" << endl;
}

void PrintManager::print(string file_name) {
	cout << file_name << endl;
}

int main (int argc, char ** argv) {

	PrintManager rugemi_printmgr;

	string file_names[5] = {"Epson","Hewlett Packard","Brother","Canon","Fujitsu"};

	for (string names : file_names) {
		rugemi_printmgr.enqueue_printjob(names);
	}

	rugemi_printmgr.run();

	return 0;
}