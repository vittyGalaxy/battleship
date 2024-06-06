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
bool BattleField::insertShip(const BattleShip &bs)
{
    
} 

/*---------------------------------------------------------------------------*/
bool BattleField::removeShip(const BattleShip &bs)
{
    
} 
