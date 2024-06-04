#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////
// ifstream battleshipFile("BattleShip.txt");
//     for (int i = 0; i < 10; i++){
//         for (int j = 0; j < 10; j++){
//             if(battleField[i][j] != Battleship::zero){
//                 battleshipFile << i << j;
//             }
//         }
//     }
// battleshipFile.close();

//////////////////////////////////////////////////////////////
// int* battleField[n];
// for(int i=0; i<n; i++){
//     battleField[i] = new int[n];
// }
// for (int nRow = 0; nRow < n; nRow++) {
//     for (int nCol = 0; nCol < n; nCol++) {
//         battleField[nRow][nCol] = zero;
//     }
// }


int main() {
    Mode mode;
    int x = 0, y = 0, direction = 0;
    Battleship lenght = zero;
    bool verify = false;

    unsigned int numAttempt = 0;
    const unsigned int MAX_ATTEMPT = 3;


    // create BF
    // int* battleField = create();

    // define ships
    Battleship ships[9] = {one, one, two, two, two, three, three, three, four};


    // chose
    unsigned int choise = 0;
    cout << "metti '1' se vuoi inserire le navi, '2' se vuoi salvare il campo, '3' se vuoi caricare il campo, '0' se vuoi uscire: ";
    cin >> choise;
    while(choise != 0){

        // CHECK
        while((choise > 4) && (numAttempt < MAX_ATTEMPT)){
            cout << "scelta non adatta" << endl;
            cout << "metti '1' se vuoi inserire le navi, '2' se vuoi salvare il campo, '3' se vuoi caricare il campo, '0' se vuoi uscire: ";
            cin >> choise;
            numAttempt++;

            if(numAttempt == MAX_ATTEMPT){
                cout << "ma allora é evidente che sei un cretino e che la battaglia navale non fa per te!" << endl;
                return 1;
            }
        }
        
        numAttempt = 0;

        if(choise == 1){
            // input all ships
            for (int i = 0; i < 9; i++){
                lenght = ships[i];
                cout << "Inserisci nave da " << lenght << endl;
                cout << "Inserisci x: ";
                cin >> x;
                cout << "Inserisci y: ";
                cin >> y;
                cout << "Inserisci in che direzione '0' sotto, '1' a sinistra, '2' sopra, '3' a destra: ";
                cin >> direction;
                mode = (Mode)direction;
                verify = insertBattleShip(battleField, x, y, lenght, mode);
                if (!verify){
                    cout << "Rimetti la nave" << endl;
                    i--;
                }else{
                    cout << "nave inserita" << endl;
                }
            }
        }

        if(choise == 2){
            // save the field
            // save();
        }

        if(choise == 3){
            // load the field
            // load();
        }

        if(choise == 4){
            // remove
            // remove();
        }
       
        cout << "metti '1' se vuoi inserire le navi, '2' se vuoi salvare il campo, '3' se vuoi caricare il campo, '0' se vuoi uscire: ";
        cin >> choise;
    }
    viewTable(battleField);
    return 0;
}
