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

/*---------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------*/
TEST(insertBF, CorrectShip){
    BattleShip oBS(1,1,1,3);
    EXPECT_EQ(oBS.getLength(), 3);
    EXPECT_EQ(oBS.isValid(), true);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    //oBF.show();

    oBF.insertShip(oBS);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);    
    EXPECT_EQ(BFSupervisor(oBF).isThereAShip(0,0,0,2), true);

    //oBF.show();

    BattleShip oBSMono(4,4,4,4);
    EXPECT_EQ(oBSMono.getLength(), 1);
    EXPECT_EQ(oBSMono.isValid(), true);
    oBF.insertShip(oBSMono);
    EXPECT_EQ(oBF.getNumberOfShips(), 2);  
    EXPECT_EQ(BFSupervisor(oBF).isThereAShip(3,3,3,3), true);
    
    //oBF.show();
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

    BattleShip oBSWrong(1,10,1,11);
    bool bRes = oBF.insertShip(oBSWrong);
    EXPECT_EQ(bRes, false);
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

/*---------------------------------------------------------------------------*/
TEST(removeBF, correctBS){
    BattleShip oBS_1(1,1,1,3);

    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    //oBF.show();

    oBF.insertShip(oBS_1);
    EXPECT_EQ(oBF.getNumberOfShips(), 1);

    //oBF.show();

    bool bRes = oBF.removeShip(oBS_1);

    //oBF.show();
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

/*---------------------------------------------------------------------------*/
TEST(saveLoadBF, ships){
    // ships to be saved
    BattleShip oBS_1(1,1,1,3);
    BattleShip oBS_2(2,3,2,5);
    BattleShip oBS_3(7,7,7,9);
    BattleShip oBS_4(2,2,2,2);
    BattleShip oBS_5(8,1,6,1);

    // BF
    BattleField oBF;
    oBF.insertShip(oBS_1);
    oBF.insertShip(oBS_2);
    oBF.insertShip(oBS_3);

    // check
    EXPECT_EQ(oBF.getNumberOfShips(), 3);
    oBF.save("bella.txt");
    EXPECT_EQ(oBF.getNumberOfShips(), 3);

    // New Battlefield
    BattleField oBF_2;
    EXPECT_EQ(oBF_2.getNumberOfShips(), 0);
    bool bRes = oBF_2.load("bella.txt");
    EXPECT_EQ(bRes, true);
    EXPECT_EQ(oBF_2.getNumberOfShips(), 3);

    // wrong filename
    bRes = oBF_2.load("bell");
    EXPECT_EQ(bRes, false);

    // New Battlefield
    BattleField oBF_3;
    oBF_3.insertShip(oBS_4);
    oBF_3.insertShip(oBS_5);
    EXPECT_EQ(oBF_3.getNumberOfShips(), 2);
    oBF_3.load("bella.txt");
    EXPECT_EQ(oBF_3.getNumberOfShips(), 3);
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseOne){
    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    for(int nI = 1; nI <= 10; nI++){
        BattleShip oBS(nI, nI, nI, nI);
        
        oBF.insertShip(oBS);
        EXPECT_EQ(oBF.getNumberOfShips(), 1);
        EXPECT_EQ(oBF.getCell(nI-1, nI-1), BattleField::ship);

        oBF.removeShip(oBS);
        EXPECT_EQ(oBF.getNumberOfShips(), 0);
        EXPECT_EQ(oBF.getCell(nI-1, nI-1), BattleField::water);
    }
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseTwoVertical){
    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    ---
    |X|
    |X|
    ---
    */

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI, nJ+1);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI+1, nJ, nI, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);

                // EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseTwoHorizontal){
    BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    |X X|
    */

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI+1, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI+1, nJ, nI, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                // oBF.show();
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}


/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseThreeVertical){
     BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    ---
    |X|
    |X|
    |X|
    ---
    */

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI, nJ+2);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ+2, nI, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseThreeHorizontal){
     BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    -------
    |X X X|
    -------
    */

       for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI+2, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseFourHorizontal){
     BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    ---------
    |X X X X|
    ---------
    */

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI+3, nJ);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+2), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ-1, nI+2), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/
TEST(InsertRemove_IT, caseFourVertical){
     BattleField oBF;
    EXPECT_EQ(oBF.getNumberOfShips(), 0);

    /*
    ---
    |X|
    |X|
    |X|
    |X|
    ---
    */

    for(int nI = 1; nI <= 10; nI++){
        for(int nJ = 1; nJ <= 10; nJ++){
            BattleShip oBS(nI, nJ, nI, nJ+3);

            bool bRes = oBF.insertShip(oBS);
            if(bRes){
                EXPECT_EQ(oBF.getNumberOfShips(), 1);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::ship);
                EXPECT_EQ(oBF.getCell(nJ+2, nI-1), BattleField::ship);

                oBF.removeShip(oBS);
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
                EXPECT_EQ(oBF.getCell(nJ-1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ+1, nI-1), BattleField::water);
                EXPECT_EQ(oBF.getCell(nJ+2, nI-1), BattleField::water);
            }else{
                EXPECT_EQ(oBF.getNumberOfShips(), 0);
            }
        }
    }
}

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}