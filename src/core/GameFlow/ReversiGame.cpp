/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * ReversiGame Class.
 *
 * The ReversiGame class is in charge of starting and ending a game.
 */

#include "ReversiGame.h"

//----------Initializer List----------
/*
 * ReversiGame(Board* gb) Constructor.
 *
 * @param gb Board* -- a reference to the game's board.
 */
ReversiGame::ReversiGame(int boardType) {
    gameBoard = new Board(boardType);
    initializeTurnsManager();
}

//----------DESTRUCTORS----------
/*
 * ~ReversiGame().
 */
ReversiGame::~ReversiGame() {
    delete manager;
}

//----------INITIALIZING FUNCTIONS----------
/* initializeTurnsManager().
 *
 * This function will scan a number of players from the player and create the
 *  turns manager accordingly.
 */
void ReversiGame::initializeTurnsManager() {
    //Local Variables
    int numberOfPlayers;

    do {
        cout << "Please choose one of the next options:" << endl
             << "Player vs. PC: 1" << endl << "Player vs. Player: 2" << endl;
        cin >> numberOfPlayers;
    } while(!(0 < numberOfPlayers && numberOfPlayers < 3));

    manager = new TurnsManager(numberOfPlayers, gameBoard);
}

//----------PUBLIC FUNCTIONS----------
//----------IN-GAME USE-----------
/* startGame().
 *
 * This function will start the game and handle the game flow.
 */
void ReversiGame::startGame() {
    // Print the board
    GAME_BOARD.printBoard();
    while((GAME_BOARD.getSpaceLeft())) {
        // Evaluate available moves for player
        MANAGER->evaluateAvailableMovesForThisTurn(this->gameBoard);

        // End turn if player has no available moves
        if(MANAGER->getAvailableMovesNum() == 0) {
            MANAGER->endTurn();
        } else {
            // Nested Functions explanation: moveMade (board) calls:
            //  1). nextMove (manager) -> CellIndex
            //  2). getCurrentPlayerColor (manager) -> Cell
            GAME_BOARD.moveMade(MANAGER->nextMove(),
                                MANAGER->getCurrentPlayerColor());
            MANAGER->endTurn();

            //Print the board
            GAME_BOARD.printBoard();
        }
    }
    endGame();
}

/* endGame().
 *
 * This function will end the game and call announceWinner().
 */
void ReversiGame::endGame() {
    //Ending announcement
    cout << "The game has ended!" << endl << endl;

    //Print board
    GAME_BOARD.printBoard();

    //Announce Winner
    announceWinner();
}

//----------UTILITY-----------

/* announceWinner().
 *
 * This function calculates the board's status and returns the winner.
 */
void ReversiGame::announceWinner() {
    //Local Variables
    int* scores = GAME_BOARD.evaluateFinalScore(); //get scores array
    int winnerScore;
    bool winner;

    if(scores[0] > scores[1]) {
        winnerScore = scores[0];
        winner = 0;
    }else if(scores[0] < scores[1]) {
        winnerScore = scores[1];
        winner = 1;
    }else{
      cout << "!WE HAVE A TIE!";
        return;
    }

    cout << "The winner is: " << generatePlayerName(winner) <<
         " with " << winnerScore << " points. Over " <<
         generatePlayerName(!winner) << " with " <<
         pow(GAME_BOARD.getSize(),2) - winnerScore << " points";

}

/* generatePlayerName(bool b).
 *
 * @param bool b -- a boolean representing true/false so that true is
 *                   white false is black.
 *
 * @return string representing player's name
 */
string ReversiGame::generatePlayerName(bool b) {
    if(b == 0) { return "WHITE"; }
    return "BLACK";
}