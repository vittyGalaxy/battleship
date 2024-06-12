#include "../include/BattleField.h"
#include <fstream>

/*---------------------------------------------------------------------------*/
void BattleField::init(){
    for(int nRow = 0; nRow < N; nRow++){
        for(int nCol = 0; nCol < N; nCol++){
            BF[nRow][nCol] = water;
        }
    }
    aoBattleships.clear();
}

/*---------------------------------------------------------------------------*/
void BattleField::save(const string& filename){
    std::ofstream oFile(filename);
    for(int i = 0; i < aoBattleships.size(); i++){
         oFile   << aoBattleships.at(i).getXInit() << " "
                 << aoBattleships.at(i).getYInit() << " "
                 << aoBattleships.at(i).getXEnd() << " "
                 << aoBattleships.at(i).getYEnd() << " "
                 << endl;
    }
}

/*---------------------------------------------------------------------------*/
bool BattleField::load(const string& filename){
    int xInit = 0, yInit = 0, xEnd = 0, yEnd = 0;

    //opening file
    std::ifstream iFile(filename);
    if (iFile.is_open()){
        
        // reinit field
        init();

        //uploading files
        while(!iFile.eof()){
            iFile >> xInit >> yInit >> xEnd >> yEnd;
            BattleShip oBS(xInit, yInit, xEnd, yEnd);
            insertShip(oBS);
        }
    }else{return false;}

    return true;
}

/*---------------------------------------------------------------------------*/
bool BattleField::insertShip(const BattleShip &bs) {
    if(isReady())               { return false; }
    if(!bs.isValid())           { return false; }    

    // save ship into field
    if(!fillCells(bs, ship))    { return false; }

    // add ship
    aoBattleships.push_back(bs);
    return true;
} 

/*---------------------------------------------------------------------------*/
bool BattleField::removeShip(const BattleShip &bs) {
    if(isEmpty())       { return false; }
    if(!bs.isValid())   { return false; }
    
    // find bs
    auto itBS = std::find(aoBattleships.begin(), aoBattleships.end(), bs);
    if(itBS == aoBattleships.end())   { 
        // NOT FOUND
        return false;
    }

    // remove from vector
    aoBattleships.erase(itBS);

    // remove from BF
    fillCells(bs, water);

    return true;
} 

/*---------------------------------------------------------------------------*/
void BattleField::show(){
    std::cout << "--------------------------------" << std::endl;
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
    std::cout << "--------------------------------" << std::endl;
}

/*---------------------------------------------------------------------------*/
bool BattleField::isReady(){
    return (getNumberOfShips() == NUM_SHIPS); 
}

/*---------------------------------------------------------------------------*/
bool BattleField::isEmpty(){
    return (aoBattleships.size() == 0);
}

/*---------------------------------------------------------------------------*/
bool BattleField::fillCells(const BattleShip &bs, State state){
    if(bs.getLength() > N)      { return false; }
    if(bs.getXInit() > N)       { return false; }
    if(bs.getXEnd() > N)        { return false; }
    if(bs.getYInit() > N)       { return false; }
    if(bs.getYEnd() > N)        { return false; }

    //get coords
    int nXInit = std::min(bs.getXInit()-1, bs.getXEnd()-1);
    int nYInit = std::min(bs.getYInit()-1, bs.getYEnd()-1);
    int nXEnd = std::max(bs.getXInit()-1, bs.getXEnd()-1);
    int nYEnd = std::max(bs.getYInit()-1, bs.getYEnd()-1);


    // verify if there is a ship
    if((state == ship) && isThereAShip(nXInit, nYInit, nXEnd, nYEnd)) { 
        return false; 
    }

    // horizontal
    for(int x = nXInit; x <= nXEnd; x++){
        BF[nYInit][x] = state;
    }

    // vertical
    for(int y = nYInit; y <= nYEnd; y++){
        BF[y][nXInit] = state;
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