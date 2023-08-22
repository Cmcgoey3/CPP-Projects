/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * 
 * Main program driver to make a request object with the schedule API, execute that request,
 * and then send the data to the parser in jsonParser.cpp. Then prints off all of the results
 * with the format:
 *                  home vs. away: home score - away score
*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <curl/curl.h>
#include "jsonParser.h"
#include "request.h"
#include "game.h"

using namespace std;

/**
 * Main function to drive the program
 * Description: invoke functiont to call on the NHL stats api and then print out the result
 * Return: integer to denote success/failure
*/
int main()
{
    // Create request object with the 2022/23 regular season and then execute it
    request scheduleRequest("https://statsapi.web.nhl.com/api/v1/schedule?season=20222023&gameType=R&expand=schedule.linescore");
    scheduleRequest.execute();

    // Vector of game objects returned from the parseGames function in jsonParser.cpp
    vector<game> games = parseGames(scheduleRequest.result());

    // Iterate over every game and then print the result
    for (int i = 0; i < games.size(); i++)
    {
        // The current game in the games vector
        game currentGame = games[i];
        cout << currentGame.getHomeName() << " vs. ";
        cout << currentGame.getAwayName() << ": ";
        cout << currentGame.getHomeScore() << " - ";
        cout << currentGame.getAwayScore() << endl;
    }
    return 0;
}

