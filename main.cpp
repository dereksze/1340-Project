#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <list>
#include <vector>
#include "RockPaperScissors.h"
#include "TicTacToe.h"
#include "Hangman.h"
using namespace std;
struct status
{
    int posx;
    int posy;
    int lives;
    list<char>spell;
    int numofspell;
    string name;
    bool real;
    bool cont;
    int prevx;
    int prevy;
    int rank;

};//-----------------------------------player data

// The game ends when 1 player finds the 'Win' exitgate
// The computer randomly generates 1 set of gate according to the number of players
// 2 players: Choose between 0-3     3 players: Choose between 0-5     4 players: Choose between 0-7

void choosegate(status player[], int i, char map[20][20], int available[169][2], int mode, int &countrank, vector<int> &final, int findingate){ // 1: Win, 2: Return to the starting point , 3: Transferred to a random position, 4: Return to the starting point
  if(findingate==1){ // Win and end game
    cout << "You have won the game! Congratulations!" << endl;
    player[i].rank=countrank;
    countrank++;
    player[i].cont=0;
  }
  else if(findingate==2){ // Return to the starting point
    player[i].posy=0;
    player[i].posx=19;
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<<"You have been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Return to the starting point' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
  }
  else if(findingate==3){ // Transferred to a random position
    int set=rand()%169;
    player[i].posy=available[set][1];
    player[i].posx=available[set][0];
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<<"You have been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Transfer to random positoin' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
  }
  else if(findingate==4){
    player[i].posy=0;
    player[i].posx=19;
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<<"You have been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Return to the starting point' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
  }
}

int npcgate(status player[], int i, char map[20][20], int available[169][2],int mode, int &countrank, vector<int> &final){ // 1: Win, 2: Return to the starting point , 3: Transferred to a random position, 4: Return to the starting point
  int a;
  if (final.size()!=0)
  {
    a=final.size();
  }
  else
  {
    a=1;
  }
  int npcchoose=rand()%final.size();
  int findingate=final[npcchoose]; // Find which gate has the player chosen in the array
  final.erase(final.begin()+npcchoose); // Earse the chosen gate

  if(findingate==1){ // Win and end game
    cout << player[i].name << " has won the game! Game Over!" << endl;
    player[i].rank=countrank;
    countrank++;
    player[i].cont=0;
    return 1;
  }
  else if(findingate==2){ // Return to the starting point
    player[i].posy=0;
    player[i].posx=19;
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<< player[i].name << " has been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Return to the starting point' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
    return 2;
  }
  else if(findingate==3){ // Transferred to a random position
    int set=rand()%169;
    player[i].posy=available[set][1];
    player[i].posx=available[set][0];
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<<player[i].name <<" has been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Transfer to random positoin' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
    return 3;
  }
  else if(findingate==4){
    player[i].posy=0;
    player[i].posx=19;
    player[i].prevx=20;
    player[i].prevy=20;
    if (player[i].real)
        cout<<player[i].name <<" has been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    else
    {
        cout<<player[i].name<<" has chosen the gate 'Return to the starting point' and is transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
    }
    return 2;
  }

  return 0;
}

void printgate(vector<int> final){
  if(final.size()==8){
    cout << "  _________________ " << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << "|    NUMBER: 3   | |" << "|    NUMBER: 4   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;

    cout << "  _________________ " << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 5   | |" << "|    NUMBER: 6   | |" << "|    NUMBER: 7   | |" << "|    NUMBER: 8   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==7){
    cout << "  _________________ " << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << "|    NUMBER: 3   | |" << "|    NUMBER: 4   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;

    cout << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 5   | |" << "|    NUMBER: 6   | |" << "|    NUMBER: 7   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==6){
    cout << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << "|    NUMBER: 3   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;

    cout << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 4   | |" << "|    NUMBER: 5   | |" << "|    NUMBER: 6   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==5){
    cout << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << "|    NUMBER: 3   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;

    cout << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 4   | |" << "|    NUMBER: 5   | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==4){
    cout << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << endl;

    cout << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 3   | |" << "|    NUMBER: 4   | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==3){
    cout << "  _________________ " << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << "|    NUMBER: 3   | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==2){
    cout << "  _________________ " << "  _________________ " << endl
         << " /________________/|" << " /________________/|" << endl
         << "|                | |" << "|                | |" << endl
         << "|      GATE      | |" << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << "|    NUMBER: 2   | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|                | |" << "|                | |" << endl
         << "|________________|/ " << "|________________|/ " << endl;
  }
  else if(final.size()==1){
    cout << "  _________________ " << endl
         << " /________________/|" << endl
         << "|                | |" << endl
         << "|      GATE      | |" << endl
         << "|    NUMBER: 1   | |" << endl
         << "|                | |" << endl
         << "|                | |" << endl
         << "|________________|/ " << endl;
  }
}

