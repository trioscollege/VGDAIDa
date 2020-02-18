#ifndef PLAYER_H
#define PLAYER_H

#include <string>


struct Player
{
	std::string name;
	int score;

	Player(const std::string& name, int score) : name(name), score(score) { }
};


struct PlayerNameCompare
{
	// compare players by value
	int operator() (const Player& a, const Player& b)
	{
		if (a.name < b.name)
			return -1;
		else if (a.name > b.name)
			return 1;
		else
			return 0;
	}

	// compare players by pointer
	int operator() (const Player* a, const Player* b)
	{
		if (a->name < b->name)
			return -1;
		else if (a->name > b->name)
			return 1;
		else
			return 0;
	}
};


struct PlayerScoreCompare
{
	// compare players by value
	int operator() (const Player& a, const Player& b)
	{
		// high scores first!
		if (a.score > b.score)
			return -1;
		else if (a.score < b.score)
			return 1;
		else
			return 0;
	}

	// compare players by pointer
	int operator() (const Player *a, const Player *b)
	{
		// high scores first!
		if (a->score > b->score)
			return -1;
		else if (a->score < b->score)
			return 1;
		else
			return 0;
	}
};


void listPlayers(SList<Player*>& master);
void listHighScores(SList<Player*>& master);


#endif
