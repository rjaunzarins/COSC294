#ifndef MOVE_H
#define MOVE_H
#include <iostream>

struct Move {
    Move(int row, char col);        
    Move() = default;              
    int getIndex();
    int row;
    char col;
    friend std::istream& operator >>(std::istream& os, Move& move);
};


#endif