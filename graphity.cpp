//A city on weighted graphs
//Implemented by hashes
//To be an element of a container , the object passed should be
//copy-able or moveable.
//A Work in Progress, learn from the statements above.
//Djikstras Algorithm too.
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class City {
public:
	City () {};
	City (string name);
	City & operator=(City &);
	string getname ();
	void set_name (string that);
	void add_route (City , int);
	void display_path (City destination);
private:
	string city_name;
	map<City, int> routes;
};

City::City (string name) {
	city_name = name;
}

City & City::operator=(City & this_city) {
	this->city_name = this_city.city_name;
	return *this;
}

string City::getname () {
	return city_name;
}

void City::set_name (string that) {
	city_name = that;
}

void City::add_route (City ciudad, int price) {
	//this is a hash or map or assoc. container
	routes [ciudad] = price;
}

void display_path (City destination) {
	City current_vertex = *this;
	stack<City> adjacent_vertices;
	City cheapest = *this;

	//iterate through the routes
	while (!current_vertex.routes.end()) {
		if (cheapest > current_route) {
			cheapest = current_route;
		}
	}
}

int main (int argc, char ** argv) {
	
	City Batangas ("Batangas");
	City Calamba ("Calamba");
	City Laguna ("Laguna");
	City Rizal ("Rizal");
	City Quezon ("Quezon");

	Batangas.add_route (Calamba,104);
	Batangas.add_route (Rizal,317);
	Batangas.add_route (Laguna,214);

	return 0;	
}