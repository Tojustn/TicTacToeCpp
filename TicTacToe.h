// Header File for TicTacToe class
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>
#include <vector>
#include<string>
using namespace std;

class TicTacToe {
    public:
        array<string, 9> board;
        string currentWinner;
        TicTacToe();
        void printBoard();
        static void printBoardIndex();
        vector<int> avaliableMoves();
        bool make_move(int square, string letter);
        bool winner(int square, string letter);
        void getSubArray(int start, int length, std::array<string, 3>& subArr);
        bool tie();
        bool emptySquares();
        vector<int> availableMoves();
};

#endif // TicTacToe_H