void Exittogates(status player[], int i, char map[20][20], int mode, int available[169][2],int &countrank, int playernum, vector<int> &final){
  int playerchoose, findingate;
  bool gameend = 1;
  if(mode==2){ // 4 sets 4 gates
    if (player[i].real && player[i].cont){ // player turn
      printgate(final);
      cout << "Player please choose a number from 1 to " << final.size() << " : ";
      cin >> playerchoose;
      cout << endl;
      findingate=final[playerchoose-1]; // Find which gate has the player chosen in the array
      final.erase(final.begin()+playerchoose-1); // Earse the chosen gate
      choosegate(player, i, map, available, mode, countrank, final, findingate);
    }
    else if (not player[i].real && player[i].cont && gameend){ // npc turn
      npcgate(player, i, map, available, mode, countrank, final);
    }
  }
  else if(mode==3){ // 4 sets 6 gates
    if (player[i].real && player[i].cont){
      printgate(final);
      cout << "Player please choose a number from 1 to " << final.size() << " : ";
      cin >> playerchoose;
      cout << endl;
      findingate=final[playerchoose-1]; // Find which gate has the player chosen in the array
      final.erase(final.begin()+playerchoose-1); // Earse the chosen gate
      choosegate(player, i, map, available, mode, countrank, final, findingate);
    }
    else if (not player[i].real && player[i].cont && gameend){ // npc turn
      npcgate(player, i, map, available, mode, countrank, final);
    }
  }
  else if(mode==4){ // 4 sets 8 gates
    if (player[i].real && player[i].cont){
      printgate(final);
      cout << "Player please choose a number from 1 to " << final.size() << " : ";
      cin >> playerchoose;
      cout << endl;
      findingate=final[playerchoose-1]; // Find which gate has the player chosen in the array
      final.erase(final.begin()+playerchoose-1); // Earse the chosen gate
      choosegate(player, i, map, available, mode, countrank, final, findingate);
    }
    else if (not player[i].real && player[i].cont && gameend){ // npc turn
      npcgate(player, i, map, available, mode, countrank, final);
    }
  }
}

