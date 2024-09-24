/* Tic Tac Toe Project

Justin To

*/
#include <iostream>
#include <string>
#include <array>

using namespace std;
class TicTacToe{
    public:
        array<string,9> board;
        bool currentWinner;
        TicTacToe(){
            board = {" "," "," "," "," "," "," "," "," "};
            currentWinner = false;
        }
        // Prints Board
        void printBoard(){
            for(int i = 0; i<9;i+=3){
                cout << this->board[i] << " | " << this->board[i+1] << " | " << this->board[i+2]<<endl;
            }
            cout<<"\n";
        }
        // Print Board Indexed
        void static printBoardIndex(){
            for(int i = 0; i<9;i+=3){
                cout << i << " | " << i+1 << " | " << i+2<<endl;
            }
            cout<<"\n";
        }
};

int main(){
    TicTacToe tictactoe;

    tictactoe.printBoard();
    tictactoe.printBoardIndex();

    return 0;
}