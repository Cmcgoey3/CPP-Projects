/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: JSON parsing function that takes in a string representation of the NHL stats
 * schedule API and returns a vector of game objects
 */

#include <string>
#include <vector>
#include <iostream>
#include "game.h"
#include "jsonParser.h"
#include "json.hpp"

using namespace std;

// Required to use the nlohmann json library
using json = nlohmann::json;

/**
 * Function Name: parseGames
 * Description: JSON parsing function that takes in a string representation of the NHL stats
 * schedule API and returns a vector of game objects
 * Parameter: string scheduleJSON - string representation of the NHL stats schedule API
 * Return: vector of game objects parsed from the JSON
*/
vector<game> parseGames(string scheduleJSON)
{
    // Initialize the vector of game objects
    vector<game> gameList;

    // Call the nlohmann json prse() function to parse the passed string
    json schedule = json::parse(scheduleJSON);

    // Houses a json object containing all games to be played on each date (in chronological order)
    json dates = schedule.at("dates");

    // Iterate over every date in the schedule
    for (int i = 0; i < dates.size(); i++)
    {
        // For each date, initialize the games to the json with id "games"
        json gamesArr = dates[i].at("games");

        // ITerate over each game
        for (int j = 0; j < gamesArr.size(); j++) 
        {
            // Initialize the current game and the 'status' of the game (played or to be played)
            json currentGame = gamesArr[j];
            string status = currentGame.at("status").at("abstractGameState");

            /**
             * Status == "Preview" means that the game has yet to be played. If this is the case, 
             * continue to the next iteration
             * */ 
            if (status == "Preview") 
            {
                continue;
            }

            // Initialize the home and away teams json information 
            json home = currentGame.at("teams").at("home");
            json away = currentGame.at("teams").at("away");

            // Access both teams' names and scores
            string homeName = home.at("team").at("name");
            string awayName = away.at("team").at("name");
            int homeScore = (int)home.at("score");
            int awayScore = (int)away.at("score");

            // Create a game object with the parsed information
            game newGame(homeName, homeScore, awayName, awayScore);

            // Push the game 
            gameList.push_back(newGame);
        }
    }

    // Return the final vector of game objects
    return gameList;
}

