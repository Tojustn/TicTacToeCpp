#include <string>
#include <iostream>
#include <stdexcept>
#include "TicTacToe.h"
#include <cstdlib>
#include "Player.h" // Include the Player class header
#include "HumanPlayer.h" // Include the Player class header
#include "RandomComputerPlayer.h" // Include the Player class header
using namespace std;
// General Player


Player::Player(const string& letter) {
    this->letter = letter;
}


int RandomComputerPlayer::get_move(TicTacToe& tictactoe) {
    std::vector<int> moves = tictactoe.avaliableMoves(); // Correct the method name
    int randomIndex = rand() % moves.size();
    return moves[randomIndex];
}


// Reference player letter

int HumanPlayer::get_move(TicTacToe& tictactoe) {
    bool validSquare = false;
    int val = -1;

    while (!validSquare) {
        int square = -1;
        std::cout << this->letter << "'s turn. Input a move (0-8): ";
        std::cin >> square;

        try {
            val = square;
            bool isIn = false;

            for (int move : tictactoe.avaliableMoves()) { // Correct the method name
                if (val == move) {
                    isIn = true;
                    break;
                }
            }

            if (isIn) {
                std::cout << "Valid Move" << std::endl;
                return val;
            } else {
                throw std::invalid_argument("Invalid move. Please try again.");
            }
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
    return -1;
}