#include <iostream>
#include <string>
#include <fstream>
#include "mines.h"

using namespace std;
int side, num_mines; //global variable of side and number of mines

void startgame(char realboard[][16], char board[][16]){					//function that initialise two boards, one is for storing the mine position, another one is for player
    srand(time (NULL));									//generate a random number to make sure that the game will not be same everytime
	for (int i=0; i<side; i++){							//ensure that two boards have no mines
		for (int j=0; j<side; j++){
			board[i][j] = realboard[i][j] = '-';
		}
	}
}

void printboard(char board[][16]){							//function that print out the board
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

bool Valid_input(int row, int col){							//function that check whether the input exist on game board
		return ((row >= 0) && (row < side) && (col >= 0) && (col < side));
}

bool Minespot (int row, int col, char minesboard[][16])					//function that check whether the selected cell has mine or not
{
	if (minesboard[row][col] == '*')
		return true;
	else
		return false;
}

char nearbymines_num(int row, int col, int mines[][2], char minesBoard[][16]){		//function that count the number of nearby munes of the selected position
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

//Function that decide the difficulty level of the game(board size, mines amount)
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

//Function that determine when the game end
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
    ifstream fin;
    fin.open("Minesweeper.txt");
    string line;
    while ( getline(fin, line) ) {
		cout << line << endl;
 	}
    string level;
    cout << "Please input the level of difficulty of your game: (Rookie/Challenger/Master)" << endl;
    cin >> level;
    Level (level);
    //cout << side<< '' << num_mines;

    char minesBoard[16][16], playerBoard[16][16]; //step1 : define 2 array (1 for player, 1 for the mines)

    int movesremains = side * side - num_mines;
    int mines[num_mines][2]; // step2 : define an array for mines

    startgame (minesBoard, playerBoard);// step3 : create two game board

    //printboard(minesBoard);
    //printboard(playerBoard);
    Mines_implementation(mines, minesBoard, side, num_mines); // step4 : randomly placing mines in mines board
    //printboard(minesBoard);
    //printboard(playerBoard);
	ofstream fout;
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
    if (movesremains==(side * side - num_mines)){
        
    }
    while (endgame == false){
	    cout<< "Board:"<<endl;
	    printboard(playerBoard);
	    //printboard(minesBoard);
	    int col, row;
	    cout<< "Please enter your move: (row first then col)";
	    cin>>row>>col;
	    endgame = playloop (playerBoard, minesBoard, mines, row, col, &movesremains);
	    if ((endgame == false) && (movesremains == 0)){
	    		ifstream fin2;
    			fin2.open("win.txt");
    			string line2;
    				while (getline(fin2, line2)) {
					cout << line2 << endl;
 				}
	    		endgame = true;
				remove("answer.txt");
	    	}
    	}

    
        return 0;
}
