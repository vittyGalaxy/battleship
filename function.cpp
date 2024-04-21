#include <iostream>
#include "function.h"

using namespace std;

bool insertBattleShip(bool *F[], int startX, int startY, int length, Mode mode) {
    switch (mode) {
        case horizontalRight:
            return insertBattleshipHorizontalRight(*F, startX, startY, length);
        case verticalOn:
            return insertBattleshipVerticalOn(*F, startX, startY, length);
        case verticalBelow:
            return insertBattleshipVerticalBelow(*F, startX, startY, length);
        case horizontalLeft:
            return insertBattleshipHorizontalLeft(*F, startX, startY, length);
        default:
            break;
    }
    return false;
}

bool insertBattleshipVerticalOn(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX][startY - row]){
            return false;
        }else{
            F [startX] [startY - row] = true;
        }
    }
    return true;
}

bool insertBattleshipHorizontalLeft(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX - row][startY]){
            return false;
        }else{
            F [startX - row] [startY] = true;
        }
    }
    return true;
}

bool insertBattleshipVerticalBelow(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX][startY + row]){
            return false;
        }else{
            F [startX] [startY + row] = true;
        }
    }
    return true;

}

bool insertBattleshipHorizontalRight(bool *F[], int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (F[startX + row][startY]){
            return false;
        }else{
            F[startX + row] [startY] = true;
        }
    }
    return true;
};

void makeTable(bool *F[]) {
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            if (!F[nRow][nCol]) {
                cout << "|O| ";
                cout << "---";
            } else {
                cout << "|X| ";
                cout << "---";
            }
        }
    }
}

bool verifyD(int naval){
    if ((naval > 3) || (naval < 0)){
        return true;
    }else{
        return false;
    }
}