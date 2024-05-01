#include <iostream>
#include "function.h"

using namespace std;

int main() {
    Mode mode;
    int x = 0, y = 0, lenght = 0, direction = 0;
    bool verify = false;
    int* battleField[n];
    for(int i=0; i<n; i++){
        battleField[i] = new int[n];
    }
    for (int nRow = 0; nRow < n; nRow++) {
        for (int nCol = 0; nCol < n; nCol++) {
            battleField[nRow][nCol] = zero;
        }
    }
    for (int i = 0; i < 9; i++){
        switch (i) {
            case 0:
                cout << "nave da 4" << endl;
                lenght = 4;
                break;
            case 1:
                cout << "nave da 3" << endl;
                lenght = 3;
                break;
            case 2:
                cout << "nave da 3" << endl;
                break;
            case 3:
                cout << "nave da 3" << endl;
                break;
            case 4:
                cout << "nave da 2" << endl;
                lenght = 2;
                break;
            case 5:
                cout << "nave da 2" << endl;
                break;
            case 6:
                cout << "nave da 2" << endl;
                break;
            case 7:
                cout << "nave da 1" << endl;
                lenght = 1;
                break;
            case 8:
                cout << "nave da 1" << endl;
                break;
        }
        cout << "Inserisci x: ";
        cin >> x;
        cout << "Inserisci y: ";
        cin >> y;
        cout << "Inserisci in che direzione '0' sotto, '1' a sinistra, '2' sopra, '3' a destra: ";
        cin >> direction;
        mode = (Mode)direction;
        insertBattleShip(battleField, x, y, lenght, mode);
        verify = insertBattleShip(battleField, x, y, lenght, mode);
        if (verify == false){
            cout << "Rimetti la nave" << endl;
            i--;
        }
    }
    viewTable(battleField);
    return 0;
}
