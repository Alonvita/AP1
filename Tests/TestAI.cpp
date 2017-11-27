/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the AI tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Board/Board.h"
#include "../src/core/Players/AI.h"

class TestAI : public testing::Test {
public:
    TestAI() {};

protected:
    AI* ai;
};

TEST_F(TestAI, TestAI_TestAI_Initializaioin_Test) {
    // Local variables
    Board* b = new Board();
    ai = new AI(b);

    ASSERT_EQ(ai->getValue(), WHITE);
}

TEST_F(TestAI, TestAI_Make_Move_Evaluation) {
    // Local variables
    Board* b = new Board();
    ai = new AI(b);

    CellIndex moveMade =
            ai->makeAMove(ai->evaluateAvailableMoves(b, ai->getValue()));

    EXPECT_FALSE(moveMade.index[0] == -1);
    EXPECT_FALSE(moveMade.index[1] == -1);
}