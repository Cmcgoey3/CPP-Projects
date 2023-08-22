/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: header file for the game class
 */

#ifndef GAME_H
#define GAME_H

#include <string>

/**
 * Header file information for the game class
*/
class game
{
// Private values for their names and scores
private:
    std::string homeName;
    std::string awayName;

    int homeScore;
    int awayScore;

// All prototypes for the functions described in game.cpp
public:
    game();

    game(std::string homeN, int homeS, std::string awayN, int awayS);

    ~game();

    void setHomeName(std::string name);

    std::string getHomeName();

    void setAwayName(std::string name);

    std::string getAwayName();

    void setHomeScore(int score);

    int getHomeScore();

    void setAwayScore(int score);

    int getAwayScore();
};

#endif
