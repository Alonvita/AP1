/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * AI Class.
 *
 * An AI is a computer that will serve as a second player. It will
 *  evaluate it's best moves to make and send them as a string to
 *  the TurnsManager.
 *
 */

#ifndef AI_H_
#define AI_H_

//----------INCLUDING----------
#include <string>
#include <iostream>
#include <unistd.h>
#include "../Board/Cell.h"
#include "../GameLogic/MovesEvaluator.h"
#include "Player.h"

//----------DEFINITIONS----------
#define INT_MAX 2147483647
#define AI_COLOR (Cell) Player::getValue()
#define PLAYER_COLOR (Cell) !AI_COLOR
#define AI_SENTENCES (string[]) { "You're making it easy on me!", \
                                  "You must be joking...",        \
                                  "Mmm... let me think",          \
                                  "Oh you got me there...",       \
                                  "Over ma dead body!",           \
                                  "That one really does it..." }

using namespace std;

class AI : public Player, public MovesEvaluator {
public:
    //----------PUBLIC FUNCTIONS----------
    // Initialize
    explicit            AI(Board* gameBoard);

    // In-Game Use
    virtual CellIndex   makeAMove(vector<CellIndex> aMoves)         const;

private:
	// Utility
    int                 calculatePotential(
                            Board *gb, vector<CellIndex> vec)       const;

    // Print
    void                printBestMove(CellIndex bMove)              const;
};

#endif /* AI_H_ */
