#include "Player.h"
#include "../ADT/SortedList.h"

#include <iostream>
using namespace std;


void listPlayers(SList<Player*>& master)
{
	SortedList<Player*,PlayerNameCompare> sorted;

	SList<Player*>::Iterator p = master.begin();
	for ( ; p != master.end(); ++p)
		sorted.insert(*p);

	SortedList<Player*,PlayerNameCompare>::Iterator sp = sorted.begin();
	for ( ; sp != sorted.end(); ++sp)
		cout << (*sp)->name << "\t" << (*sp)->score << endl;
	cout << endl;
}


void listHighScores(SList<Player*>& master)
{
	SortedList<Player*,PlayerScoreCompare> sorted;

	SList<Player*>::Iterator p = master.begin();
	for ( ; p != master.end(); ++p)
		sorted.insert(*p);

	SortedList<Player*,PlayerScoreCompare>::Iterator sp = sorted.begin();
	for ( ; sp != sorted.end(); ++sp)
		cout << (*sp)->name << "\t" << (*sp)->score << endl;
	cout << endl;
}
