#ifndef Gameboard_H
#define Gameboard_H


class Gameboard{
    const char NULL_CHAR = '-';
    int** board;
    int board_size;
    int move_counter;
    char winner;
    char next_player;
    void swapPlayers();
    bool checkMove(int row, int col);
    char getWinner(int row, int col);
    char getHorizWinner(int row, int col);
    char getVertWinner(int row, int col);
    char getDiagWinner(int row, int col);
    void printBoard();
    public:
        Gameboard(int size);
        ~Gameboard();
        void playNextMove(int row, int col);
        char getNextPlayer();
        bool checkWinner();
};
#endif