void printlayout(char map[20][20], status* player, int mode)
{
    int y = mode;
    cout << setw(2) << "       ";
    for (int i = 0; i < 20; i++)
    {
        cout << setw(2) << i % 10;
    }
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "     " << setw(2) << setfill('0') << i << setfill(' ');
        for (int j = 0; j < 20; j++)
        {
            if (map[i][j] == '0')
                cout << setw(2) << "#";
            else
                cout << setw(2) << map[i][j];

        }
        cout << "                               |           ";
        if (i == 1)
            cout << "PLAYER INFORMATION LIST" << endl;
        else if ((i == 11 || i == 3 || i == 15 || i == 7) && y > 0)
        {
            cout << "Player name: "<<player[mode - y].name << endl;
        }
        else if ((i == 12 || i == 4 || i == 16 || i == 8) && y > 0)
        {
            cout<<"Coordination"<< ": (" << player[mode - y].posy << " , " << player[mode - y].posx << ")" <<endl;
        }
        else if ((i == 13 || i == 5 || i == 17 || i == 9) && y > 0)
        {
            cout<<"Lives: "<<player[mode-y].lives<<endl;
            y--;
        }
        else
            cout << endl;
    }
}//-----------------------------print map use
int playerinputbox1()
{
    string choices;
    char choice;
    cout << "Start rolling the dice? (Y/N)" << endl;
    cin>>choices;//---------------------------------1.
    while ((choices[0] != 'Y' && choices[0] != 'N') || choices.length()>1)
    {
        cout << "Incorrect input please input again,Start rolling the dice? (Y/N)" << endl;
        cin>>choices;
    }
    choice=choices[0];
    if (choice == 'N')//------------------------------1a
    {
        string quitc;
        char quit;
        cout << "Quit game? (Y/N) " << endl;
        cin>>quitc;
        while ((quitc.length()!=1)|| (quitc[0] != 'Y' && quitc[0] != 'N'))
        {
            cout << "Incorrect input please input again, Quit game? (Y/N)" << endl;
            cin>>quitc;
        }
        quit=quitc[0];
        if (quit == 'Y')//-----------------------------1b
        {
            char save;
            cout << "Save game? (Y/N)" << endl;
            cout << "Save game? (Y/N)" << endl;
            cin.get(save);
            cin.ignore(1024, '\n');
            while (save != 'Y' && save != 'N')
            {
                cout << "Incorrect input please input again, Save game? (Y/N)" << endl;
                cin.get(save);
                cin.ignore(1024, '\n');
            }
            if (save == 'Y')
            {
                return 3;//------------------------------------------------------------end the game
            }
            else
            {
                cout << "ENDED WITHOUT SAVE!!!!!!" << endl;
                return 2;//=------------------------------------------------------------end the game
            }

        }
        else
            return 1;
    }
    else
        return 0;
}//--------------------------------------------------------playerinput box 1
bool search(char map[20][20], int posx, int posy, int dirx, int diry, int prevx, int prevy)
{
    if (((posx + dirx) >= 0) && ((posy + diry) >= 0) && ((posx + dirx) < 20) && ((posy + diry) < 20) && (((posx + dirx) != prevx) || ((posy + diry) != prevy)) && map[posx + dirx][posy + diry] == '0')
        return 1;
    else
        return 0;
}//---------------------------------------search available move
void move(status player[], int i, int dice, char map[20][20], int mode)
{
    int count = 0;
    char list[3];
    char choicec;
    string choice;
    if (player[i].posy==0 && player[i].posx==19)
    {
        player[i].prevy=20;
        player[i].prevx=20;
    }
    if (search(map, player[i].posx, player[i].posy, -1, 0, player[i].prevx, player[i].prevy))//up
    {
        list[count] = 'U';
        count++;
    }
    if (search(map, player[i].posx, player[i].posy, 1, 0, player[i].prevx, player[i].prevy) && player[i].real)//down
    {
        list[count] = 'D';
        count++;
    }
    if (search(map, player[i].posx, player[i].posy, 0, -1, player[i].prevx, player[i].prevy))//left
    {
        list[count] = 'L';
        count++;
    }
    if (search(map, player[i].posx, player[i].posy, 0, 1, player[i].prevx, player[i].prevy))//right
    {
        list[count] = 'R';
        count++;
    }
    if (count == 1)
    {
        choicec = list[count - 1];
    }
    else
    {
        if (player[i].real and count!=0)
        {
            printlayout(map, player, mode);
            cout << player[i].name << " ,You have " << dice << " move(s) left!" << endl;
            cout << "Please enter your direction (";
            for (int j = 0; j < count; j++)
            {
                if (j < (count - 1))
                    cout << "'" << list[j] << "',";
                else
                    cout << "'" << list[j] << "'";
            }
            cout << ") (U=up, R=right, L=left, D=down)" << endl;
            cin>>choice;
            while (choice.length()>1 || (choice[0] != list[0] && choice[0] != list[1]))
            {
                cout << "Input Incorrect, please enter again (U=up, R=right, L=left, D=down)" << endl;
                cin>>choice;
            }
            choicec=choice[0];
        }
        else if (count!=0)
        {
            int c=rand()%count;
            choicec=list[c];
        }
    }
    switch (choicec)
    {
    case 'U':
        player[i].prevx = player[i].posx;
        player[i].prevy = player[i].posy;
        player[i].posx--;
        break;
    case 'D':
        player[i].prevx = player[i].posx;
        player[i].prevy = player[i].posy;
        player[i].posx++;
        break;
    case 'L':
        player[i].prevx = player[i].posx;
        player[i].prevy = player[i].posy;
        player[i].posy--;
        break;
    case 'R':
        player[i].prevx = player[i].posx;
        player[i].prevy = player[i].posy;
        player[i].posy++;
        break;
    }

}//-------------------------------------------player move on map
/*bool checktraps(int trapslocation[200][2],status player[],int j)
{
    bool located=0;
    for (int i=0; i<60; i++)
    {
        if (trapslocation[i][0]==player[j].posy && trapslocation[i][1]==player[j].posx)
        {
            located=1;
            break;
        }
    }
    return located;
}*/
bool inspelllist(status player[], int i, char spellusec)
{
    bool yes=0;
    for (int j=0; j<player[i].numofspell; j++)
    {
        char temp=player[i].spell.front();
        if (temp==spellusec)
        {
            yes=1;
            break;
        }
        else
        {
            player[i].spell.pop_front();
            player[i].spell.push_back(temp);
            temp=player[i].spell.front();
        }
    }
    return yes;
}
void spelleffect(char spellusec, status player[], int i,int available[169][2],char map[20][20],int mode,int &countrank, int playernum, vector<int> &final)
{
    for (int j=0; j<player[i].numofspell; j++)
    {
        char temp=player[i].spell.front();
        player[i].spell.pop_front();
        if (temp!=spellusec)
        {
            player[i].spell.push_back(temp);
        }
        else
        {
            player[i].numofspell--;
            break;
        }
    }
    switch (spellusec)
    {
        case '1':
        {
            string name;
            bool cantfind=1;
            if (player[i].real)
            {
                cout<<"Enter a name of player, you planned to attack: "<<endl;
                cin>>name;
                for (int j=0; j<mode; j++)
                {
                    if (name==player[j].name)
                    {
                        cantfind=0;
                        player[j].lives--;
                        cout<<player[j].name<<" remains "<<player[j].lives<<" lives"<<endl;
                        break;
                    }
                }
                while (cantfind)
                {
                    cout<<"This player is not found... Please insert a correct name:"<<endl;
                    cin>>name;
                    for (int j=0; j<mode; j++)
                    {
                        if (name==player[j].name)
                        {
                            cantfind=0;
                            player[j].lives--;
                            cout<<player[j].name<<" remains "<<player[j].lives<<" lives"<<endl;
                            break;
                        }
                    }
                }
            }
            else if (mode!=0)
            {
                int a=rand()%mode;
                int f;
                if (a==i && (a+1)>(mode-1))
                    f=a-1;
                else if (a==i && (a-1)<0)
                    f=a+1;
                else
                    f=a;
                player[f].lives--;
                cout<<player[i].name<<" used spell 1 on "<<player[f].name<<", "<<player[f].name<<" remains "<<player[f].lives<<" lives"<<endl;
            }
            break;
        }
        case '2':
        {
            int set=rand()%169;
            player[i].posy=available[set][1];
            player[i].posx=available[set][0];
            player[i].prevx=20;
            player[i].prevy=20;
            if (player[i].real)
                cout<<"You have been sent to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
            else
            {
                cout<<player[i].name<<" used spell 2 and transfered to ("<<player[i].posy<<","<<player[i].posx<<")"<<endl;
            }
            break;
        }
        case '3':
        {
            if (player[i].lives<5)
                player[i].lives++;
            if (not player[i].real)
            {
                cout<<player[i].name<<" used spell 3"<<endl;
            }
            break;
        }
        case '4':
        {
            int dice = rand() % 6 + 1;
            int d = dice;
            if (player[i].real)
            {
                cout << "You have " << dice << " move(s) " << endl;
            }
            else
            {
                cout<<player[i].name<<" used spell 4"<<endl;
                cout<<player[i].name<<" have "<<d<<" extra move(s)."<<endl;
            }
            for (int j = 0; j < dice; j++)
            {
                move(player, i, d, map, mode);
                d--;
                if (player[i].posx == 0 && player[i].posy == 19)
                {
                    //entered exit
                    cout << player[i].name << " entered the exit" << endl;//---------------------------------------------exit gate header file
                    Exittogates(player,i,map,mode,available,countrank, playernum, final);
                    break;
                }
            }
            break;
        }
    }
}
void usespell(status player[], int i, char map[20][20], int available[169][2],int mode, int &countrank, int playernum, vector<int> &final)
{
    string spellchoice;
    if (player[i].real)
    {
        cin>>spellchoice;
        while (spellchoice.length()>1 || (spellchoice[0]!='Y' && spellchoice[0]!='N'))
        {
            cout<<"Incorrect input, please input again!"<<endl;
            cin>>spellchoice;
        }
    }
    else
    {
        spellchoice="Y";
    }
    char spellc=spellchoice[0];
    switch (spellc)
    {
        case 'N':
            cout<<"No spell used, there are "<<player[i].numofspell<<" spell(s) left"<<endl;
            break;
        case 'Y':
            bool c;
            string spelluse;
            char spellusec;
            cout<<endl;
            if (player[i].real)
            {
                cout<<"Spells Menu:"<<endl;
                cout<<"Code          Description"<<endl;
                cout<<"  1           Select one enemy to attack and deduct enemy's lives by one"<<endl;
                cout<<"  2           You will randomly be sent to a new location"<<endl;
                cout<<"  3           Cure yourself and heal one life"<<endl;
                cout<<"  4           You can roll the dice again and make extra moves"<<endl;
                cout<<endl;
                cout<<"You have "<<player[i].numofspell<<" spell(s)"<<endl;
                cout<<"Your spell list: [";
                for (int j=0; j<player[i].numofspell; j++)
                {
                    if (j<player[i].numofspell-1)
                    {
                        char temp=player[i].spell.front();
                        cout<<temp<<" ,";
                        player[i].spell.pop_front();
                        player[i].spell.push_back(temp);
                    }
                    else
                    {
                        char temp=player[i].spell.front();
                        cout<<temp<<"]"<<endl;
                        player[i].spell.pop_front();
                        player[i].spell.push_back(temp);
                    }
                }
                cout<<"Are you sure to use a spell? (Y/N)"<<endl;
                string confirm;
                cin>>confirm;
                while (confirm.length()>1 ||(confirm[0]!='Y' && confirm[0]!='N'))
                {
                    cin>>confirm;
                }
                if (confirm=="Y")
                {
                    c=1;
                }
                else
                {
                    c=0;
                    cout<<"OK! No spells used"<<endl;
                }
                if (c)
                {
                     cout<<"Please select the spell you want to use by inserting the code number:"<<endl;
                    cin>>spelluse;
                    spellusec=spelluse[0];
                    while (spelluse.length()>1 || not inspelllist(player, i, spellusec))
                    {
                        cout<<"Incorrect input, please input again!"<<endl;
                        cin>>spelluse;
                        spellusec=spelluse[0];
                    }
                }
            }
            else
            {
                spellusec=player[i].spell.front();
                c=1;
            }
            if (c)
            {
                spelleffect(spellusec,player,i,available,map,mode,countrank, playernum, final);
            }
            break;
    }
}
void playerinputbox2(status player[], int i, char map[20][20], int mode, int available[169][2], int &countrank, int playernum, vector<int> &final)
{
    int dice = rand() % 6 + 1;
    int d = dice;
    cout << "You have " << dice << " move(s) " << endl;
    for (int j = 0; j < dice; j++)
    {
        move(player, i, d, map, mode);
        d--;
        if (player[i].posx == 0 && player[i].posy == 19)
        {
            //entered exit
            cout << player[i].name << " entered the exit" << endl;
            Exittogates(player,i,map,mode,available,countrank, playernum, final);
            break;
        }
    }
    if (player[i].cont==1)/*(checktraps(trapslocation, player, i))*/
    {
      cout << player[i].cont << endl;
        int a;
        a=rand()%12+1;
        char c= '0'+a;
        if (a<5)
        {
            cout<<"You found something on the ground!!"<<endl;
            player[i].spell.push_back(c);
            player[i].numofspell++;
        }
        else
        {
              if (a==6|| a==7)
              {
                  if(Hangman()==1)
                  {
                    int b=rand()%4+1;
                    c='0'+b;
                    player[i].spell.push_back(c);
                    player[i].numofspell++;
                  }
                  else
                  {
                      player[i].lives--;
                      cout << "You have lost 1 life!" << endl;
                  }
              }
              if (a==8 || a==9)
              {
                  if (RockPaperScissors()==1)
                  {
                    int b=rand()%4+1;
                    c='0'+b;
                    player[i].spell.push_back(c);
                    player[i].numofspell++;
                  }
                  else
                  {
                      player[i].lives--;
                      cout << "You have lost 1 life!" << endl;
                  }
              }
              if (a==10)
              {
                if (TicTacToe()==1)
                {
                    int b=rand()%4+1;
                    c='0'+b;
                    player[i].spell.push_back(c);
                    player[i].numofspell++;
                }
                else
                {
                    player[i].lives--;
                    cout << "You have lost 1 life!" << endl;
                }
              }
        }
        cout <<"Your spell list: [";
        for (int j=0; j<player[i].numofspell; j++)
        {
            if (j<player[i].numofspell-1)
            {
                char temp=player[i].spell.front();
                cout<<temp<<", ";
                player[i].spell.pop_front();
                player[i].spell.push_back(temp);
            }
            else
            {
                char temp=player[i].spell.front();
                cout<<temp;
                player[i].spell.pop_front();
                player[i].spell.push_back(temp);
            }
        }
        cout<<"]"<<endl;
        if (player[i].numofspell>0)
        {
            cout << "Use the spell? (Y/N)" << endl;
            usespell(player,i,map,available,mode, countrank, playernum, final);
        }
    }

    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}//---------------------------------------------------player input box2

