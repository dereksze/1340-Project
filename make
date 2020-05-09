TicTacToe.o:TicTacToe.cpp TicTacToe.h
	g++ -c TiacTacToe.cpp
Hangman.o:Hangman.cpp Hangman.h
	g++ -c Hangman.cpp
RockPaperScissors.o:RockPaperScissors.cpp RockPaperScissors.h
	g++ -c RockPaperScissors.cpp
main:TicTacToe.o Hangman.o RockPaperScissors.o main.cpp
	g++ -pedantic-errors -std=c++11 TicTacToe.o Hangman.o RockPaperScissors.o main.cpp -o main
