#include "Gameboard.h"
#include <iostream>

using namespace std;

int main(){
    int board_size;
    int row;
    int col;

    cout << "Welcome to TicTacToe. Enter the board size: ";
    cin >> board_size;
    while (board_size < 3){
        cout << "minimum board size is 3, try again: ";
        cin >> board_size;
    }

    //creates the game board
    Gameboard gameboard = Gameboard(board_size);

    //plays the game until there is a winner
    while (!(gameboard.checkWinner())){
        cout << gameboard.getNextPlayer()<<"'s turn  \n";
        cout << "enter a row: ";
        cin >> row;
        cout << "enter a column: \n";
        cin >> col;

        gameboard.playNextMove(row,col);
    }

    return 0;
}