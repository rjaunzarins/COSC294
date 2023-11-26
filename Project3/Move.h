#ifndef MOVE_H
#define MOVE_H

struct Move {
    Move(int row, char col);        //! added new constructor
    Move() = default;               //! must add default --- remove when no longer used
    int getIndex();
    int row;
    char col;
};

#endif