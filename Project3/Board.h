#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Move.h"

enum class EnemyPiece { HIT, MISS, EMPTY };

enum class PlayerPiece { AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY };

class Board {   //Shouldnt board have destructor if arrays are dynamic?
    public:
        Board();
        void reset();
        void makeMove(Move, bool);
        bool isLegal(Move);
        friend std::ostream& operator <<( std::ostream&, const Board&);
    private:
        static constexpr size_t boardSize = 10;
        PlayerPiece pBoard[boardSize];  //WTF is going on with the boards? 
        EnemyPiece eBoard[boardSize];   //How does enemypiece have only hit miss empty?
         
};

#endif