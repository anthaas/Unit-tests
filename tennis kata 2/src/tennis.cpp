#include "tennis.h"
using namespace std;
string ScoreBoard::GetScore(int scorePlayer1, int scorePlayer2)
{
	return textrepre[scorePlayer1] + ":" + textrepre[scorePlayer2];

}
