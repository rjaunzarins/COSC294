#ifndef MOVE_H
#define MOVE_H

struct Move {
    int getIndex();
    char convertToChar(int);   //! made for board class conversion
    int row;
    char col;
};

#endif