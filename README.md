# ENGG1340 Project APRIL 11, 2020
ENGG1340 Project Proposal

NAME OF THE GAME: NEW SUPER MELIA ADVENTURE

CONTACT INFORMATION: Group 100

NAME: Marsha Melis 
UID: 3035683538 
EMAIL: m3568m@connect.hku.hk

NAME: Sze Ho Yin 
UID: 3035688758 
EMAIL: szehoyin@connect.hku.hk


**Introduction of New Super Melia Adventure**

Flow of the game:

Firstly, there will be a home page showing the heading of our text-based game (New Super Melia Adventure) along with a sentence asking the player whether they want to reload the previous game or not. The whole adventure starts with a main game, which will be a monopoly-based map game. The main goal is to be the fastest to reach the exit point and choose the winning gate. Players can select the mode of the game which is to insert the number and symbols of players and non-player characters (npc) respectively. Each player has 5 lives to start with. When players lose all lives (maximum 5), the players will return to the starting point with initial status (5 lives with no spells on hand). There will be random spells and black boxes which act as traps and rewards inside the map. The map contains an exit directing the player to a number of gates, either the “Win” gate or the “Lose” gate. The player wins the game if they successfully choose the winning gate, else, they lose the game. 


Concise demonstration of the game:

- Main Goal
1. Be the fastest player to reach the exit
2. Enter the exit and select the “Win” gate

- Inside the map
1. Spells → Traps / Rewards
2. Black Boxes → Deduct the player’s lives


Game Rules: 

1. Each player has 5 lives in a new game
2. Player will automatically lose the game when they chose the “Lose” gate
3. Player will win the game when they successfully choose the “Win” gate
4. Player should save the game to keep their progress
5. Player will return to the starting position with initial status when they lose all      lives (maximum 5)
   *initial status refers to the player starting with 5 lives and no spells on hand


**Game Features**

1. Generation of random game sets or events
    - random function is used to perform the function of a dice
    - random function is applied in the exit to change the position of the door
    - random function is applied when generating the mini games
    - random function is applied when the player draws different spells

2. Data structures for storing game status
    - use a char array to save the map 
    - use struct player which includes int pos[2] with int x and int y to be the position of the player, string name to be the name of         the player, int life to record the number of lives of the player remaining and another int spell[5] to record the amount of spells       the player own

3. Dynamic memory management
    - create a new struct player[] to store the data of the player as the number of players are variables
    - use a new char[] to store the current available gates in the exit and another new char[] to store the initial gate in the exit

4. File input/output (e.g., for loading/saving game status)
    - create data directories to store the data of the player
    - create a player[].txt file to save the position, name and amount of spells when the player save the game
    - to load the previous progress, use a while loop to read the data of player[].txt  

5. Program codes in multiple files
    - main.cpp include the initialization, initial map, player data and all other header files
    - minigames[n].cpp include the detail of the mini games
    - exit.cpp include the detail arrangements of the exit (i.e the layout of the rooms in the exit)
    - playerAI.cpp for handling the npc part of the player  
    - map.cpp to edit the changes on the map
    - initialize.cpp to perform the initialization of the game

6. Other features
    - Different game modes: players can choose to play with friends or the npc
    - Supporting multiple players: players can choose the total number of players (maximum 4)
    - It is a unique, fusion of tactics, mystery and adventure typed board game which has used monopoly as the prototype and amended by       our own
    - Various types of ending: players may have different ways to end the game as they have to choose among a number of gates when they       arrive to the exit of the map
    *Special game mode: all the players are npc, the computer will stimulate the game
