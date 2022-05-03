#include <iostream>
#include <string>

using namespace std;

int side, num_mines;

void Level(string level)
{
    if (level == "Master")
    {
        side = 16;
        num_mines = 45;
    }
 
    if (level == "Challenger")
    {
        side = 9;
        num_mines = 12;
    }
 
    if (level == "Rookie")
    {
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
    int board [side][side];
    //cout << side<< '' << num_mines;
    return 0;
}
