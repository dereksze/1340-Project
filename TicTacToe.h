#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include "TicTacToe.cpp"

void printboard(char board[]);
void playerinput(int &count, char board[]);
void npcinput(int &count, char board[]);
char checkwin(char board[]);
int gameend(bool &win, int &count, char board[]);
bool TicTacToe();

#endif
