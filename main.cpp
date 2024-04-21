#include <iostream>
#include "function.h"

using namespace std;

int main() {
    insertBattleShip(battleField, 1, 1, 4, horizontalRight);
    insertBattleShip(battleField, 6, 5, 3, horizontalLeft);
    insertBattleShip(battleField, 3, 4, 2, horizontalRight);
    insertBattleShip(battleField, 2, 5, 1, verticalOn);
    insertBattleShip(battleField, 1, 2, 3, horizontalRight);
    insertBattleShip(battleField, 9, 6, 2, verticalBelow);
    makeTable();
    ciao
    return 0;
}