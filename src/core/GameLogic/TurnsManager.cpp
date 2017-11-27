/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * TurnsManager Class.
 *
 * The TurnsManager class is in charge of everything that is linked to the
 *  turns of the games: availability, turn validity and who's turn it is.
 */

//----------INCLUDING----------
#include "TurnsManager.h"

//----------Initialization list----------
/*
 * TurnsManager() Constructor.
 */
TurnsManager::TurnsManager(): playerTurn((Cell) 0) {
    Board* gb = new Board(2);
    initializeOneParticipant(gb);
}
/*
 * TurnsManager(int numPlayers, Board* gb) Constructor.
 */
TurnsManager::TurnsManager(int numPlayers, Board* gb): playerTurn((Cell) 0) {
    if (numPlayers == 2)
        initializeTwoParticipants();

    initializeOneParticipant(gb);
}

//----------DESTRUCTORS----------
/*
 * ~TurnsManager().
 */
TurnsManager::~TurnsManager() {
    //Remove both players
    vector<Player*> vec;
    players.swap(vec);
}

//----------GETTERS & SETTERS----------

/*
 * getAvailableMovesNum().
 *
 * @return int -- the number of available moves for this turn.
 */
int TurnsManager::getAvailableMovesNum() {
    return (int) availableMoves.size();
}

/*
 * getCurrentPlayerColor().
 *
 * @return Cell -- current playing player's color
 */
Cell TurnsManager::getCurrentPlayerColor() {
    return ((Cell)this->playerTurn);
}

//----------Public Functions----------
/*
 * endTurn().
 *
 * This function will XOR the current player turn with 1 so that the turn is
 *  passed on to the next player.
 */
void TurnsManager::endTurn() {
    cout <<endl << "Turn has Ended" << endl;
    this->playerTurn = (Cell) this->playerTurn ^ 1;
}


/*
 * evaluateAvailableMovesForThisTurn(Board* gb).
 *
 * @param gb Board* -- the game's board.
 */
void TurnsManager::evaluateAvailableMovesForThisTurn(Board* gb) {
    //clear last turn's availableMoves, get new moves and shrink
    availableMoves.clear();
    availableMoves =
            MovesEvaluator::evaluateAvailableMoves(gb, (Cell)playerTurn);

    //Print
    //cout << callPlayerByName() << " player: it's your move." << endl;
    //printAvailableMoves();
}

/*
 * nextMove(int boardSize).
 *
 * @param boardSize int -- the board's size
 *
 * @return CellIndex* -- a reference to the move made as string holding a cell
 *  					 index as [row,col].
 */
CellIndex TurnsManager::nextMove() {
    //Local Variables
    CellIndex playerMove;

    do {
        playerMove = (*PLAYER).makeAMove(availableMoves);
    } while(!isMoveLegal(playerMove));

    return playerMove;
}

//----------INITIALIZATION FUNCTIONS----------
/*
 * initializeTwoParticipants().
 */
void TurnsManager::initializeTwoParticipants() {
    players.push_back(new Participant(WHITE));
    players.push_back(new Participant(BLACK));
}

/*
 * initializeParticipantAndAI().
 */
void TurnsManager::initializeOneParticipant(Board* gb) {
    players.push_back(new AI(gb));
    players.push_back(new Participant(BLACK));
}

//----------PRIVATE FUNCTIONS----------
/*
 * isMoveLegal(CellIndex cI).
 *
 * @param cI CellIndex -- a reference to struct holding cell's index
 * 						   as [row,col]
 *
 * @return true if the move is legal or false otherwise.
 */
bool TurnsManager::isMoveLegal(CellIndex cI) {
    //Check { -1,-1 } for bad input
    if(cI.index[0] == -1 && cI.index[1] == -1) {
        cout << "This move is illegal" << endl << endl;
        return false;
    }

    int playerMoveRow = (cI).index[0];
    int playerMoveCol = (cI).index[1];
    vector<CellIndex>::iterator it = this->availableMoves.begin();

    while(it != this->availableMoves.end()) {
        //Inner-Loop Variables
        int availableMoveRow = (*it).index[0];
        int availableMoveCol = (*it).index[1];

        //Check is the player's move matches any available moves
        if(playerMoveRow == availableMoveRow
           && playerMoveCol == availableMoveCol) {
            return true;
        }
        ++it; //Advance iterator
    }

    cout << "This move is illegal" << endl;
    return false;
}