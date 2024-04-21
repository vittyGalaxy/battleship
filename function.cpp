#include <iostream>
#include "function.h"

using namespace std;

bool insertBattleShip(bool *F[], int startX, int startY, int length, Mode mode) {
    switch (mode) {
        case horizontalRight:
            return insertBattleshipHorizontalRight(F, startX, startY, length);
        case verticalOn:
            return insertBattleshipVerticalUp(F, startX, startY, length);
        case verticalBelow:
            return insertBattleshipVerticalDown(F, startX, startY, length);
        case horizontalLeft:
            return insertBattleshipHorizontalLeft(F, startX, startY, length);
        default:
            break;
    }
    return false;
}

bool insertBattleshipVerticalUp(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX - row][startY]){
            return false;
        }else{
            F[startX - row][startY] = true;
        }
    }
    return true;
}

bool insertBattleshipHorizontalLeft(bool *F[], int startX, int startY, int length){
    for (int col = 0; col < length; col++){
        if (F[startX][startY - col]){
            return false;
        }else{
            F[startX][startY - col] = true;
        }
    }
    return true;
}

bool insertBattleshipVerticalDown(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX + row][startY]){
            return false;
        }else{
            F [startX + row][startY] = true;
        }
    }
    return true;

}

bool insertBattleshipHorizontalRight(bool *F[], int startX, int startY, int length){
    for (int col = 0; col < length; col++){
        if (F[startX][startY + col]){
            return false;
        }else{
            F[startX] [startY + col] = true;
        }
    }
    return true;
};

void makeTable(bool *F[]) {
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            if (!F[nRow][nCol]) {
                cout << "|O| ";
            } else {
                cout << "|X| ";
            }
        }
        cout << endl;
    }
}

bool verifyD(int naval){
    if ((naval > 3) || (naval < 0)){
        return true;
    }else{
        return false;
    }
}