# Unit-tests: Tennis kata

## Problem Description
Implemetate a simple tennis game. Each set is one game. Score points are called "Love" for 0, "Fifteen" for 1, "Thirty" for 2, "Fourty" for 3. <br /><br />
The scoring system is rather simple: <br />
1. Item A game is won by the first player to have won at least four points in total and at least two points more than opponent. <br />
2. Item The running score of each game is described in a manner peculiar to tennis: scores from zero to three points are described as "Love", "Fifteen", "Thirty", and "Fourty" respectively. <br />
3. Item If at least three points have been scored by each player, and the scores are equal, the score is "Deuce" <br />
4. Item If at least three points have been scored by each side and a player has more point than his opponent, the score of the game is "Advantage" for the player in the lead. <br />

<br />
Write program, that will print out score. Imagine, that your only input is a guy with two buttons in front of him with labels "Player 1 scored" and "Player 2 scored" when player wins the ball.

######Sample output:
"Fifteen-Thirty" for score "1:2" <br />
"Deuce" for score "3:3" <br />
"Advantage Player 2" for score "4:5" <br />
"Player 1 wins" for score "7:5" <br />
"Love-Love" for score "0:0"

#### Stage 2 - new requirement
Add names for players and use them, so output will be like "Advantage Federer", "Djokovic wins".

