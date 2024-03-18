//
//  snake.cpp
//  C++
//
//  Created by qt on 2024/3/18.
//

#include "snake.hpp"

int Play() {
    gameT game;
    InitializeGame(game);
    RunSimulation(game);
    return 0;
}

void InitializeGame(gameT game) {
    ifstream input;
    while (true) {
        cout << "Enter filename: ";
        string fileName = GetLine();
        
        
    }
}

void RunSimulation(gameT game) {
    
}
