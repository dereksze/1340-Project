#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <string> // size
#include "RockPaperScissors.h"
using namespace std;

int playernum=0;

void RPSprintrules(){ // print the game rules
  cout << " " << endl
       << "*************************************************" << "    |  " << "###############################################################" << endl
       << "************** ROCK PAPER SCISSORS **************" <<  "    |  " << "##  _______ " << " __    __ " << "______ " << " _______ " << "_______ " << "               ##" << endl
       << "*************************************************" << "    |  " << "## /   ____|" << "|  |  |  |" << "  __  \\" << "|   ____|" << "   __  \\" << "               ##" << endl
       << "                                                 " << "    |  " << "## \\____   \\" << "|  |  |  |" << " /__\\  |" << "  |____  " << " /__\\  |" << "              ##" << endl
       << "GAME RULES" << "                                       " << "    |  " << "##  ____|   |" << "  |__|  |" << "   __ /" << "|  |____" << "        /" << "               ##" << endl
       << "1. Player needs to enter a char R, P, S to choose" << "    |  " << "## |_______/" << "\\________/" << "__|_ __" << "|_______|" << "__|\\ __\\____   ___" << "     ##" << endl
       << "   Rock, Paper or Scissors" << "                           |  " << "##               |  \\  /  |" << "   ____|" << "  |" << "    |__   __|" << " / _ \\ " << "   ##" << endl
       << "2. R represents Rock" << "                                 |  " << "##               |        |" << "  |____" << "   |" << "       | |" << "   / /_\\ \\ " << "  ##" << endl
       << "   P represents Paper" << "                                |  " << "##               |  |\\/|  |" << "  |____" << "   |____" << " __| |__" << "/  ___  \\" << "  ##" << endl
       << "   S represents Scissors" << "                             |  " << "##               |__|  |__|" << "_______|" << "_______|" << "______" << "/__/   \\__\\" << " ##" << endl
       << "3. Rock wins against Scissors" << "                        |  " << "##                                                           ##" << endl
       << "   Scissors win against paper" << "                        |  " << "###############################################################" << endl
       << "   Paper wins against Rock" << "                           |  " << endl
       << "4. The 1st person to win 3 rounds wins the game" << "      |  " << endl << endl;
}

int RPSplayer(){ // player input
  bool valid=false;
  string temp;
  char playermove;
  cout << "R for Rock; P for Paper; S for Scissors" << endl;
  while(valid==false){
    cout << "Player 1, please choose R, P or S: ";
    cin >> temp;

    if(temp.size()==1){
      playermove=temp[0];
      if(playermove=='R'){
        cout << "You picked Rock!" << endl;
        playernum=1;
        valid==true;
        break;
      }
      else if(playermove=='P'){
        cout << "You picked Paper!" << endl;
        playernum=2;
        valid==true;
        break;
      }
      else if(playermove=='S'){
        cout << "You picked Scissors!" << endl;
        playernum=3;
        valid==true;
        break;
      }
      else
        cout << "Invalid move, please choose again!" << endl;
    }
    else
      cout << "Invalid move, please choose again!" << endl;
  }

  return playernum;
}

bool RockPaperScissors(){
  bool end=false;
  int playerwin=0, npcwin=0;
  srand(time(NULL));
  while(end==false){
    RPSprintrules();
    RPSplayer();

    int npcmove=1+rand()%3; // generate npc input
    if(npcmove==1)
        cout << "NPC picked Rock!" << endl;
    else if(npcmove==2)
        cout << "NPC picked Paper!" << endl;
    else if(npcmove==3)
        cout << "NPC picked Scissors!" << endl;

    if(npcmove==playernum) // Check winner of this round
      cout << "It is a draw!" << endl << endl;
    else if(npcmove==1 && playernum==2){
      cout << "You win this round!" << endl << endl;
      playerwin++;
    }
    else if(npcmove==2 && playernum==3){
      cout << "You win this round!" << endl << endl;
      playerwin++;
    }
    else if(npcmove==3 && playernum==1){
      cout << "You win this round!" << endl << endl;
      playerwin++;
    }
    else{
      cout << "Computer win this round. Don't give up!" << endl << endl;
      npcwin++;
    }

    if(playerwin==3){
      cout << "*************************************************" << endl;
      cout << "             The winner is: Player               " << endl;
      cout << "                 Congratulations!                " << endl;
      cout << "*************************************************" << endl;
      end=true;
      return 1;
    }
    else if(npcwin==3){
      cout << "*************************************************" << endl;
      cout << "             The winner is: Computer             " << endl;
      cout << "                    Game Over!                   " << endl;
      cout << "*************************************************" << endl;
      end=true;
      return 0;
    }
  }
  return 0;
}
