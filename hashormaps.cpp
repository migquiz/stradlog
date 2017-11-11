//Hash Tables are key value pairs
//or associative arrays or
//maps in C/C++

//TODO : To sort the table based
//on the number of votes on a candidate

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void addSpaces (string test,int length_of_longest_string) {
	for (int i = 0; i < (length_of_longest_string - test.length()); i++) {
		cout << " ";
	}
}

int main (int argc, char ** argv) {

	vector<string> candidates = {"Miguel","Miguel",
	"Dexter","Ericson","Stark","Miguel","Bruce",
	"Richards","Bruce","Stark","Santiagos",
	"John Kevin","Amber","Amber","Amber","Amber"
	,"Amber","Amber","Amber"};

	map<string,int> ballox;

	string longest_name = "";

	for (string data : candidates) {
		++ballox[data];
		//this is for looking the candidate with the longes name
		if (data.length() > longest_name.length()) {
			longest_name = data;
		}
	}

	for (auto map_it = ballox.begin(); map_it != ballox.end(); ++map_it) {
		cout << "Candidates: " << map_it->first;
		addSpaces (map_it->first,longest_name.length());
		cout << " | Vote Count: " << map_it->second << endl;
	}

	return 0;
}