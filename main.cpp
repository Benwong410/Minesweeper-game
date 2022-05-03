#include <iostream>
#include <string>
#define MAXSIDE 17

using namespace std;

int side, num_mines; //global variable of side and number of mines

void startgame(char realboard[][MAXSIDE], char board[][MAXSIDE]){
	srand(time (NULL));
	for (int i=0; i<SIDE; i++){
		for (int j=0; j<SIDE; j++){
			board[i][j] = realboard[i][j] = '-';
		}
	}
}

void printboard(char board[][MAXSIDE])
{
	cout << " ";
	for (i=0; i<SIDE; i++){
		cout << " " << i;
	}
	cout << endl;
	for (i=0; i<SIDE; i++){
		cout << " " << i;
		for (j=0; j<SIDE; j++){
			cout << " " << board[i][j];
		}
		cout << endl;
	}
}

//Function that decide the level of the game(board size, mines amount)
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

int main()
{
    string level;
    cout << "Please input the level of difficulty of your game: (Rookie/Challenger/Master)" << endl;
    cin >> level;
    Level (level);
    //cout << side<< '' << num_mines;
    
    int board [side][side];
    
    
    return 0;
}
