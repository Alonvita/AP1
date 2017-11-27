/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the Board tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Board/Board.h"

class BoardTest : public testing::Test {
public:
    BoardTest() {};

protected:
    Board* b;
};

TEST_F(BoardTest, BoardTest_Board_Initialization_Test) {
    // Check default type size
    b = new Board(0);
    ASSERT_EQ(b->getSize(), 8)
                        << "Default Board type size is: "
                        << b->getSize() << " by " << b->getSize() << endl;

    // Check size and cells in use vector
    for(int i = 1; i <= 3; ++i) {
        b = new Board(i);
        ASSERT_EQ(b->getSize(), (2 + i) * 2)
                        << "Board type " << i << " size is: "
                        << b->getSize() << " by " << b->getSize() << endl;
    }
}

TEST_F(BoardTest, BoardTest_Board_Test_CellsInUse_Test) {
    for(int type = 0; type < 4; type++) {
        // Local Helper Variables
        b = new Board(type);
        vector<CellIndex> cellsInUse = b->getCellsInUse();
        int p = 1;
        int q = 1;

        // Check that all 4 cells are in use
        for (int i = 0; i < cellsInUse.size(); ++i) {
            // Inner loop local variables
            int rowCheck = b->getSize() / 2 - p;
            int colCheck = b->getSize() / 2 - q;
            int rowAssert = cellsInUse[i].index[0];
            int colAssert = cellsInUse[i].index[1];

            ASSERT_EQ(rowAssert, rowCheck)
                        << "index " << i << " at cellInUse"
                                "[" << 0 << "] is wrong: "
                        << cellsInUse[0].index[0] << endl;
            ASSERT_EQ(colAssert, colCheck)
                        << "index " << i << " at cellInUse"
                                "[" << 1 << "] is wrong: "
                        << cellsInUse[0].index[1] << endl;

            p ^= i % 2;
            q ^= 1;
        }
    }
}

TEST_F(BoardTest, BoardTest_Board_Initialized_Num_Of_Available_Moves_Test) {
    // Local Variables
    b = new Board();

    ASSERT_EQ(b->getAvailableSlots(), 4);
}

TEST_F(BoardTest, BoardTest_Board_Cell_On_Board__Test) {
    // Local variables
    b = new Board();

    ASSERT_EQ(b->cellOnBoard(b->getSize() / 2, b->getSize() / 2), 1)
                        << "In case this test fails AND Move_Made_Test fails,"
                                " check this test first!" << endl;
}

TEST_F(BoardTest, BoardTest_Board_Move_Made_Board_Test) {
    // Local Variables
    b = new Board();
    int size = b->getSize();
    vector<CellIndex> cellAddedCheck;

    // Legal Cell
    CellIndex cellToAdd = (CellIndex){ size/2 + 2, size/2 };
    b->moveMade(cellToAdd, WHITE);
    ASSERT_EQ(b->cellOnBoard(cellToAdd.index[0], cellToAdd.index[1]), 1)
                        << "If this fails and Cell_On_Board_Test DOESN'T, "
                                "the problem is HERE" << endl;

    // Illegal Cell
    cellToAdd = (CellIndex){ size , size };
    b->moveMade(cellToAdd, WHITE);
    ASSERT_EQ(b->cellOnBoard(cellToAdd.index[0], cellToAdd.index[1]), 0);
}

TEST_F(BoardTest, BoardTest_Get_Cell_Color_Test) {
    // Local helper variables
    b = new Board();
    int size = b->getSize();

    ASSERT_EQ(b->getBoardCell(size / 2, size / 2), WHITE);
}

TEST_F(BoardTest, BoardTest_Board_Set_Cell_Test) {
    // Local helper variables
    b = new Board();
    int size = b->getSize();

    b->setCell(size / 2 ,size / 2 , OUT_OF_BOUNDS);

    ASSERT_EQ(b->getBoardCell(size /2, size / 2), OUT_OF_BOUNDS)
                        << "If this test fails, check that "
                                "Get_Cell_Color_Test passed.";
}