
#ifndef BATTLEFIELD_FUNCTION_H
#define BATTLEFIELD_FUNCTION_H

const int n = 10;

enum Battleship:int {
    water = 0,
     one = 1,
     two = 2,
     three = 3,
     four = 4
};

enum Mode {
    verticalBottom = 0,
    horizontalLeft = 1,
    verticalUp = 2,
    horizontalRight = 3
};

struct BattleShip{
    Battleship evalue;
    std::string name;
    int xInit;
    int yInit;
    int xEnd;
    int yEnd;
};

bool insertBattleShip(int *F[], int startX, int startY, Battleship length, Mode mode);

bool insertBattleshipVerticalUp(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipHorizontalRight(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipVerticalBottom(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipHorizontalLeft(int *F[], int startX, int startY, Battleship length);

void viewTable(int *F[]);

void saveFile(int *F[]);

void loadFile(int *F[]);


#endif //BATTLEFIELD_FUNCTION_H
