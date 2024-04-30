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
        cout << "Inserisci x: ";
        cin >> x;
        cout << "Inserisci y: ";
        cin >> y;
        // FIXME: posso inserire 9 navi a caso, sbagliato
        // io farei un vettore di 9 elementi e imponi l'utente a mettere la nave giusta e dove posizionarla, non quanto lunga
        
        // while(verify == false){
        //     cout << "Inserisci la lunghezza da 1 a 4: ";
        //     cin >> lenght;
        //     if ((lenght >= 1) && (lenght <= 4)){
        //         verify = true;
        //     }
        // }
        verify = false;
        cout << "Inserisci in che direzione '0' sotto, '1' a sinistra, '2' sopra, '3' a destra: ";
        cin >> direction;
        mode = (Mode)direction;
        insertBattleShip(battleField, x, y, lenght, mode);
    }
    viewTable(battleField);
    return 0;
}
