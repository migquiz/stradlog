//A short implementation of social networking
//through the use of graphs
//this is work in progress.
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void get_homies (queue<char> nodes, map<char,vector<char>> graph, char key) {
	if (nodes.empty()) {
		return;
	}
	for (char keyor : graph[key]) {
		if (key == keyor) continue;
		nodes.push(keyor);
	}
	cout << nodes.front();
	nodes.pop();
	get_homies (nodes, graph, nodes.front());
}

int main (int argc, char ** argv) {

	//graphs implemented through a hash
	map<char,vector<char>> grapho;

	grapho = {
		{'m',{'i','a'}},
		{'i',{'m','g','n'}},
		{'a',{'m','n'}},
		{'n',{'i','a','e'}},
		{'g',{'i','u','e'}},
		{'u',{'g','e','p'}},
		{'e',{'n','g','u','l'}},
		{'p',{'u','l'}},
		{'l',{'p','e'}},
		{'a',{'x','l'}},
		{'x',{'a'}}
	};

	queue<char> nodes;
	nodes.push ('m');
	get_homies (nodes,grapho,'m');

	return 0;
}