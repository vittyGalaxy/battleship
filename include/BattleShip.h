/*---------------------------------------------------------------------------*/
/*
* @file BattleShip.h
* @author Vittorio <tiozzovittorio25@gmail.com>
* @brief A simple class to handle battleship
*/
/*---------------------------------------------------------------------------*/

#include <cmath>
#include <algorithm>
#include <string>

/*---------------------------------------------------------------------------*/
class BattleShip {
private:
    int             xInit;
    int             yInit;
    int             xEnd;
    int             yEnd;
    bool            valid;
    std::string     name;

public:
    explicit inline BattleShip(int xInit, int yInit, int xEnd, int yEnd, std::string name = "")
        : xInit(xInit), yInit(yInit), xEnd(xEnd), yEnd(yEnd), valid(false), name(name)
    {
        valid = checkPositiveValues() && checkIsNotDiagonal();
    }

    BattleShip(const BattleShip& oB)
        :   xInit(oB.getXInit()), 
            yInit(oB.getYInit()), 
            xEnd(oB.getXEnd()), 
            yEnd(oB.getYEnd()), 
            name(oB.getName()), 
            valid(oB.isValid())
    { }

    BattleShip& operator=(const BattleShip& oB){
        xInit   = oB.getXInit();
        yInit   = oB.getYInit();
        xEnd    = oB.getXEnd();
        yEnd    = oB.getYEnd();
        name    = oB.getName();
        valid   = checkPositiveValues() && checkIsNotDiagonal();
        return *this;
    }

    inline bool operator==(const BattleShip& oB) const {
        return ((oB.getXInit()   == xInit)    && 
                (oB.getXEnd()    == xEnd)     && 
                (oB.getYInit()   == yInit)    && 
                (oB.getYEnd()    == yEnd));
    }

    inline ~BattleShip(){}

public:
    inline int getLength() const{
        return std::max<int>(std::abs(xInit - xEnd), std::abs(yInit - yEnd)) + 1;
    }

    inline bool isValid() const{
        return valid;
    }

    inline int getXInit() const{
        return xInit;
    }

    inline int getYInit() const{
        return yInit;
    }

    inline int getXEnd() const{
        return xEnd;
    }

    inline int getYEnd() const{
        return yEnd;
    }
    inline std::string getName() const{
        return name;
    }

private:
    inline bool checkPositiveValues(){
        if(xInit <= 0 || xEnd <= 0 || yInit <= 0 || yEnd <= 0){
            return false;
        }else{
            return true;
        }
    }

    inline bool checkIsNotDiagonal(){
        return (xInit != xEnd) && (yInit != yEnd) ? false : true;
    }
};