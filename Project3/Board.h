#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Move.h"

enum class EnemyPiece { HIT, MISS, EMPTY };

enum class PlayerPiece { AIRCRAFT = 5, BATTLESHIP = 4, CRUISER = 3, SUBMARINE = 3, PATROL = 2, EMPTY = 0 };

class Board {   //Shouldnt board have destructor if arrays are dynamic?
    public:
        Board();
        ~Board();
        void reset();
        void makeMove(Move, bool);
        bool isLegal(Move);
        friend std::ostream& operator <<( std::ostream&, const Board&);
    private:
        
        PlayerPiece *playerBoard;  //WTF is going on with the boards? 
        EnemyPiece *enemyBoard;   //How does enemypiece have only hit miss empty?      
};

#endif