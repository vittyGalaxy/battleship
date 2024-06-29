/*---------------------------------------------------------------------------*/
/*
* @file BattleField.h
* @author Vittorio <tiozzovittorio25@gmail.com>
* @brief A class to handle BattleField
*/
/*---------------------------------------------------------------------------*/

#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "BattleShip.h"

#include <vector>
#include <iostream>
#include <optional>
#include <memory>
#include <string>
using namespace std;

struct Point
{
    int x;
    int y;
};


/*---------------------------------------------------------------------------*/
class BattleField {
    friend class BFSupervisor;
public:
    enum State: int{
        water   = 0,
        ship    = 1
    };

    // consts
private:
    static const int N          = 10;
    static const int NUM_SHIPS  = 9;

    // attributes
private:
    State                            BF[N][N];
    std::vector<BattleShip>          aoBattleships;

    vector<vector<shared_ptr<BattleShip>>>      mpoBF;

public:
    explicit inline BattleField() : aoBattleships() {
        init();
    }

    inline ~BattleField(){}

public:    
    void    init();
    void    save(const string& filename);
    bool    load(const string& filename);
    bool    insertShip(const BattleShip& bs);
    bool    removeShip(const BattleShip& bs);
    bool    isReady();
    bool    isEmpty();
    void    show();

public:
    inline int getNumberOfShips() const {
        return aoBattleships.size();
    }

    inline State getCell(int nY, int nX){
        return BF[nY][nX];
    }

    inline optional<BattleShip> operator[] (const Point& point){
        if(mpoBF[point.y][point.x] == nullptr){
            return std::nullopt;
        }else{
            return make_optional(*mpoBF[point.y][point.x]);
        }
    }

private:
    bool fillCells(const BattleShip &bs, State eState);
    bool isThereAShip(int nXInit, int nYInit, int nXEnd, int nYEnd);
};

#endif // BATTLEFIELD_H