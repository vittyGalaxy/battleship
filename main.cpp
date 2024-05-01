#include <iostream>
#include "function.h"

using namespace std;

int main() {
    Mode mode;
    int x = 0, y = 0, direction = 0;
    Battleship lenght = zero;
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
    int choises[9] = {one, one, two, two, two, three, three, three, four};
    for (int i = 0; i < 9; i++){
        lenght = (Battleship)choises[i];
        cout << "Inserisci nave da " << lenght << endl;
        cout << "Inserisci x: ";
        cin >> x;
        cout << "Inserisci y: ";
        cin >> y;
        cout << "Inserisci in che direzione '0' sotto, '1' a sinistra, '2' sopra, '3' a destra: ";
        cin >> direction;
        mode = (Mode)direction;
        verify = insertBattleShip(battleField, x, y, lenght, mode);
        if (verify == false){
            cout << "Rimetti la nave" << endl;
            i--;
        }else{
            cout << "nave inserita" << endl;
        }
    }
    viewTable(battleField);
    return 0;
}
