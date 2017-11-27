/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * Player Class.
 *
 * Players will hold their own values and make moves as raw strings. Those
 *  strings will be managed by the TurnsManager.
 *
 */

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

//----------INCLUDES----------
#include "../Board/Board.h"
#include "../Board/Cell.h"

class Player {
//----------PUBLIC CLASSES----------
public:
    // Initialize
    Player();
    explicit            Player(Cell c);
    explicit            Player(Cell c, Board* gb);

    //Getters & Setters
    Cell                getValue() const;

    // In-Game Use
   virtual CellIndex    makeAMove(vector<CellIndex> aMoves) const = 0;

//----------PRIVATE CLASSES----------
private:
    Cell                value;
protected:
    Board*              gameBoard;
};

#endif //UNTITLED_PLAYER_H
