#ifndef TENNIS_H__
#define TENNIS_H__
#include <string>
#include <map>
class Game
{
	public:
		Game(void);
		std::string GetScore(void);
		void InitializeScore(int p1, int p2);
	private:
		int scoreP1 = 0;
		int scoreP2 = 0;
		std::map<int,std::string> dict = {{0, "Love"}, {1, "Fifteen"}, {2, "Thirty"}, {3, "Fourty"}};
};

#endif
