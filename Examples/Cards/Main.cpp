#include <cstdlib>
#include <ctime>
using namespace std;

#include "Deck.h"


int main()
{
	srand((unsigned)time(NULL));

	Deck d1;          // creates a new (full) deck
	Deck d2(false);   // creates a new (empty) deck

	d1.print(); cout << endl;

	while (!d1.empty())
		d2.put(d1.get());

	// d2 is now d1 reversed; d1 is empty

	d2.print(); cout << endl;

	d2.shuffle();

	d2.print(); cout << endl;

	d2.shuffle();

	d2.print(); cout << endl;
}
