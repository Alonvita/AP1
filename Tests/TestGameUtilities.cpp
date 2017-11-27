/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the Utilities tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Utilities/GameUtilities.h"

class TestGameUtilities : public testing::Test {
public:
    TestGameUtilities() {};
};

TEST_F(TestGameUtilities, TestGameUtilities_Clear_Vec_From_Dups_Test) {
    // Local variables
    vector<CellIndex> vec;

    vec.push_back((CellIndex) { -1 , -1 });
    vec.push_back((CellIndex) { -1 , -1 });
    vec.push_back((CellIndex) { -1 , -1 });
    vec.push_back((CellIndex) { -1 , -1 });
    vec.push_back((CellIndex) { -1 , -1 });

    clearDuplicatesValues(&vec);

    ASSERT_EQ(vec.size(), 1);
}