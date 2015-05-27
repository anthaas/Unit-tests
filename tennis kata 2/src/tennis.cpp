#include "tennis.h"
using namespace std;
string ScoreBoard::GetScore(int scorePlayer1, int scorePlayer2)
{
	if (scorePlayer2 >= 3 && scorePlayer1 == scorePlayer2)
		return "Deuce";
	return textrepre[scorePlayer1] + ":" + textrepre[scorePlayer2];

}
