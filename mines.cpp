#include "mines.h"
#include <stdlib.h> 

//The 
void Mines_implementation(int mines[][2], char minesBoard[][16], int side, int num_mines)
{	
	bool check[side*side];
	for (int i=0; i<num_mines;)
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
