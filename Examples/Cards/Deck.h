#include <vector>
#include <cstdlib>     // rand()
#include <iostream>    // cout
using namespace std;

#include "Card.h"


class Deck
{
	static const char *suits[4];
	static const char *faces[13];

	vector<Card> cards;

public:

	Deck(bool full=true)
	{
		if (full)
		{
			cards.reserve(52);
			for (int s=0; s<4; ++s)
				for (int f=0; f<13; ++f)
					cards.push_back(Card(suits[s], faces[f]));
		}
	}

	void put(const Card& card)
	{
		cards.push_back(card);
	}

	Card get()
	{
		Card card = cards.back();
		cards.pop_back();
		return card;
	}

	bool empty() const
	{
		return cards.empty();
	}

	void shuffle()
	{
		for (size_t i=0; i<cards.size(); ++i) {
			size_t j = rand() % cards.size();
			// swap cards at i and j
			Card tmp = cards[i];
			cards[i] = cards[j];
			cards[j] = tmp;
		}
	}

	void print() const
	{
		for (size_t i=0; i<cards.size(); ++i) {
			cards[i].print();
			cout << " ";
		}
		cout << endl;
	}
};
