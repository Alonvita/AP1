/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TestBoard Class.
 *
 * This unit will handle all of the Participant tests.
 *
 */

//----------INCLUDING----------
#include <gtest/gtest.h>
#include "../src/core/Board/Board.h"
#include "../src/core/Players/Participant.h"

class TestParticipant : public testing::Test {
public:
    TestParticipant() {};

protected:
    Participant* par;
};

TEST_F(TestParticipant, TestParticipant_Init_Test) {
    // Local variables
    par = new Participant(WHITE);

    ASSERT_EQ(par->getValue(), WHITE);

    par = new Participant(BLACK);

    ASSERT_EQ(par->getValue(), BLACK);
}

TEST_F(TestParticipant, TestParticipant_String_To_Vec_Test) {
    // Local variables
    par = new Participant(WHITE);

    string str = "3,4";
    vector<string> vec = par->stringToVector(str);

    // Check string dissolving
    ASSERT_EQ(vec[0], "3");
    ASSERT_EQ(vec[1], "4");
}

TEST_F(TestParticipant, TestParticipant_String_To_Move_Test) {
    // Local variables
    par = new Participant(WHITE);

    string str = "3,4";
    CellIndex move = par->stringToPlayerMove(str);

    ASSERT_EQ(move.index[0], 2);
    ASSERT_EQ(move.index[1], 3);
}