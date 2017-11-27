/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * MovesEvaluator Class.
 *
 * This class will evaluate available moves for given board and player turn.
 *
 */

#ifndef UNTITLED_MOVESEVALUATOR_H
#define UNTITLED_MOVESEVALUATOR_H

//----------INCLUDING----------
#include <vector>
#include "../Board/Board.h"
#include "../Board/Cell.h"

class MovesEvaluator {
public:
    //In-Game Use
    virtual vector<CellIndex>   evaluateAvailableMoves(Board* gb,
                                                       Cell playerColor) const;
};

#endif //UNTITLED_MOVESEVALUATOR_H