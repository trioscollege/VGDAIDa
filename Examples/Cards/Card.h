#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;


class Card
{
	const char *suit;
	const char *face;

public:

	Card(const char *suit, const char *face)
	{
		this->suit = suit;
		this->face = face;
	}

	const char *getSuit() const
	{
		return suit;
	}

	const char *getFace() const
	{
		return face;
	}

	void print() const
	{
		cout << suit << face;
	}
};


#endif
