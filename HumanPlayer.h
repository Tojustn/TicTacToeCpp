#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <string>
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& letter) : Player(letter) {}
    int get_move(TicTacToe& game) override; // Override the get_move method
};

#endif // HUMANPLAYER_H
