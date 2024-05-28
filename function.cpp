#include <iostream>
#include "function.h"

using namespace std;

bool insertBattleShip(int *F[], int startX, int startY, Battleship length, Mode mode) {
    if (startX <= 0 || startY <= 0){
        cout << "nave non inserita" << endl;
        return false;
    }
    startX--;
    startY--;
    switch (mode) {
        case horizontalRight:
            return insertBattleshipHorizontalRight(F, startX, startY, length);
        case verticalUp:
            return insertBattleshipVerticalUp(F, startX, startY, length);
        case verticalBottom:
            return insertBattleshipVerticalBottom(F, startX, startY, length);
        case horizontalLeft:
            return insertBattleshipHorizontalLeft(F, startX, startY, length);
        default:
            break;
    }
    return false;
}

bool insertBattleshipVerticalUp(int *F[], int startX, int startY, Battleship length){
    if ((((startX - 1) - length) > 10) || (((startX - 1)- length) < 0)){
        cout << "nave non inserita" << endl;
        return false;
    }
    for (int row = 0; row < length; row++){
        if (F[startX - row][startY] != zero){
            return false;
        }else{
            F[startX - row][startY] = length;
        }
    }
    return true;
}

bool insertBattleshipHorizontalLeft(int *F[], int startX, int startY, Battleship length){
    if ((((startY + 1) - length) > 10) || (((startY + 1) - length) < 0)){
        cout << "nave non inserita" << endl;
        return false;
    }
    for (int col = 0; col < length; col++){
        if (F[startX][startY - col] != zero){
            return false;
        }else{
            F[startX][startY - col] = length;
        }
    }
    return true;
}

bool insertBattleshipVerticalBottom(int *F[], int startX, int startY, Battleship length){
    if ((((startX - 1) + length) > 10) || (((startX - 1) + length) < 0)){
        cout << "nave non inserita" << endl;
        return false;
    }
    for (int row = 0; row < length; row++){
        if (F[startX + row][startY] != zero){
            return false;
        }else{
            F [startX + row][startY] = length;
        }
    }
    return true;

}

bool insertBattleshipHorizontalRight(int *F[], int startX, int startY, Battleship length){
    if ((((startX - 1) + length) > 10) || (((startX - 1) + length) < 0)){
        cout << "nave non inserita" << endl;
        return false;
    }
    for (int col = 0; col < length; col++){
        if (F[startX][startY + col] != zero){
            return false;
        }else{
            F[startX] [startY + col] = length;
        }
    }
    return true;
};

void viewTable(int *F[]) {
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            switch (F[nRow][nCol]) {
                case zero:
                    cout << "|O|";
                    break;
                case one:
                    cout << "|A|";
                    break;
                case two:
                    cout << "|B|";
                    break;
                case three:
                    cout << "|C|";
                    break;
                case four:
                    cout << "|D|";
                    break;
            }
        }
        cout << endl;
    }
}
