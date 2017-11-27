/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the Turns Manager tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Board/Board.h"
#include "../src/core/GameLogic/TurnsManager.h"

class TestTurnsManager : public testing::Test {
public:
    TestTurnsManager() {};

protected:
    TurnsManager* tm;
};

TEST_F(TestTurnsManager, TestTurnsManager_Initialization_Test) {
    // Local helper variables
    Board* b = new Board(2);
    tm = new TurnsManager(1, b);

    ASSERT_EQ(tm->getCurrentPlayerColor(), WHITE);
}

TEST_F(TestTurnsManager, TestTurnsManager_End_Turn_Test) {
    // Local helper variables
    Board* b = new Board(2);
    tm = new TurnsManager(1, b);

    tm->endTurn();

    ASSERT_EQ(tm->getCurrentPlayerColor(), BLACK);
}

