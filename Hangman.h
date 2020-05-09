#ifndef HANGMAN_H_
#define HANGMAN_H_
#include "Hangman.cpp"

void RPSprintheading();
void printhangman(int &error);
bool Hangmangamedetails(std::string word, bool &hangmanwin, int &error);
bool Hangman();

#endif
