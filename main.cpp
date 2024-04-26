#include <iostream>
#include "function.h"

using namespace std;

int main() {
//    int Dnavalship1 = 0, Dnavalship2 = 0, Dnavalship2_2 = 0, Dnavalship3 = 0, Dnavalship3_2 = 0, Dnavalship4 = 0;
//    int x1 = 0,  x2 = 0, x2_2 = 0, x3 = 0, x3_2 = 0, x4 = 0;
//    int y1 = 0,  y2 = 0, y2_2 = 0, y3 = 0, y3_2 = 0, y4 = 0;
//    bool Verify = false;
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship1;
//    Verify = verifyD(Dnavalship1);
//    if (Verify == true){
//        return 0;
//    }
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship2;
//    Verify = verifyD(Dnavalship2);
//    if (Verify == true){
//        return 0;
//    }
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship2_2;
//    Verify = verifyD(Dnavalship2_2);
//    if (Verify == true){
//        return 0;
//    }
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship3;
//    Verify = verifyD(Dnavalship3);
//    if (Verify == true){
//        return 0;
//    }
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship3_2;
//    Verify = verifyD(Dnavalship3_2);
//    if (Verify == true){
//        return 0;
//    }
//    cout << "Inserisci 0 per andare sotto, 1 a sinistra, 2 sopra, 3 a destra: ";
//    cin >> Dnavalship4;
//    Verify = verifyD(Dnavalship4);
//    if (Verify == true){
//        return 0;
//    }
//    bool battleField [n][n];
    bool *battleField[n];
    for(int i=0; i<n; i++){
        battleField[i] = new bool[n];
    }
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            battleField[nRow][nCol] = false;
        }
    }
//    insertBattleShip(battleField, 0, 0, 4, horizontalRight);
    insertBattleShip(battleField, 11, 1, 4, horizontalRight);
    insertBattleShip(battleField, 10, 1, 4, horizontalRight);
//    insertBattleShip(battleField, 1, 1, 4, horizontalLeft);
//    insertBattleShip(battleField, 6, 5, 3, horizontalLeft);
//    insertBattleShip(battleField, 3, 4, 2, horizontalRight);
//    insertBattleShip(battleField, 2, 5, 1, verticalOn);
//    insertBattleShip(battleField, 1, 2, 3, horizontalRight);
//    insertBattleShip(battleField, 9, 6, 2, verticalBelow);
    viewTable(battleField);
    return 0;
}
