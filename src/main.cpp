/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 */
#include "core/Board/Board.h"
#include "core/GameFlow/ReversiGame.h"

using namespace std;

#define RUN_GOOGLE_TESTS true


/*
 * main().
 */
int main(int argc, char* argv[]) {
    //Testing Unit
    if (RUN_GOOGLE_TESTS)
        ;

    //Local Main Variables
    int boardType;

    cout << "Hello and welcome to my Reversi Game. Please choose a board type:"
         << endl << "1: 6x6" << endl << "2: 8x8 (also default)" << endl <<
         "3: 10x10" << endl;
    cin >> boardType;

    //create game with given board size
    ReversiGame g(boardType);
    g.startGame();
}