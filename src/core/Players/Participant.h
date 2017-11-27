/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * Participant Class.
 *
 * A Participant is an out side user.
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_

//----------INCLUDING----------
#include <string>
#include <iostream>
#include <sstream>
#include "../Board/Cell.h"
#include "Player.h"

using namespace std;

class Participant : public Player {
public:
    //----------PUBLIC FUNCTIONS----------
    // Initialize
    explicit            Participant(Cell c);

    // In-Game Use
    virtual CellIndex   makeAMove(vector<CellIndex> aMoves) const;
    vector<string> 		stringToVector(string str) const;
    CellIndex 			stringToPlayerMove(string rawString) const;

private:
    // Utility
    string              callPlayerByName() const;

    // Print
    void                printAvailableMoves(vector<CellIndex> aMoves) const;
};

#endif /* PLAYER_H_ */
