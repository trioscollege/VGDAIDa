#include <iostream>
#include <string>

using namespace std;

#include "HashTable.h"


int main(void)
{
	// Key=string, Value=int
	HashTable<int> marks(13);

	// enter initial marks
	marks.insert("John", 75);
	marks.insert("Jim", 80);
	marks.insert("Sally", 25);
	marks.insert("Alan", 33);
	marks.insert("Lucy", 42);
	marks.insert("George", 78);
	marks.print();

	// print table structure
	marks.printTable();

	// update Sally's mark
	marks.insert("Sally", 92);
	cout << "Upated Sally's mark" << endl;
	marks.print();

	// Allan drops the course
	marks.remove("Alan");
	cout << "Alan dropped" << endl;
	marks.print();

	// Jim drops the course
	marks.remove("Jim");
	cout << "Jim dropped" << endl;
	marks.print();

	// Abe and Walter join the course late
	marks.insert("Abe", 50);
	marks.insert("Walter", 60);
	cout << "Abe and Walter joined" << endl;
	marks.print();

	// Sally drops the course
	marks.remove("Sally");
	cout << "Sally dropped" << endl;
	marks.print();
	
	// print table structure
	marks.printTable();

	// lookup John's mark
	HashTable<int>::Entry jmark = marks.find("John");
	if (jmark.isValid()) {
		cout << "John's mark is " << jmark.getValue() << endl;
		// update John's mark
		jmark.setValue(89);
		cout << "John's mark is now " << jmark.getValue() << endl;
	}	

	// lookup Bob's mark
	HashTable<int>::Entry bmark = marks.find("Bob");
	if (bmark.isValid()) {
		cout << "Bob's mark is " << bmark.getValue() << endl;
	} else {
		cout << "Bob not found" << endl;
	}
}
