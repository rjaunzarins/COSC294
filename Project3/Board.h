#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Move.h"
#include <random>

enum class EnemyPiece { HIT, MISS, EMPTY };

enum class PlayerPiece { AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY, DAMAGED };         //* Add PlayerPiece::DAMAGED to show Player when his ships are hit

class Board {   //Shouldnt board have destructor if arrays are dynamic?
    public:
        Board();
        ~Board();
        void reset();
        void makeMove(Move, Board&);                  //! bool isPlayer was changed to const Board& enemyPlayer otherwise we would not have access to see if hit or miss
        bool isLegal(Move);
        EnemyPiece* getEnemyBoard() const noexcept;
        PlayerPiece* getPlayerBoard() const noexcept;
        const EnemyPiece& operator[](size_t index) { return enemyBoard[index]; }
        friend std::ostream& operator <<( std::ostream&, const Board&);
    private:
        void initializePlayerboard();
        void setBoatType(size_t, size_t&, PlayerPiece&);
        void placeShips(size_t, std::mt19937_64&); 
        bool isShipPlacementLegal(Move&, bool, size_t, size_t);
        void makePlacement(PlayerPiece&, bool, size_t, size_t);
        bool isLegalPlacement(Move move);
        PlayerPiece *playerBoard;  //WTF is going on with the boards? 
        EnemyPiece *enemyBoard;   //How does enemypiece have only hit miss empty?      
};

#endif