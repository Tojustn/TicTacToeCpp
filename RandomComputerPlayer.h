#ifndef RANDOMCOMPUTERPLAYER_H
#define RANDOMCOMPUTERPLAYER_H

#include <string>
#include "Player.h"

class RandomComputerPlayer : public Player {
public:
    RandomComputerPlayer(const std::string& letter) : Player(letter) {}
    int get_move(TicTacToe& game) override; // Override the get_move method
};

#endif // RANDOMCOMPUTERPLAYER_H
