#include "include/BattleField.h"
#include <gtest/gtest.h>

class BFSupervisor{
    public:
        BattleField oBF;

        BFSupervisor(const BattleField& oBF): oBF(oBF){}

        bool isThereAShip(int nXInit, int nYInit, int nXEnd, int nYEnd){
            return oBF.isThereAShip(nXInit, nYInit, nXEnd, nYEnd);
        }
};

TEST(createShip, correctGenericShip){
    BattleShip oBS_1(1,1,1,1);
    EXPECT_TRUE(oBS_1.isValid());
    EXPECT_EQ(oBS_1.getLength(), 1);

    BattleShip oBS_2(1,1,1,2);
    EXPECT_TRUE(oBS_2.isValid());
    EXPECT_EQ(oBS_2.getLength(), 2);

    BattleShip oBS_3(4,2,6,2);
    EXPECT_TRUE(oBS_3.isValid());
    EXPECT_EQ(oBS_3.getLength(), 3);
}

TEST(createShip, wrongShip){
    BattleShip oBS_1(1,1,2,2);
    EXPECT_FALSE(oBS_1.isValid());
    
    BattleShip oBS_2(1,1,3,4);
    EXPECT_FALSE(oBS_2.isValid());

    BattleShip oBS_3(-1,1,2,2);
    EXPECT_FALSE(oBS_3.isValid());

    BattleShip oBS_4(0,0,0,0);
    EXPECT_FALSE(oBS_4.isValid());

    BattleShip oBS_5(-1,-1,-1,-1);
    EXPECT_FALSE(oBS_5.isValid());
}

TEST(createShip, assignmentOperator){
    BattleShip oBS_1(1,1,1,1);
    EXPECT_EQ(oBS_1.getXInit(), 1);
    
    BattleShip oBS_3(4,2,6,2);
    EXPECT_EQ(oBS_3.getXInit(), 4);

    oBS_1 = oBS_3;
    EXPECT_EQ(oBS_1.getXInit(), 4);
    EXPECT_EQ(oBS_1.getYInit(), 2);
    EXPECT_EQ(oBS_1.getXEnd(), 6);
    EXPECT_EQ(oBS_1.getYEnd(), 2);
}

TEST(createShip, compareOperator){
    BattleShip oBS_1(1,1,1,1);
    BattleShip oBS_3(4,2,6,2);
    EXPECT_EQ(oBS_1 == oBS_3, false);

    oBS_1 = oBS_3;
    EXPECT_EQ(oBS_1 == oBS_3, true);
}

TEST(insertBF, CorrectShip){
    BattleShip oBS(1,1,1,3);
    EXPECT_EQ(oBS.getLength(), 3);
    EXPECT_EQ(oBS.isValid(), true);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);    
    EXPECT_EQ(BFSupervisor(oBF).isThereAShip(0,0,0,2), true);


    BattleShip oBSMono(4,4,4,4);
    EXPECT_EQ(oBSMono.getLength(), 1);
    EXPECT_EQ(oBSMono.isValid(), true);
    oBF.insertShip(oBSMono);
    EXPECT_EQ(oBF.getNumberOfShips(), 2);  
    EXPECT_EQ(BFSupervisor(oBF).isThereAShip(3,3,3,3), true);
}

TEST(insertBF, WrongShip){
    BattleShip oBS(1,1,2,2);
    EXPECT_EQ(oBS.isValid(), false);

    BattleField oBF;
    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 0);
    EXPECT_EQ(oBF.isEmpty(), true);

    EXPECT_EQ(BFSupervisor(oBF).isThereAShip(0,0,1,1), false);
}

TEST(insertBF, WrongDimensionShip){
    BattleShip oBS(1,1,1,11);
    EXPECT_EQ(oBS.getLength(), 11);
    EXPECT_EQ(oBS.isValid(), true);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);
    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 0);
}

TEST(insertBF, SameShips){
    BattleShip oBS(1,1,1,3);
    EXPECT_EQ(oBS.getLength(), 3);
    EXPECT_EQ(oBS.isValid(), true);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);
    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);
    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);
}

TEST(insertBF, ShipWithCommonCells){
    BattleShip oBS_1(1,1,1,3);
    BattleShip oBS_2(3,3,1,1);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    oBF.insertShip(oBS_1);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);
    oBF.insertShip(oBS_2);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);
}

TEST(removeBF, correctBS){
    BattleShip oBS_1(1,1,1,3);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    oBF.insertShip(oBS_1);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);

    bool bRes = oBF.removeShip(oBS_1);
    EXPECT_EQ(bRes, true);
    EXPECT_EQ(oBF.getNumberOfShips(), 0);
}

TEST(removeBF, wrongBS){
    BattleShip oBS_1(1,1,1,3);
    BattleShip oBS_2(4,2,6,2);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    oBF.insertShip(oBS_1);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);

    oBF.removeShip(oBS_2);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);
}

TEST(removeBF, emptyCase){
    BattleShip oBS_1(1,1,1,3);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    oBF.removeShip(oBS_1);
    EXPECT_EQ(oBF.isEmpty(), true);
}

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}