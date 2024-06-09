#include "Gameboard.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Gameboard::Gameboard(int size){
    move_counter = 0;
    next_player = 'X';
    board_size = size;
    winner = NULL_CHAR;

    //initialize the gameboard of the input size
    board = new int*[size];
    for (int i = 0; i < size; i++){
        board[i] = new int[size];
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
        delete[] board[i];
    }
    delete[] board;
}

void Gameboard::swapPlayers(){
    //if the move counter is even then it is the turn of 'X'
    (move_counter % 2 == 0) ? next_player = 'X': next_player = 'O';
}

bool Gameboard::checkMove(int row, int col){

    //checks if the coordinates are  out of bounds
    if ((row < 0) || (row >= board_size) || (col < 0) || (col >= board_size)){
        return false;
    }
    //the move is valid if the cell is empty (as indicated by the null char)
    if (board[row][col] == NULL_CHAR){
        board[row][col] = next_player;
        move_counter++;
        return true;
    }
    return false;
}

char Gameboard::getWinner(int row, int col){
    char diag_winner = getDiagWinner(row,col);
    char horiz_winner = getHorizWinner(row,col);
    char vert_winner = getVertWinner(row,col);
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
char Gameboard::getHorizWinner(int row, int col){
    //checks the row
    char potential_winner = board[row][col];
    for (int i = 0; i < board_size;i++){
        if (board[row][i] != potential_winner){
            return NULL_CHAR;
        }
    }
    return potential_winner;
}

char Gameboard::getVertWinner(int row, int col){
    //checks the row
    char potential_winner = board[row][col];
    for (int i = 0; i < board_size;i++){
        if (board[i][col] != potential_winner){
            return NULL_CHAR;
        }
    }
    return potential_winner;
}

char Gameboard::getDiagWinner(int row, int col){
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
        if ((row+i < board_size) && (col+i < board_size)){
            if (board[row+i][col+i] != potential_winner){
                return NULL_CHAR;
            }
        }

        //checks the diagonal from right to left
        //moves up the diagonal
        if ((row-i >= 0) && (col+i < board_size)){
            if (board[row-i][col+i] != potential_winner){
                return NULL_CHAR;
            }
        }

        //moves down the diagonal
        if ((row+i <board_size) && (col-i >= 0)){
            if  (board[row+i][col-i] != potential_winner){
                return NULL_CHAR;
            }
        }
    }

    return potential_winner;
}

void Gameboard::printBoard(){
    for (int i = 0; i < board_size; i++){
        for (int j = 0; j < board_size; j++){
            printf("|%c|", board[i][j]);
        }
        printf("\n");
    }
}
void Gameboard::playNextMove(int row, int col){
    //checks if the current move is valid
    if (checkMove(row,col)){

        //prints the resulting board:
        printf("move result: \n\n");
        printBoard();
        winner = getWinner(row,col);
        if (winner != NULL_CHAR){
            printf("Game winner: %c \n",winner);
        }
        else{
            printf("Move made by :%c, no winner yet \n", next_player);
        }
        swapPlayers();
    }

    else{
        printf("cell already occupied; choose another cell! \n");
    }
}

char Gameboard::getNextPlayer(){
    return next_player;
}

bool Gameboard::checkWinner(){
    return(!(winner == NULL_CHAR));
}
