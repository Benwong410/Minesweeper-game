#include <iostream>
#include <string>
#include <fstream>
#include "mines.h"

using namespace std;
int side, num_mines; //global variable of side and number of mines

//A function that initialise two boards, one is for storing the mine position, another one is for player
void startgame(char realboard[][16], char board[][16]){					
    srand(time (NULL));									//generate a random number to make sure that the game will not be same everytime
	for (int i=0; i<side; i++){							//ensure that two boards have no mines
		for (int j=0; j<side; j++){
			board[i][j] = realboard[i][j] = '-';
		}
	}
}

//A function that print out the board
void printboard(char board[][16]){							
	cout << "  ";
	for (int i=0; i<side; i++){							//print out the columns
		cout << " " << i;
	}
	cout << endl;
	for (int i=0; i<side; i++){							//print out the rows
		cout << " " << i;
		for (int j=0; j<side; j++){
			cout << " " << board[i][j];
		}
		cout << endl;
	}
}

//A function that check whether the input exist on game board
bool Valid_input(int row, int col){							
		return ((row >= 0) && (row < side) && (col >= 0) && (col < side));
}

//A function that check whether the selected cell has mine or not
bool Minespot (int row, int col, char minesboard[][16])					
{
	if (minesboard[row][col] == '*')
		return true;
	else
		return false;
}

//A function that count the number of nearby munes of the selected position
char nearbymines_num(int row, int col, int mines[][2], char minesBoard[][16]){		
	int num=0;
	if (Valid_input(row+1,col)==true && Minespot(row+1, col, minesBoard)==true){	//check the south	
		num++;
	}
	if (Valid_input(row,col+1)==true && Minespot(row, col+1, minesBoard)==true){	//check the east
		num++;
	}
	if (Valid_input(row-1,col)==true && Minespot(row-1, col, minesBoard)==true){	//check the north
		num++;
	}
	if (Valid_input(row,col-1)==true && Minespot(row, col-1, minesBoard)==true){	//check the west
		num++;
	}
	if (Valid_input(row-1, col+1)==true && Minespot(row-1, col+1, minesBoard)==true){//check the north-east
		num++;
	}
	if (Valid_input(row-1, col-1)==true && Minespot(row-1, col-1, minesBoard)==true){//check the north-west
		num++;
	}
	if (Valid_input(row+1, col-1)==true && Minespot(row+1, col-1, minesBoard)==true){//check the south-west
		num++;
	}
	if (Valid_input(row+1, col+1)==true && Minespot (row+1, col+1, minesBoard)==true){//check the south-east
		num++;
	}
	return num;
}

//A function that decide the difficulty level of the game(board size, mines amount)
void Level(string level)
{
    if (level == "Master"){//Hardest level with 16*16 board and 45 mines in total
        side = 16;
        num_mines = 45;
    }
 
    if (level == "Challenger"){//Intermediate level with 9*9 board and 12 mines in total
        side = 9;
        num_mines = 12;
    }
 
    if (level == "Rookie"){//Beginner level with 5*5 board and 3 mines in total
        side = 5;
        num_mines = 3;
    }
 
    return;
}

//A function that determine when the game end
bool playloop(char playerBoard[][16], char minesBoard[][16], int mines[][2], int row, int col, int *movesremains)
{

	if (playerBoard[row][col] != '-')
		return (false);

	// You opened a mine
	// You are going to lose
	if (minesBoard[row][col] == '*')
	{
		playerBoard[row][col]='*';

		for (int i=0; i<num_mines; i++)
			playerBoard[mines[i][0]][mines[i][1]]='*';

		printboard (playerBoard);
		ifstream fin1;
    		fin1.open("lose.txt");
    		string line1;
    			while (getline(fin1, line1)) {
				cout << line1 << endl;
 			}
		remove("answer.txt");
		return true ;
	}
	else{
		(*movesremains)--;
		playerBoard[row][col] = nearbymines_num(row, col, mines, minesBoard) + '0';
		return false;
	}
}			


int main(){
    ifstream fin;                                  //*File input* that inculde a graphic and print in the terminal
    fin.open("Minesweeper.txt");
    string line;
    while ( getline(fin, line) ) {
		cout << line << endl;
 	}
    string level;
    cout << "Please input the level of difficulty of your game: (Rookie/Challenger/Master)" << endl;
    cin >> level;                                 //step1: player input the difficulty of the game which determine the size of board and number of mines
    Level (level);
    

    char minesBoard[16][16], playerBoard[16][16]; //step2 : define 2 array (1 for player, 1 for the mines)

    int movesremains = side * side - num_mines;
    int mines[num_mines][2];                      // step3 : define an array for mines

    startgame (minesBoard, playerBoard);          // step4 : create two game board (one for terminal, one for mines)

   
    Mines_implementation(mines, minesBoard, side, num_mines); // step5 : randomly placing mines in mines board
    
	ofstream fout;                            //**File output** of the location of mines which can be used for cheating if needed  
	fout.open("answer.txt", ios::app);
	fout << "  ";
	for (int i=0; i<side; i++){
		fout << " " << i;
	}
	fout << endl;
	for (int i=0; i<side; i++){
		fout << " " << i;
		for (int j=0; j<side; j++){
			fout << " " << minesBoard[i][j];
		}
		fout << endl;
	}
	fout.close();
    bool endgame = false;                 
    while (endgame == false){                                      //if endgame is false the game will continue
	    cout<< "Board:"<<endl;
	    printboard(playerBoard);                               //print out the board for player in every turn
	    int col, row;
	    cout<< "Please enter your move: (row first then col)"; //player input their moves
	    cin>>row>>col;
	    endgame = playloop (playerBoard, minesBoard, mines, row, col, &movesremains); //endgame will be true if the player hits the mines
	    if ((endgame == false) && (movesremains == 0)){        //if players win the game
	    		ifstream fin2;                             //**File input** a "win" graphic and print on terminal
    			fin2.open("win.txt");
    			string line2;
    				while (getline(fin2, line2)) {
					cout << line2 << endl;
 				}
	    		endgame = true;                            //break the loop
			remove("answer.txt");                      //Deleted the **File output** answer txt file
	    	}
    	}   
        return 0;
}
