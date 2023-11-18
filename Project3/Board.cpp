#include <iostream>
#include "Board.h"
#include "Move.h"

//Default constructor that initializes the board by calling the member 
//function reset(). 
Board::Board() {
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

}

//Executes the move indicated by the first function parameter; the second is true 
//if it is the player's move, and false if it was the enemy's move (i.e., this 
//parameter indicates which array to update).
void Board::makeMove(Move, bool) {

}

//Retuns false if out of bounds of the board, or if the Move has already been done 
//by checking the enemy's board.
bool Board::isLegal(Move) {
    return false; //default return for compiling
}

//Displays both the boards to the specified stream
std::ostream& operator <<( std::ostream& outStream, const Board& board) {
    return outStream;
}