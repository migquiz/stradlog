//A Graph Implementation of a simple degree of connections
//Breadth First Traversal meaning nodes are visted from top to bottom
//this is a work in progress
#include <iostream>
#include <map>
#include <queue>
using namespace std;

void traverse () {
	//mark the each adjacent vertex visited if not been visited then add
	//it to the queue

	//if the current vertex has no unvisited vertex , remove the next vertex
	//from the queue and make it the current vertex

	//if thres no more vertices unvisited and no more vertices in queue, it's
	//complete
}

int main (int argc, char ** argv) {

	map<char,vector<char>> network;
	network = {
		{'m',{'i','g','u'}},
		{'i',{'o','g'}},
		{'g',{}},
		{'u',{'r'}}
	};

	traverse (network);

	return 0;
}