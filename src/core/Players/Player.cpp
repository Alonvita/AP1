/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * Player Class.
 *
 * Players will hold their own values and make moves as raw strings. Those
 *  strings will be managed by the TurnsManager.
 */

//----------INCLUDING----------
#include "Player.h"

//----------Initializer List----------
/*
 * Player() Constructor.
 */
Player::Player(): value(BLACK) {
    this->gameBoard = 0;
}

//----------PUBLIC FUNCTIONS----------
/*
 * Player(Cell c) Constructor.
 *
 * @param c Cell - the player's color
 */
Player::Player(Cell c): value(c) {
    this->gameBoard = 0;
}

/*
 * Player(Cell c, Board* gb) Constructor.
 *
 * @param c Cell - the player's color
 * @param gb Board -- the game's board
 */
Player::Player(Cell c, Board* gb): value(c), gameBoard(gb) {}


/*
 * getValue().
 *
 * return Cell -- the color of the player
 */
Cell Player::getValue() const{
    return value;
}