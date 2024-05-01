
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

// TYPO: nomi sbagliati, verticalBottom e verticalUP
enum Mode {
    verticalBelow = 0,
    horizontalLeft = 1,
    verticalOn = 2,
    horizontalRight = 3
};

bool insertBattleShip(int *F[], int startX, int startY, int length, Mode mode);

bool insertBattleshipVerticalUp(int *F[], int startX, int startY, int length);

bool insertBattleshipHorizontalRight(int *F[], int startX, int startY, int length);

bool insertBattleshipVerticalDown(int *F[], int startX, int startY, int length);

bool insertBattleshipHorizontalLeft(int *F[], int startX, int startY, int length);

void viewTable(int *F[]);


#endif //BATTLEFIELD_FUNCTION_H
