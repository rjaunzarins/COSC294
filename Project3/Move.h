#ifndef MOVE_H
#define MOVE_H
#include <iostream>

struct Move {
    Move(int row, char col);        //! added new constructor
    Move() = default;               //! must add default --- remove when no longer used
    int getIndex();
    int row;
    char col;
    friend std::istream& operator >>(std::istream& os, Move& move);
};


#endif