void initalization(string &npcnumc, int &mode, int *&npcnum, string &playernumc, int &playernum, char *&smode)
{
    char modec;
        cout << "Choose mode:" << endl;//need to be design later on------------------------------------------------(2)choose mode
        cout << "Mode 1: 2 Players    Mode 2: 3 Players   Mode 3: 4 Players" << endl;//need to be design later on
        cout << "Input '1' for mode 1, '2' for mode 2, '3' for mode 3" << endl;//need to be design later on
        cin >> modec;
        cin.ignore(1024, '\n');
        while (modec != '3' && modec != '2' && modec != '1')
        {
            cout << "Input error, please enter again" << endl;
            cin.get(modec);
            cin.ignore(1024, '\n');
        }
        mode = modec - '0' + 1;
        //number of player and npc input
        cout << "Number of NPC:" << endl;//need to be design later on
        cin >> npcnumc;
        while (npcnumc.length() > 1 || (npcnumc[0] != '0' && npcnumc[0] != '1' && npcnumc[0] != '2' && npcnumc[0] != '3'))
        {
            cout << "Input incorrect, please input again" << endl;//need to be design later on
            cin >> npcnumc;
        }
        *npcnum = npcnumc[0] - '0';
        cout << "Number of Players:" << endl;//need to be design later on
        cin >> playernumc;
        while (playernumc.length() > 1 && (playernumc[0] != '0' && playernumc[0] != '1' && playernumc[0] != '2' && playernumc[0] != '3'))
        {
            cout << "Input incorrect, please input again" << endl;//need to be design later on
            cin >> playernumc;
        }
        playernum = playernumc[0] - '0';
        while ((*npcnum + playernum) != mode)
        {
            cout << "Input incorrect, please input again" << endl;//need to be design later on
            cout << "Number of NPC:" << endl;//need to be design later on
            cin >> npcnumc;
            while (npcnumc.length() > 1 && (npcnumc[0] != '0' || npcnumc[0] != '1' || npcnumc[0] != '2' || npcnumc[0] != '3'))
            {
                cout << "Input incorrect, please input again" << endl;//need to be design later on
                cin >> npcnumc;
            }
            *npcnum = npcnumc[0] - '0';
            cout << "Number of Players:" << endl;//need to be design later on
            cin >> playernumc;
            while (playernumc.length() > 1 && (playernumc[0] != '0' || playernumc[0] != '1' || playernumc[0] != '2' || playernumc[0] != '3'))
            {
                cout << "Input incorrect, please input again" << endl;//need to be design later on
                cin >> playernumc;
            }
            playernum = playernumc[0] - '0';
        }
        *smode = 'N';
}
void npcmove(status player[], int i, char map[20][20], int mode, int available[169][2],int &countrank, int playernum, vector<int> &final)
{
    int dice = rand() % 6 + 1;
    int d = dice;
    cout<<player[i].name<<" has "<<d<<" move(s)."<<endl;
    for (int j = 0; j < dice; j++)
    {
        move(player, i, d, map, mode);
        d--;
        if (player[i].posx == 0 && player[i].posy == 19)
        {
            //entered exit
            cout << player[i].name << " entered the exit" << endl;//---------------------------------------------exit gate header file
            Exittogates(player,i,map,mode,available,countrank, playernum, final);
            break;
        }
    }
    if (player[i].cont)
    /*(checktraps(trapslocation, player, i))*/
    {
        int a;
        a=rand()%12+1;
        char c= '0'+a;
        if (a<5)
        {
            player[i].spell.push_back(c);
            player[i].numofspell++;
        }
    }
    if (player[i].numofspell>0)
    {
        usespell(player,i,map,available,mode, countrank, playernum, final);
    }
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}
int main()
{
    srand(time(0));
    int countrank=1;
    // variable for exit
    int npcchoose, playerchoose, findingate;
    // variable cannot be removed
    int spells_and_game[13]={1,2,3,4,5,6,7,8,9,10,11,12};
    int available[169][2]={{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{1,6},{1,17},{2,6},{2,10},{2,11},{2,12},{2,13},{2,14},{2,15},{2,16},{2,17},{3,0},{3,1},{3,2},{3,3},{3,4},{3,5},{3,6},{3,10},{4,0},{4,10},{5,0},{5,1},{5,2},{5,3},{5,4},{5,5},{5,6},{5,10},{5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{5,17},{5,18},{5,19},{6,6},{6,19},{7,4},{7,5},{7,6},{7,9},{7,10},{7,11},{7,12},{7,13},{7,14},{7,15},{7,16},{7,17},{7,18},{7,19},{8,0},{8,1},{8,2},{8,3},{8,4},{8,9},{9,0},{9,4},{9,9},{10,0},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9},{11,0},{11,4},{11,9},{11,10},{11,11},{11,12},{11,13},{11,14},{11,15},{11,16},{11,17},{11,18},{11,19},{12,0},{12,1},{12,2},{12,3},{12,4},{12,19},{13,3},{13,14},{13,15},{13,16},{13,17},{13,18},{13,19},{14,3},{14,14},{15,0},{15,1},{15,2},{15,3},{15,4},{15,5},{15,6},{15,7},{15,8},{15,9},{15,10},{15,11},{15,12},{15,13},{15,14},{16,0},{17,0},{17,1},{17,2},{17,3},{17,4},{17,5},{17,6},{17,7},{17,8},{17,9},{17,10},{17,11},{17,12},{17,13},{17,14},{17,15},{17,16},{17,17},{17,18},{17,19},{18,19},{19,0},{19,1},{19,2},{19,3},{19,4},{19,5},{19,6},{19,7},{19,8},{19,9},{19,10},{19,11},{19,12},{19,13},{19,14},{19,15},{19,16},{19,17},{19,18},{19,19}
 };
 /*
    int trapslocation[200][2]={};
    for (int i=0; i<200; i++)
    {
        int set=rand()%169;
        trapslocation[i][0]=available[set][0];
        trapslocation[i][1]=available[set][1];
    }*/
    int mode;
    bool gameend = 1;
    char map[20][20] = {
      ' ',' ',' ',' ',' ',' ','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
      ' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ',' ',
      ' ',' ',' ',' ',' ',' ','0',' ',' ',' ','0','0','0','0','0','0','0','0',' ',' ',
      '0','0','0','0','0','0','0',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0','0','0','0','0','0','0',' ',' ',' ','0','0','0','0','0','0','0','0','0','0',
      ' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',
      ' ',' ',' ',' ','0','0','0',' ',' ','0','0','0','0','0','0','0','0','0','0','0',
      '0','0','0','0','0',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0',' ',' ',' ','0',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0',' ',' ',' ','0','0','0','0','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0',' ',' ',' ','0',' ',' ',' ',' ','0','0','0','0','0','0','0','0','0','0','0',
      '0','0','0','0','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',
      ' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0','0','0','0','0','0',
      ' ',' ',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ',' ',' ',' ',' ',
      '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',' ',' ',' ',' ',' ',
      '0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',
      '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'
    };
    //Initialization
    char* smode = new char;
    int* npcnum = new int;
    int playernum = 0;
    string npcnumc, playernumc, choicec;
    *smode = 'a';
    char* choice = new char;
    system("clear");
    cout << R"RAW( ########################################################################################
##      SSSSSSS  UUU     UUU PPPPPPPPP   EEEEEEEEEEEE RRRRRRRRRR                        ##
##     SSS    SS UUU     UUU PPP     PPP EEE          RRR      RRR                      ##
##    SSS        UUU     UUU PPP      PPPEEE          RRR      RRR                      ##
##     SSSSS     UUU     UUU PPP     PPP EEEEEEEEEEEE RRRRRRRRRR                        ##
##        SSS    UUU     UUU PPPPPPPPP   EEE          RRR  RRRR                         ##
##   SS     SSS  UUUUUUUUUUU PPP         EEE          RRR    RRRR                       ##
##     SSSSSSS   UUUUUUUUUUU PPP         EEEEEEEEEEEE RRR      RRRR                     ##
##                   MMM       MMM EEEEEEEEEEEE LLL         IIIIIIIIIIIII    AA         ##
##                   MMMM     MMMM EEE          LLL              III        AAAA        ##
##                   MM MM   MM MM EEE          LLL              III       AA  AA       ##
##                   MM  MM MM  MM EEEEEEEEEEEE LLL              III      AA    AA      ##
##                   MM   MMM   MM EEE          LLL              III     AAAAAAAAAA     ##
##                   MM         MM EEE          LLLLLLLLLLLL     III    AA        AA    ##
##                   MM         MM EEEEEEEEEEEE LLLLLLLLLLLLIIIIIIIIIIIAA          AA   ##
 ########################################################################################


)RAW";
    cout<<endl;
    cout << "Start / Reload game ('S'= start , 'R' = Reload)" << endl;
    cin >> choicec;
    while (choicec.length()>1 || (choicec[0] != 'S' && choicec[0] != 'R'))
    {
        cout << "Incorrect Input, please enter again" << endl;
        cin >> choicec;
    }
    *choice = choicec[0];
    switch (*choice)// --------------------------------------choose s/r
    {
    case 'S':
        initalization(npcnumc, mode, npcnum, playernumc,  playernum, smode);
        break;
    case 'R'://----------------------------------------------------------------reload game
        *smode='O';
        ifstream fin;
        fin.open("data.txt");
        if (fin.fail())
        {
            cout<<"Sorry, data is not found. Please input the following data to start a new game."<<endl;
            exit(1);
            initalization(npcnumc, mode, npcnum, playernumc, playernum, smode);
        }
        else
        {
            fin>>mode;
            fin.close();
        }

        break;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------
    int totalnumofplayer=mode;
    int numofplayer = playernum;
    vector<int> final; //exit gate final set
    int gatechoose=rand()%3+1;
    delete choice;
    choice = 0;
    status* player = new status[mode];
    if (*smode=='O')
    {
        playernum=0;
        ifstream fin;
        fin.open("data.txt");
        fin>>mode;
        for (int i=0; i<mode; i++)
	    {
		    fin>>player[i].cont;
		    fin>>player[i].lives;
    	  fin>>player[i].name;
		    fin>>player[i].posx;
		    fin>>player[i].posy;
		    fin>>player[i].prevx;
		    fin>>player[i].prevy;
		    fin>>player[i].real;
        fin>>player[i].rank;
            if (player[i].real)
            {
                playernum++;
            }
            fin>>player[i].numofspell;
		    for (int j=0; j<player[i].numofspell; j++){
                char a;
		        fin>>a;
                player[i].spell.push_back(a);
		      }
        }
        fin.close();
    }
    else if (*smode=='N')
    {
        for (int i = 0; i < playernum; i++)
        {
            cout << "Name of Player " << (i + 1) << ": " << endl;
            cin >> player[i].name;
            player[i].lives = 5;
            player[i].real = 1;
            player[i].posx = 19; //changed
            player[i].posy = 0; //changed
            player[i].cont = 1;
            player[i].prevx = 20;
            player[i].prevy = 20;
            player[i].numofspell=0;
            player[i].rank=0;
        }
        for (int i = 0; i < *npcnum; i++)
        {
            string name;
            switch (i)
            {
            case 0:
                name = "npc_1";
                break;
            case 1:
                name = "npc_2";
                break;
            case 2:
                name = "npc_3";
                break;
            case 3:
                name = "npc_4";
                break;
            }
            player[i + playernum].name = name;
            player[i + playernum].lives = 5;
            player[i + playernum].real = 0;
            player[i + playernum].posx = 19; //changed
            player[i + playernum].posy = 0; //changed
            player[i + playernum].prevx = 20;
            player[i + playernum].prevy = 20;
            player[i + playernum].cont = 1;
            player[i + playernum].numofspell=0;
            player[i + playernum].rank=0;

        }
        cin.ignore(2048, '\n');
        cout << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    }
    delete npcnum;
    delete smode;
    smode = 0;
    npcnum = 0;
    system("clear");
    //finish initialization
    //main game
    if(mode==2){
      int exitgates[4][4]={{1,3,2,4}, {2,4,3,1}, {4,2,1,3}, {3,1,4,2}};
      for(int i=0; i<4; i++){
        final.push_back(exitgates[gatechoose][i]);
      }
    }
    else if(mode==3){
      int exitgates[4][6]={{2,1,3,1,3,4}, {3,4,1,3,2,1}, {4,1,2,2,1,3}, {1,2,3,4,3,1}};
      for(int i=0; i<6; i++){
        final.push_back(exitgates[gatechoose][i]);
      }
    }
    else if(mode==4){
      int exitgates[4][8]={{2,3,1,4,3,4,1,2}, {3,2,3,1,4,2,4,1}, {4,4,2,3,1,1,2,3}, {1,2,3,4,3,1,2,4}};
      for(int i=0; i<8; i++){
        final.push_back(exitgates[gatechoose][i]);
      }
    }
    while (gameend)
    {
        for (int i = 0; i < mode; i++)
        {
            printlayout(map, player, mode);
            cout << player[i].name << " turn!" << endl;
            if (player[i].real && player[i].cont)
            {
                //playerinput
                int x = playerinputbox1();
                if (x == 1)
                {
                    while (x == 1)
                        x = playerinputbox1();
                }
                if (x == 0)//--------------------------------------------keep playing
                {
                    playerinputbox2(player, i, map, mode,available,countrank, playernum, final);//player input box2
                    if (not player[i].cont)
                    {
                      cout << numofplayer << endl;
                        numofplayer--;
                        totalnumofplayer--;
                    }
                }
                else if (x == 2)//----------------------------------quit without save
                {
                    gameend = 0;
                    break;
                }
                else if (x == 3)//-------------------------------------quit with save
                {
                    ofstream fout;
		    fout.open("data.txt");
		    if (fout.fail())
		    {
		        cout<<"Fail to save, sorry"<<endl;
			exit(1);
		    }
		    else
		    {
		        fout<<mode<<endl;
		        for (int i=0; i<mode; i++)
			{
			  fout<<player[i].cont<<endl;
			  fout<<player[i].lives<<endl;
			  fout<<player[i].name<<endl;
			  fout<<player[i].posx<<endl;
			  fout<<player[i].posy<<endl;
	      fout<<player[i].prevx<<endl;
			  fout<<player[i].prevy<<endl;
			  fout<<player[i].real<<endl;
        fout<<player[i].rank<<endl;
        fout<<player[i].numofspell<<endl;
			  for (int j=0; j<player[i].numofspell; j++){
			    fout<<player[i].spell.front()<<endl;
            player[i].spell.pop_front();
			  }
			}

		      fout.close();
		    }
		    gameend = 0;
                    break;
                }
            }
            else if ((not player[i].real) && (player[i].cont) && gameend)
            {
                npcmove(player, i, map, mode,available,countrank, playernum, final);
                if(not player[i].cont)
                {
                  totalnumofplayer--;
                }
                //npc move
            }
            if(numofplayer!=0 && totalnumofplayer>1){
              for (int j = 0; j < mode; j++)
              {
                  if (player[j].lives<=0)
                  {
                      cout<<player[j].name<<" lost all his lives, he will return to the starting point."<<endl;
                      player[j].posy=0;
                      player[j].posx=19;
                      player[j].prevy=20;
                      player[j].prevx=20;
                      player[j].lives=5;
                  }
              }
            }
            cout<<"Press any key to continue..."<<endl;
            cin.ignore();
        }
        if (numofplayer == 0 || totalnumofplayer==1)
            gameend = 0;
    }
    cout<<"Ranking: "<<endl;
    for (int i=1; i<countrank; i++)
    {
      for(int j=0; j<mode; j++){
        if(player[j].rank==i){
          cout << i << ": " << player[j].name << endl;
        }
      }
    }
    for(int i=0; i<mode; i++)
    {
        if(player[i].rank==0)
        {
            cout<<countrank<<": "<<player[i].name<<endl;
        }
    }
    return 0;
}
