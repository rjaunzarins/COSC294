#include "Move.h"
#include <iostream>

Move::Move(int row, char col) : row(row), col(col) {}

int Move::getIndex() {
    return (row * 10) + (static_cast<int>(col) - 65);
}