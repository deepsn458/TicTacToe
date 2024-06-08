#ifndef Gameboard_H
#define Gameboard_H


class Gameboard{
    const char NULL_CHAR = '-';
    char** board;
    int board_size;
    int move_counter;
    char winner;
    char next_player;
    void swapPlayers();
    bool checkMove(int row, int col);
    char checkWinner(int row, int col);
    char checkHorizWinner(int row, int col);
    char checkVertWinner(int row, int col);
    char checkDiagWinner(int row, int col);
    public:
        Gameboard(int size);
        ~Gameboard();
        void playNextMove(int row, int col);
};
#endif