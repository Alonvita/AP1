/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the Reversi Game tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Board/Board.h"
#include "../src/core/GameLogic/MovesEvaluator.h"

class TestMovesEvaluator : public testing::Test {
public:
    TestMovesEvaluator() {};

protected:
    MovesEvaluator me;
};

TEST_F(TestMovesEvaluator, TestMovesEvaluator_Available_Moves_Test) {
    // Local variables
    Board* b = new Board();
    int size = b->getSize();
    int row = (size / 2) - 2;
    int col [4] = {0, 1, -2, -1};
    vector<CellIndex> availableMoves =
            me.evaluateAvailableMoves(b, WHITE);

    // Test for White available Moves
    for (int i = 0; i < availableMoves.size(); ++i) {
        ASSERT_EQ(availableMoves[i].index[0], row);
        ASSERT_EQ(availableMoves[i].index[1], (size / 2) + col[i]);

        row++;
    }

    availableMoves = me.evaluateAvailableMoves(b, BLACK);
    row = (size / 2) - 2;
    for (int i = 0; i < availableMoves.size(); ++i) {
        ASSERT_EQ(availableMoves[i].index[0], row);
        ASSERT_EQ(availableMoves[i].index[1], (size / 2) + col[3 - i]);

        row++;
    }
}