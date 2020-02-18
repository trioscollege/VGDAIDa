#include <iostream>
#include <string>

using namespace std;

#include "BST.h"


struct Player
{
	string name;
	int ranking;
};


void printPlayer(Player& p)
{
	cout << p.name << ": " << p.ranking << endl;
}


int main(int args, char **argc)
{
	Player players[] = {
		{ "Jim", 23 },
		{ "Sally", 75 },
		{ "Bob", 53 },
		{ "Bubba", 18 },
		{ "Alice", 95 },
		{ "George", 98 },
		{ "Lucy", 33 },
		{ "Walter", 66 },
		{ "Abe", 65 },
		{ "Joe", 67 }
	};
	int n = sizeof(players) / sizeof(players[0]);
	int i;


	cout << "Sorting players by name:" << endl;

	BinaryTree<string,Player> tree1;

	for (i=0; i<n; i++)
		tree1.insert(players[i].name, players[i]);

	tree1.traverse(printPlayer);

	cout << endl;
	cout << "Sorting players by ranking:" << endl;

	BinaryTree<int,Player> tree2;

	for (i=0; i<n; i++)
		tree2.insert(players[i].ranking, players[i]);

	tree2.traverse(printPlayer);

	return 0;
}
