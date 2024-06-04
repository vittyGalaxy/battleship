
#ifndef BATTLEFIELD_FUNCTION_H
#define BATTLEFIELD_FUNCTION_H

const int n = 10;

enum Battleship:int {
    zero = 0,
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

bool insertBattleShip(int *F[], int startX, int startY, Battleship length, Mode mode);

bool insertBattleshipVerticalUp(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipHorizontalRight(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipVerticalBottom(int *F[], int startX, int startY, Battleship length);

bool insertBattleshipHorizontalLeft(int *F[], int startX, int startY, Battleship length);

void viewTable(int *F[]);

// void save();

// bool load();

// bool removeShip();


#endif //BATTLEFIELD_FUNCTION_H
