/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Player's Move.
*/

#include "Move.h"
#include <iostream>

Move::Move(int row, char col) : row(row), col(col) {}

int Move::getIndex() {
	return (row * 10) + (col - 65);												//65 = 'A'
}


std::istream& operator>>(std::istream& inStream, Move& move) {					//invalid input compensated for elsewhere [ HumanPlayer::getMove() ]
	inStream >> move.row >> move.col;
	move.col = toupper(move.col);												//change lowercase to uppercase for validation/implementation purposes
	return inStream;
}