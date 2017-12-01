//A graph reimplementation in C++
//Person have networks
//The lower levels should be added first 
//so referencing the object a topmost layer
//will be successful
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Person {
public:
	Person ();
	Person (string _name);
	void add_friend (Person *friend_instance);
	string get_name ();
	void display_network ();
	void visit_done ();

	string name;
	vector<Person> friends;
	bool visited;
};

Person::Person () {}

Person::Person (string _name) {
	name = _name;
	visited = false;
}

void Person::add_friend (Person *friend_instance) {
	friends.push_back (*friend_instance);
}

string Person::get_name () {
	return name;
}

void Person::visit_done () {
	visited = true;
}

void Person::display_network () {
	
	vector<Person> to_reset = {*this};
	queue<Person> person_queue;
	Person current_vertex;

	person_queue.push (*this);
	this->visited = true;

	while (!person_queue.empty()) {
		current_vertex = person_queue.front ();
		person_queue.pop ();

		cout << current_vertex.name << endl;

		for (Person friendie : current_vertex.friends) {
			if (!friendie.visited) {
				to_reset.push_back (friendie);
				person_queue.push (friendie);
				friendie.visited = true;
			}
		}
	}

	for (Person node : to_reset) {
		node.visited = false;
	}
}

int main (int argc, char ** argv) {

	Person Alice ("Alice");
	Person Elaine ("Elaine");
	Person Candy ("Candy");
	Person Derek ("Derek");
	Person Helen ("Helen");
	Person Irena ("Irena");
	Person Fred ("Fred");
	Person Gina ("Gina");
	Person Bob ("Bob");

	Bob.add_friend (&Fred);
	Bob.add_friend (&Helen);

	Derek.add_friend (&Gina);
	Derek.add_friend (&Irena);

	Gina.add_friend (&Elaine);

	Alice.add_friend (&Bob);
	Alice.add_friend (&Candy);
	Alice.add_friend (&Derek);
	Alice.add_friend (&Elaine);

	Alice.display_network();

	cout << endl << endl;

	Bob.display_network();

	return 0;

}