#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int side, num_mines; //global variable of side and number of mines

void startgame(char realboard[][16], char board[][16]){
    srand(time (NULL));
	for (int i=0; i<side; i++){
		for (int j=0; j<side; j++){
			board[i][j] = realboard[i][j] = '-';
		}
	}
}

void printboard(char board[][16]){
	cout << "  ";
	for (int i=0; i<side; i++){
		cout << " " << i;
	}
	cout << endl;
	for (int i=0; i<side; i++){
		cout << " " << i;
		for (int j=0; j<side; j++){
			cout << " " << board[i][j];
		}
		cout << endl;
	}
}

void Mines_implementation(int mines[][2], char minesBoard[][16])
{
	bool check[side*side];

	//memset (mark, false, sizeof (mark));

	for (int i=0; i<num_mines; )
	{
		int random = rand() % (side*side);
		int x = random / side;
		int y = random % side;

		if (check[random] == false)
		{
			mines[i][0]= x;
			mines[i][1] = y;

			minesBoard[mines[i][0]][mines[i][1]] = '*';
			check[random] = true;
			i++;
		}
	}

	return;
}

int nearbymines(int row, int col, int mines[][2], char realBoard[][16]){	//function that checks the whether there are mines in nearby position of the selected position
	int count=0;
	if (isValid(row+1,col)==true){				//check the south
		if (isMine(row+1, col, realBoard)==true){
			count++;
		}
	}
	if (isValid(row,col+1)==true){				//check the east
		if (isMine(row, col+1, realBoard)==true){
			count++;
		}
	}
	if (isValid(row-1,col)==true){				//check the north
		if (isMine(row-1, col, realBoard)==true){
			count++;
		}
	}
	if (isValid(row,col-1)==true){				//check the west
		if(isMine(row, col-1, realBoard)==true){
			count++;
		}
	}
	if (isValid(row-1, col+1)==true){			//check the north-east
		if (isMine(row-1, col+1, realBoard)==true){
			count++;
		}
	}
	if (isValid(row-1, col-1)==true){			//check the north-west
		if (isMine(row-1, col-1, realBoard)==true){
			count++;
		}
	}
	if (isValid(row+1, col-1)==true){			//check the south-west
		if (isMine(row+1, col-1, realBoard)==true)
			count++;
		}
	}
	if (isValid(row+1, col+1)==true){			//check the south-east
		if (isMine (row+1, col+1, realBoard)==true)
			count++;
		}
	}
	return (count);
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

	char minesBoard[16][16], playerBoard[16][16]; //step1 : define 2 array (1 for player, 1 for the mines)

    int movesremains = side * side - num_mines;
	int mines[num_mines][2]; // step2 : define an array for mines

    startgame (minesBoard, playerBoard);// step3 : create two game board

    //printboard(minesBoard);
    //printboard(playerBoard);
    Mines_implementation (mines, minesBoard); // step4 : randomly placing mines in mines board
    //printboard(minesBoard);
    //printboard(playerBoard);
	bool endgame = false; 

	while (endgame == false)
	{
		cout<< "Board:"<<endl;
		printboard(playerBoard);
		int col, row;

		cin>>row>>col;

		endgame = playloop (playerBoard, minesBoard, mines, row, col, &movesremains);

		if ((endgames == false) && (movesremains == 0))
		{
			cout<<"Winner Winner, Chicken Dinner!";
			endgame = true;
		}
	}
    
    return 0;
}
