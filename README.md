# Group-35 (Project Proposal)

## Identification of The Team Members
```
* Team_Member_1 
* Github username: Benwong410 
* Name: Wong Hin Chi 
* UID:3035806324
```
```
* Team_Member_2
* Github username: JaeTee211
* Name: Tsang Hing Kwan Jack
* UID:3035782396
```

# Proposed Project

## Name of Game
Minesweeper

## Brief Description
Randomly generate a rectangular board with selected number of "mines" for each game. Clear the unit of the board without detonating the "mines".

## Game Rules
1. Before the start of the game, player need to input the number of row and column of the board, also the number of "mines".
2. Player can only input one position (in row and column) to be cleared for each movement.
3. For each movement, if the selected unit is not "mine", there will be hints provided, telling the player how many "mines" around the cleared area.
4. If all the unit are cleared and the "mines" are not detonated, the game will finish and the player will win the game.

## Features and Coding Requirements
* 1: Generation of random game sets or events
    * The position of the "mines" will be randomly generated

* 2: Data structures for storing game status
    * The game will use 2D arrays for storing the game status, such as the board on screen and hiden game board

* 3: Dynamic memory management
    * There will be update of arrays after player input and provide hints
    
* 4: File input/output (e.g., for loading/saving game status)
    * The game can be pause and resume if the players quit 
    
* 5: Program codes in multiple files
    * use makefile to store function in mutiple files
