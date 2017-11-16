//A short implementation of social networking
//through the use of graphs

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main (int argc, char ** argv) {

	//graphs implemented through a hash
	map<string,string> friends  =  {
		{"miguel","this"},
		{"quizon","the second"}
	};

	map<string,vector<string>> nodes = {
		{"miguel",{"bulb","light","year"}}
	};

	vector<string> init = {"this","quick","brown"};

	cout << friends["miguel"] << endl;
	cout << init[0] << endl;
	cout << nodes["miguel"][0] << endl;

	for (auto testing : nodes["miguel"]) {
		cout << testing << endl;
	}

	return 0;
}