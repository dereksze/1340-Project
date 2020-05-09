#include <iostream>
#include <cstdlib> // rand, srand
#include <time.h> // time
#include <string> // at
#include <cctype> // isdigit
#include "TicTacToe.h"
using namespace std;

void printboard(char board[]){ // Print the tictactoe board and the game rules
  cout << " " << endl
       << "*************************************************" << endl
       << "****************** TIC TAC TOE ******************" << endl
       << "*************************************************" << endl << endl

       << "GAME RULES" << endl
       << "1. Player needs to enter a number (1-9) to choose" << endl
       << "   a square" << endl
       << "2. The first player who gets 3 same symbols in a " << endl
       << "   row is the winner" << endl
       << "3. If all the squares are full, the game ends." << endl
       << "4. If no player gets 3 symbols in a row, the game" << endl
       << "   ends with a tie" << endl << endl

       << "----- Player 1  [X] --------- Player 2  [O] -----" << endl

       << "       ___________ ___________ ___________      " << endl
       << "      |           |           |           |     " << endl
       << "      |     " << board[0] << "     |     " << board[1] << "     |     " << board[2] << "     |" << endl
       << "      |___________|___________|___________|     " << endl
       << "      |           |           |           |     " << endl
       << "      |     " << board[3] << "     |     " << board[4] << "     |     " << board[5] << "     |" << endl
       << "      |___________|___________|___________|     " << endl
       << "      |           |           |           |     " << endl
       << "      |     " << board[6] << "     |     " << board[7] << "     |     " << board[8] << "     |" << endl
       << "      |___________|___________|___________|     " << endl << endl;
}

void playerinput(int &count, char board[]){ // Let the player input and change the board
  char choice;
  string temp;
  bool valid=false;
  int find;

  while(valid==false){
    cout << "Player 1, your turn" << endl;
    cout << "Enter the box (1-9): ";
    cin >> temp;
    cout << endl;

    if(isdigit(temp[0])){
      find=temp[0]-'1';
    }

    if(temp.size()!=1 || !isdigit(temp[0]) || board[find]=='X' || board[find]=='O' || find==-1){ // Check for invalid moves
      cout << "Invalid move. Please enter again." << endl << endl;
      valid = false;
    }
    else{
      choice=temp.at(0);
    }

    if((choice == '1') && (board[0]== '1')){
      board[0]='X';
      count++;
      valid=true;
    }
    else if((choice == '2') && (board[1]== '2')){
      board[1]='X';
      count++;
      valid=true;
    }
    else if((choice == '3') && (board[2]== '3')){
      board[2]='X';
      count++;
      valid=true;
    }
    else if((choice == '4') && (board[3]== '4')){
      board[3]='X';
      count++;
      valid=true;
    }
    else if((choice == '5') && (board[4]== '5')){
      board[4]='X';
      count++;
      valid=true;
    }
    else if((choice == '6') && (board[5]== '6')){
      board[5]='X';
      count++;
      valid=true;
    }
    else if((choice == '7') && (board[6]== '7')){
      board[6]='X';
      count++;
      valid=true;
    }
    else if((choice == '8') && (board[7]== '8')){
      board[7]='X';
      count++;
      valid=true;
    }
    else if((choice == '9') && (board[8]== '9')){
      board[8]='X';
      count++;
      valid=true;
    }
    else
      valid==false;
  }
}

void npcinput(int &count, char board[]){ // Let the npc input and change the board
  cout << "Player 2 is thinking......" << endl << endl;
  int add=0;
  srand(time(NULL));
  for(int i=0; i<9; i++){
    if(board[i]!='X' && board[i]!='O')
      add++;
  }

  char *seed=new char [add];
  int a=0;
  for(int i=0; i<9; i++){
    if(board[i]!='X' && board[i]!='O'){
      *(seed+a)=board[i];
      a++;
    }
  }

  int l, y=rand()%add;
  switch(seed[y]){
    case '1':
      l=0; break;
    case '2':
      l=1; break;
    case '3':
      l=2; break;
    case '4':
      l=3; break;
    case '5':
      l=4; break;
    case'6':
      l=5; break;
    case'7' :
      l=6; break;
    case'8':
      l=7; break;
    case'9':
      l=8; break;
  }

  cout << "Player 2 has chosen: " << board[l] << endl << endl;
  board[l]='O';
  delete[]seed;
  seed=0;
  count++;
}

char checkwin(char board[]){ // Check for the winner
  if(board[0]==board[1] && board[1]==board[2]){
    return board[0];
  }
  else if(board[3]==board[4] && board[4]==board[5]){
    return board[3];
  }
  else if(board[6]==board[7] && board[7]==board[8]){
    return board[6];
  }
  else if(board[0]==board[3] && board[3]==board[6]){
    return board[0];
  }
  else if(board[1]==board[4] && board[4]==board[7]){
    return board[1];
  }
  else if(board[2]==board[5] && board[5]==board[8]){
    return board[2];
  }
  else if(board[0]==board[4] && board[4]==board[8]){
    return board[0];
  }
  else if(board[2]==board[4] && board[4]==board[6]){
    return board[2];
  }
  return 0;
}

int gameend(bool &win, int &count, char board[]){ // Check if the game is over or not
  if((checkwin(board)!=0) && (checkwin(board)=='X')){
    cout << "*************************************************" << endl;
    cout << "             The winner is: Player 1             " << endl;
    cout << "                 Congratulations!                " << endl;
    cout << "*************************************************" << endl;
    win=1;
    return 1;
  }
  else if((checkwin(board)!=0) && (checkwin(board)=='O')){
    cout << "*************************************************" << endl;
    cout << "             The winner is: Computer             " << endl;
    cout << "                    Game Over!                   " << endl;
    cout << "*************************************************" << endl;
    win=0;
    return 1;
  }
  else if(count==9){
    cout << "*************************************************" << endl;
    cout << "                The game is a tie.               " << endl;
    cout << "*************************************************" << endl;
    win=0;
    return 1;
  }
  return 0;
}

bool TicTacToe(){
  char board[]={'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  bool win=1;
  int count=0;
  while(gameend(win, count, board)==0){
    printboard(board);
    if((count==0) || (count==2) || (count==4) || (count==6) || (count==8))
      playerinput(count, board);
    else if((count==1) || (count==3) || (count==5) || (count==7) || (count==9))
      npcinput(count, board);
  }

  return win;
}
