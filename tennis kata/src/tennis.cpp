#include "tennis.h"
using namespace std;
Game::Game()
{
	scoreP1 = 0;
	scoreP2 = 0;
}

string Game::GetScore()
{
	if (scoreP1 >= 3 && scoreP2 >= 3) {
		if (scoreP1 == scoreP2)
			return "Deuce";
		if (scoreP1 > scoreP2)
			return "Advantage Player 1";
		if (scoreP2 > scoreP1)
			return "Advantage Player 2";
	}
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
