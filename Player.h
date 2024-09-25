#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "TicTacToe.h"

class Player {
public:
    std::string letter;
    Player(const std::string& letter); // Constructor
    virtual ~Player() {} // Virtual destructor
    virtual int get_move(TicTacToe& tictactoe) = 0; // Pure virtual function
};

#endif // PLAYER_H
