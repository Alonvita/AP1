/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * MovesEvaluator Class.
 *
 * This class will evaluate available moves for given board.
 *
 */

//----------INCLUDING----------
#include "MovesEvaluator.h"

//----------PUBLIC FUNCTIONS----------

vector<CellIndex> MovesEvaluator::
            evaluateAvailableMoves(Board* gb, Cell playerColor) const {
    //Local Variables
    vector<CellIndex> cellsInUse = gb->getCellsInUse();
    vector<CellIndex>::iterator it = cellsInUse.begin();
    vector<CellIndex> availableMoves;

    //Itter over cellsInUse
    while(it != cellsInUse.end()) {
        //Inner Loop Variables
        Cell currentCell = gb->getBoardCell((*it).index[0],(*it).index[1]);

        //Check if cell's value is OPPOSITE to the playing player's value
        if((currentCell == WHITE && playerColor == BLACK)
           || (currentCell == BLACK && playerColor == WHITE)) {
            //get cell's empty neighbors
            vector<CellIndex> emptyNeighbors = gb->getEmptyNeighbors(*it);
            vector<CellIndex>::iterator it = emptyNeighbors.begin();

            //For each neighbor -> check that it has potential
            while(it != emptyNeighbors.end()) {

                //create potential vector
                vector<CellIndex> cellPotential =
                        gb->getCellPotentialAsVector(*it, playerColor);

                //Cell has potential and therefore an available move!
                if(!cellPotential.empty()) {
                    //Reserve place for the vector
                    availableMoves.push_back(*it);
                }

                ++it;
            }
        }
        ++it;
    }
    //Clear Duplicates
    clearDuplicatesValues(&availableMoves);

    return availableMoves;
}