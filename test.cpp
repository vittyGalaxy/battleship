#include "include/BattleShip.h"
#include <gtest/gtest.h>

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

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}