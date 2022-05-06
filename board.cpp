#include <iostream>
#include "board.h"
using namespace std;

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
