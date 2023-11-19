#include <iostream>
#include "Board.h"
#include "Move.h"

//Default constructor that initializes the board by calling the member 
//function reset(). 
Board::Board() : playerBoard(new PlayerPiece[100]), enemyBoard(new EnemyPiece[100]) {
    reset();
}

Board::~Board() {
    delete [] playerBoard;
    playerBoard = nullptr;
    delete [] enemyBoard;
    enemyBoard = nullptr;
}

//Erases all pieces from the board (i.e. sets them to Empty); then randomly 
//places the 5 ship types within the player pieces' array
void Board::reset() {
    for(size_t i = 0; i < 100; ++i) {    //! Change 100 to size
        playerBoard[i] = PlayerPiece::EMPTY;
        enemyBoard[i] = EnemyPiece::EMPTY;
    }
}

//Executes the move indicated by the first function parameter; the second is true 
//if it is the player's move, and false if it was the enemy's move (i.e., this 
//parameter indicates which array to update).
void Board::makeMove(Move move, bool isPlayer) {

}

//Retuns false if out of bounds of the board, or if the Move has already been done 
//by checking the enemy's board.
bool Board::isLegal(Move) {
    return false; //!default return for compiling
}

//Displays both the boards to the specified stream
std::ostream& operator <<(std::ostream& outStream, const Board& board) {
    outStream << "-- PLAYER BOARD --\n";
    outStream << "-------------------------------------------------\n";
    for(int i = 0; i < 10; ++i) { 
        for(int j = 0; j < 10; ++j) {
            outStream << "| " << static_cast<int>(board.playerBoard[(10 * i)+j]) << " ";
        }
        outStream << "\n-------------------------------------------------\n";
    }
    outStream << "\n";

    outStream << "-- ENEMY BOARD --\n";
    outStream << "-------------------------------------------------\n";
    for(int i = 0; i < 10; ++i) { 
        for(int j = 0; j < 10; ++j) {
            outStream << "| " << static_cast<int>(board.enemyBoard[(10 * i)+j]) << " ";
        }
        outStream << "\n-------------------------------------------------\n";
    }
    outStream << "\n";
    return outStream;
}