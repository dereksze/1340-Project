#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <string> // length
#include "Hangman.h"
using namespace std;

void RPSprintheading(){ // print the game rules
  cout << R"RAW(
*************************************************
********************* HANGMAN *******************
*************************************************

GAME RULES                                                  ___________________________
1. The computer will randomly select a word from     |     |          HANGMAN          |
   the word list                                     |     |___________________________|
2. The total no. of underlines shows the length      |     |    --XXX--                |
   of the whole word                                 |     |       :         OH NO !!! |
3. The player has to guess the full word to win      |     |       :                   |
4. If the player guesses an alphabet which is not    |     |       O        \ O    O   |
   in the word, a body part will be added to the     |     |      /|\        |\   /|7  |
   gallow                                            |     |      / \       / \   / \  |
5. The player has 6 lives to solve the word, else    |     |___________________________|
   you lose the game                                 |

)RAW";
}

void printhangman(int &error){ // print the hangman for every mistake player has made
  if(error==0){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |                \ O    O   |
    |                 |\   /|7  |
    |                / \   / \  |
    |___________________________|
       You have 6 lives left!

)RAW";
  }
  else if(error==1){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |       0        \ O    O   |
    |                 |\   /|7  |
    |                / \   / \  |
    |___________________________|
       You have 5 lives left!

)RAW";
  }
  else if(error==2){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |       0        \ O    O   |
    |       |         |\   /|7  |
    |                / \   / \  |
    |___________________________|
       You have 4 lives left!

)RAW";
  }
  else if(error==3){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |       0        \ O    O   |
    |      /|         |\   /|7  |
    |                / \   / \  |
    |___________________________|
       You have 3 lives left!

)RAW";
  }
  else if(error==4){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |       0        \ O    O   |
    |      /|\        |\   /|7  |
    |                / \   / \  |
    |___________________________|
       You have 2 lives left!

)RAW";
  }
  else if(error==5){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :                   |
    |       :                   |
    |       0        \ O    O   |
    |      /|\        |\   /|7  |
    |      /         / \   / \  |
    |___________________________|
        You have 1 life left!

)RAW";
  }
  else if(error==6){
    cout << R"RAW(     ___________________________
    |          HANGMAN          |
    |___________________________|
    |    --XXX--                |
    |       :         OH NO !!! |
    |       :                   |
    |       0        \ O    O   |
    |      /|\        |\   /|7  |
    |      / \       / \   / \  |
    |___________________________|
            GAME OVER!!!

)RAW";
  }

}

bool Hangmangamedetails(string word, bool &hangmanwin, int &error){ // the basic setting of the game
  int display=0;
  string show=word;
  for(int i=0; i<show.length(); i++){
    show[i]='#';
  }

  while(display<word.length()){
    char inputhangman;
    cout << "Please enter a letter one by one. Or else you will receive great penalty!" << endl;
    cout << "Enter a letter from the word " << show << " : ";
    cin >> inputhangman;

    bool repeated=false;
    bool correct=false;
    for(int i=0; i<word.length(); i++){
      if(inputhangman==word[i]){
        if(show[i]==word[i]){
          cout << "You have chosed " << inputhangman << " before! Choose another letter!" << endl;
          repeated=true;
          break ;
        }
        else{
          show[i]=word[i];
          display++;
          correct=true;
        }
      }
    }

    if(repeated){
      continue;
    }

    if(!correct){
      cout << inputhangman << " is not a correct letter in the word!" << endl;
      error++;
    }

    printhangman(error);

    if(error==6){
      break;
    }
  }

  if(error==6){
    cout << "The final word is: " << word << endl;
    cout << "Game over, you have lost this mini game!" << endl;
    hangmanwin=0;
    return 0;
  }
  else{
    cout << "The final word is: " << word << endl;
    cout << "Congratulations!!! You have won this mini game!" << endl;
    hangmanwin=1;
    return 1;
  }

}

bool Hangman(){
  int error=0;
  bool hangmanwin=0;
  srand(time(NULL));
  string wordlist[]={"advanced", "lotus", "dazzling", "improper", "workload", "benefits", "comment", "animal", "enemy", "soldier" ,"innovation", "proposal", "windows", "brainstorm", "destruction", "immediately","player","programming", "difficult", "jazz", "easy", "dizzy", "apple", "banana", "generate", "constraints", "ability", "project", "impossible", "random", "picture", "joker", "puzzle", "board", "swimming", "running", "soccer", "technology", "computer", "strawberry", "watermelon", "science", "cartoon", "helicopter", "halloween", "basketball", "engineering", "arrangements", "leftover", "industry"};
  int choice=rand()%50;
  string final=wordlist[choice];

  RPSprintheading();
  Hangmangamedetails(final, hangmanwin, error);

  return hangmanwin;
}
