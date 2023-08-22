/**
 * Author: Connor McGoey
 * Date: February 6, 2023
 * Description: Header file for the jsonParser.cpp file and functions
 */

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>
#include <vector>
#include "game.h"

std::vector<game> parseGames(std::string schedule);

#endif
