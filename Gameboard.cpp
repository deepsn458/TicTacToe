#include "Gameboard.h"
#include <string.h>

Gameboard::Gameboard(int size){
    move_counter = 0;
    next_player = 'X';
    board_size = size;

    //initialize the gameboard of the input size
    board = new char*[size];
    for (int i = 0; i < size; i++){
        board[i] = new char[size];
    }

    //creates default values for the board
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            board[i][j] = NULL_CHAR;
        }
    }
}

Gameboard::~Gameboard(){
    //deallocates the memory created for the board
    for (int i = 0; i < board_size; i++){
        delete board[i];
    }
    delete board;

}

void Gameboard::swapPlayers(){
    //if the move counter is even then it is the turn of 'X'
    (move_counter % 2 == 0) ? next_player = 'X': next_player = 'O';
    move_counter++;

}

bool Gameboard::checkMove(int row, int col){
    //the move is valid if the cell is empty (as indicated by the null char)
    if (board[row][col] == NULL_CHAR){
        board[row][col] = next_player;
        return true;
    }
    return false;
}

char Gameboard::checkWinner(int row, int col){
    char diag_winner = checkDiagWinner(row,col);
    char horiz_winner = checkHorizWinner(row,col);
    char vert_winner = checkVertWinner(row,col);
    if ((diag_winner== NULL_CHAR) && (horiz_winner == NULL_CHAR) && (vert_winner == NULL_CHAR)){
        return NULL_CHAR;
    }

    //returns the winner if there is one
    else if (diag_winner != NULL_CHAR){
        return diag_winner;
    }
    else if (vert_winner != NULL_CHAR){
        return vert_winner;
    }
    else{
        return horiz_winner;
    }
}
char Gameboard::checkHorizWinner(int row, int col){
    //checks the row
    char potential_winner = board[row][col];
    for (int i = 0; i < board_size;i++){
        if (board[row][i] != potential_winner){
            return NULL_CHAR;
        }
    }
    return potential_winner;
}

char Gameboard::checkVertWinner(int row, int col){
    //checks the row
    char potential_winner = board[row][col];
    for (int i = 0; i < board_size;i++){
        if (board[i][col] != potential_winner){
            return NULL_CHAR;
        }
    }
    return potential_winner;
}

char Gameboard::checkDiagWinner(int row, int col){
    char potential_winner = board[row][col];

    //Checks the diagonal from left to right
    for (int i = 0; i <= board_size; i++){
        //moves up the diagonal from the cell in consideration
        if ((row-i >= 0) && (col - i >= 0)){
            if (board[row-i][col-i] != potential_winner){
                return NULL_CHAR;
            }
        }

        //moves down the diagonal
        if ((row+i <= board_size) && (col+i <= board_size)){
            if (board[row+i][col+i] != potential_winner){
                return NULL_CHAR;
            }
        }

        //checks the diagonal from right to left
        //moves up the diagonal
        if ((row-i >= 0) && (col+i <= board_size)){
            if (board[row-i][col+i] != potential_winner){
                return NULL_CHAR;
            }
        }

        //moves down the diagonal
        if ((row+i <=board_size) && (col-i >= 0)){
            if  (board[row+i][col-i] != potential_winner){
                return NULL_CHAR;
            }
        }
    }

    return potential_winner;
}



