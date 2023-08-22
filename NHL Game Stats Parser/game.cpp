/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: game class information and necessary getters and setters
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "game.h"

using namespace std;

/**
 * Function Name: game
 * Description: Empty constructor to initialize the object
 * Parameters: N/A
 * Return Description: N/A
*/
game::game() {}

/**
 * Function Name: game
 * Description: Constructor to take in and set the values for the team names and their scores
 * Parameters: string home name, int home score, string away name, int away score
 * Return Description: N/A
*/
game::game(string homeN, int homeS, string awayN, int awayS)
{
    homeName = homeN;
    awayName = awayN;

    homeScore = homeS;
    awayScore = awayS;
}

/**
 * Function Name: ~game
 * Description: Destructor for the game class
 * Parameters: N/A
 * Return Description: N/A
*/
game::~game() {}

/**
 * Function Name: setHomeName
 * Description: function to set the name for the home team 
 * Parameters: string name for the home team's name
 * Return Description: void, no return value
*/
void game::setHomeName(string name)
{
    homeName = name;
}

/**
 * Function Name: getHomeName
 * Description: get and return the name of the home team
 * Parameters: N/A
 * Return Description: the home team's name
*/
string game::getHomeName()
{
    return game::homeName;
}

/**
 * Function Name: setAwayName
 * Description: function to set the name for the away team 
 * Parameters: string name for the away team's name
 * Return Description: void, no return value
*/
void game::setAwayName(string name)
{
    awayName = name;
}

/**
 * Function Name: getAwayName
 * Description: get and return the name of the away team
 * Parameters: N/A
 * Return Description: the away team's name
*/
string game::getAwayName()
{
    return awayName;
}

/**
 * Function Name: setHomeScore
 * Description: set the score of the Home team
 * Parameters: int score of the Home team
 * Return Description: void, no return value
*/
void game::setHomeScore(int score)
{
    homeScore = score;
}

/**
 * Function Name: getHomeScore
 * Description: get and return the score of the Home team
 * Parameters: N/A
 * Return Description: the Home team's score
*/
int game::getHomeScore()
{
    return homeScore;
}

/**
 * Function Name: setAwayScore
 * Description: set the score of the Away team
 * Parameters: int score of the Away team
 * Return Description: void, no return value
*/
void game::setAwayScore(int score)
{
    awayScore = score;
}

/**
 * Function Name: getAwayScore
 * Description: get and return the score of the Away team
 * Parameters: N/A
 * Return Description: the Away team's score
*/
int game::getAwayScore()
{
    return awayScore;
}
