#include "tennis.h"
using namespace std;
Game::Game() { }

string Game::GetScore()
{
	if (scoreP1 == scoreP2 && scoreP1 >= 3)
		return "Deuce";
	string strP1, strP2;
	for (auto entry : dict) {
		if (scoreP1 == entry.first)
			strP1 = entry.second;
		if (scoreP2 == entry.first)
			strP2 = entry.second;
	}
	return strP1 + "-" + strP2;
}

void Game::InitializeScore(int p1, int p2)
{
	scoreP1 = p1;
	scoreP2 = p2;
}
