/*---------------------------------------------------------------------------*/
/*
* @file BattleField.h
* @author Vittorio <tiozzovittorio25@gmail.com>
* @brief A class to handle BattleField
*/
/*---------------------------------------------------------------------------*/

#include "BattleShip.h"

#include <string>
using namespace std;

/*---------------------------------------------------------------------------*/
class BattleField {
private:
    enum State: int{
        water=0,
        ship=1
    };

    static const int N = 10;
    State BF[N][N];

public:
    explicit inline BattleField(){}
    inline ~BattleField(){}

public:    
    void init(); // tutto water
    void save(const string& filename);
    bool load(const string& filename);
    bool insertShip(const BattleShip& bs);
    bool removeShip(const BattleShip& bs);
};

