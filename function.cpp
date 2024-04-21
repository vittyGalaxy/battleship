#include <iostream>
#include "function.h"

using namespace std;

bool insertBattleShip(bool F, int startX, int startY, int length, Mode mode) {
    switch (mode) {
        case horizontalRight:
            return insertBattleshipHorizontalRight(&F, startX, startY, length);
        case verticalOn:
            return insertBattleshipVerticalOn(&F, startX, startY, length);
        case verticalBelow:
            return insertBattleshipVerticalBelow(&F, startX, startY, length);
        case horizontalLeft:
            return insertBattleshipHorizontalLeft(&F, startX, startY, length);
        default:
            break;
    }
    return false;
}

bool insertBattleshipVerticalOn(bool *F, int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (battleField[startX][startY - row]){
            return false;
        }else{
            *F = battleField [startX] [startY - row] = true;
        }
    }
    return true;
}

bool insertBattleshipHorizontalLeft(bool *F, int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (battleField[startX - row][startY]){
            return false;
        }else{
            *F = battleField [startX - row] [startY] = true;
        }
    }
    return true;
}

bool insertBattleshipVerticalBelow(bool *F, int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (battleField[startX][startY + row]){
            return false;
        }else{
            *F =  battleField [startX] [startY + row] = true;
        }
    }
    return true;

}

bool insertBattleshipHorizontalRight(bool *F, int startX, int startY, int length){
    for (int row = 0; row < length; row++){
        if (battleField[startX + row][startY]){
            return false;
        }else{
            *F = battleField [startX + row] [startY] = true;
        }
    }
    return true;
};

void makeTable() {
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            battleField[nRow][nCol] = false;
        }
    }

    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            if (!battleField[nRow][nCol]) {
                cout << "|O|";
            } else {
                cout << "|X|";
            }
        }
    }
}