/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * Cell Class.
 *
 * will be used to define CellIndex and Cell.
 *
 */

#ifndef CELL_H_
#define CELL_H_

//----------INCLUDING----------
#include <string>

using namespace std;

struct CellIndex { int index[2] ;};

enum Cell {
    WHITE,
    BLACK,
    EMPTY,
    OUT_OF_BOUNDS
};

#endif /* CELL_H_ */