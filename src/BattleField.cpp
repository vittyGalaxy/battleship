#include "../include/BattleField.h"

/*---------------------------------------------------------------------------*/
void BattleField::init(){
    for(int nRow = 0; nRow < N; nRow++){
        for(int nCol = 0; nCol < N; nCol++){
            BF[nRow][nCol] = water;
        }
    }
}

/*---------------------------------------------------------------------------*/
void BattleField::save(const string& filename){
    // TODO
    // salvare il campo anche grezzo va bene
    // salvare il campo con il nome che viene passato in questa funzione
}

/*---------------------------------------------------------------------------*/
bool BattleField::load(const string& filename){
    // TODO
    // caricare il campo
}

/*---------------------------------------------------------------------------*/
bool BattleField::insertShip(const BattleShip &bs) {
    if(isReady())       { return false; }
    if(!bs.isValid())   { return false; }    

    // save ship into field
    if(!fillCells(bs, ship))    { return false; }

    // add ship
    aoBattleships.push_back(bs);
    return true;
} 

/*---------------------------------------------------------------------------*/
bool BattleField::removeShip(const BattleShip &bs) {
 // TODO
} 

/*---------------------------------------------------------------------------*/
void BattleField::show(){
    for (int nY = 0; nY < N; nY++) {
        for (int nX = 0; nX < N; nX++) {
            switch (BF[nY][nX]) {
                case water:
                    std::cout << "|O|";
                    break;

                case ship:
                    std::cout << "|X|";
                    break;
            }
        }
        cout << endl;
    }
}

/*---------------------------------------------------------------------------*/
bool BattleField::isReady(){
    return (aoBattleships.size() == NUM_SHIPS); 
}

/*---------------------------------------------------------------------------*/
bool BattleField::isEmpty(){
    return (aoBattleships.size() == 0);
}

/*---------------------------------------------------------------------------*/
bool BattleField::fillCells(const BattleShip &bs, State eState){
    if(bs.getLength() > N)  { return false; }
    
    // get coords
    int nXInit  = bs.getXInit() - 1;
    int nYInit  = bs.getYInit() - 1;
    int nXEnd   = bs.getXEnd()  - 1;
    int nYEnd   = bs.getYEnd()  - 1;

    // verify if there is a ship
    if((eState == ship) && isThereAShip(nXInit, nYInit, nXEnd, nYEnd)) { 
        return false; 
    }

    // horizontal
    for(int x = nXInit; x <= nXEnd; x++){
        BF[nYInit][x] = ship;
    }

    // vertical
    for(int y = nYInit; y <= nYEnd; y++){
        BF[y][nXInit] = ship;
    }

    return true;
}

/*---------------------------------------------------------------------------*/
bool BattleField::isThereAShip(int nXInit, int nYInit, int nXEnd, int nYEnd){
    bool shipIsPresent = false;

    if(BF[nYInit][nXInit]   == ship) { return true; }
    if(BF[nYEnd][nXEnd]     == ship) { return true; }

    // horizontal
    for(int x = nXInit; x <= nXEnd; x++){
        shipIsPresent = shipIsPresent || ( BF[nYInit][x] == ship);
    }

    // vertical
    for(int y = nYInit; y <= nYEnd; y++){
        shipIsPresent = shipIsPresent || ( BF[y][nXInit] == ship);
    }

    return shipIsPresent;
}