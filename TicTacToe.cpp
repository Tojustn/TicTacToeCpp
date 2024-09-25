/* Tic Tac Toe Project

Justin To

*/
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <windows.h>
#include "TicTacToe.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomComputerPlayer.h"
using namespace std;


TicTacToe::TicTacToe() {
    board.fill(" "); // Initialize the board with empty strings
    currentWinner;
}

    // Method to get a subarray of the board
void TicTacToe::getSubArray(int start, int length, std::array<string, 3>& subArr) {
    for (int i = 0; i < length; ++i) {
        subArr[i] = board[start + i];
    }
}

    // Prints the Board
void TicTacToe::printBoard() {
    for (int i = 0; i < 9; i += 3) {
        cout << this->board[i] << " | " << this->board[i + 1] << " | " << this->board[i + 2] << endl;
    }
    cout << "\n";
}

    // Print Board Indexed
void TicTacToe::printBoardIndex() {
    for (int i = 0; i < 9; i += 3) {
        cout << i << " | " << i + 1 << " | " << i + 2 << endl;
    }
    cout << "\n";
}

    // Return available moves as a vector of indices
vector<int> TicTacToe::avaliableMoves() {
    vector<int> moves;
    for (int i = 0; i < 9; ++i) {
        if (this->board[i] == " ") {
            moves.push_back(i); // Store the index of available moves
        }
    }
    return moves;
}
bool TicTacToe::make_move(int square, string letter){
    if (this->board[square] == " "){
        board[square] = letter;
        if (winner(square, letter)){
            this-> currentWinner = letter;
        }
        return true;
    }
    else{
         return false;
    }
}
bool TicTacToe::tie(){
    for (string value: board){
        if (value == " "){
            return false;
        }
    }
    return true;
}
bool TicTacToe::emptySquares(){
    for(string value: this->board){
        if (value == " "){
            return true;
        }
    }
    return false;
}
// Check for a winner
bool TicTacToe::winner(int square, string letter) {
    // Check for row wins
    int rowIndex = square / 3;
    array<string, 3> row;
    getSubArray(rowIndex * 3, 3, row);

    if (row[0] == letter && row[1] == letter && row[2] == letter) {
        return true; // Row win
    }

    // Check for column wins
    int colIndex = square % 3;
    array<string, 3> col = {board[colIndex], board[colIndex + 3], board[colIndex + 6]};
    if (col[0] == letter && col[1] == letter && col[2] == letter) {
        return true; // Column win
    }

    // Check for diagonal wins
    if (square % 2 == 0) { // Only check diagonals if square is even
         if (square == 0) {
            if (board[0] == letter && board[4] == letter && board[8] == letter) {
                return true; // Diagonal win from top-left to bottom-right
            }
        } 
        else if (square == 2) {
            if (board[2] == letter && board[4] == letter && board[6] == letter) {
                return true; // Diagonal win from top-right to bottom-left
            }
        }
    }
        
    return false; // No win found
}

string play(TicTacToe& game, Player& x_player, Player& o_player, bool print_game = true){
    if (print_game){
        game.printBoardIndex();
        Sleep(800);
    }
    string letter = "X";
    int square = -1;
    // while the game has empty squares
    while(game.emptySquares()){
        if (letter == "O"){
            square = o_player.get_move(game);
        }
        else{
            square = x_player.get_move(game);
        }

        if (game.make_move(square,letter)){
            if(print_game){
                cout << letter << " makes a move to square " << square << endl;
                game.printBoard();

                if(game.currentWinner == "X" || game.currentWinner == "Y"){
                    cout << letter << " is SUPERIOR!";
                    return letter;
                }
                if (letter == "X"){
                    letter = "O";
                }
                else{
                    letter = "X";
                }
                Sleep(800);
            }
        }
        if(game.tie()){
            cout <<"TIE GAME";
        }
    }
    return "";
}
int main() {
    TicTacToe game;
    HumanPlayer Justin("X");
    RandomComputerPlayer o_player("O");
    play(game, Justin, o_player);
    // Sample usage (add a player move, etc.)
    // game.board[0] = "X";
    // if (game.winner(0, "X")) {
    //     cout << "Player X wins!" << endl;
    // }

    return 0;
}
