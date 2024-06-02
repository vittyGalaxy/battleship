#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

int main() {
    int choise = 0;
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
    cout << "metti '1' se vuoi inserire le navi, '2' se vuoi salvare il campo, '3' se vuoi caricare il campo, '0' se vuoi uscire: ";
    cin >> choise;
    ifstream battleshipFile("BattleShip.txt");
    while (choise == 0){
        switch (choise) {
            case 1:
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
                break;
            case 2:
                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        battleshipFile << battleField[i][j];
                    }
                }

                break;
            case 3:

                break;
            default:
                cout << "non esiste quel numero" << endl;
                break;
        }
        cout << "metti '1' se vuoi inserire le navi, '2' se vuoi salvare il campo, '3' se vuoi caricare il campo, '0' se vuoi uscire: ";
        cin >> choise;
    }
    battleshipFile.close();
    viewTable(battleField);
    return 0;
}
