#include "Move.h"

Move::Move(int row, char col) : row(row), col(col) {}

int Move::getIndex() {
    return (row * 10) + (static_cast<int>(col) - 65);
}

std::istream& operator >>(std::istream& os, Move& move) {
    os >> move.row >> move.col;
    move.col = toupper(move.col);
    return os;
}