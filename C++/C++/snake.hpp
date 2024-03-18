//
//  snake.hpp
//  C++
//
//  Created by qt on 2024/3/18.
//

#ifndef snake_hpp
#define snake_hpp

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "chapter1-3.hpp"
using namespace std;

/* Number of food pellets that must be eaten to win*/
const int kMaxFood = 20;

/* Constants for different tile types */
const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';

struct pointT {
    int row, col;
};

struct gameT {
    vector<string> world;
    int numRows, numCols;
    
    deque<pointT> snake;
    int dx, dy; // The snake direction
    
    int numEaten; // How much food snake has eaten
};

int Play();
void InitializeGame(gameT game);
void RunSimulation(gameT game);
string GetLine();

#endif /* snake_hpp */
