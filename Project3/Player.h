#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include "Move.h"
#include <string>

class Player {
    public:
        Player(const std::string&);                     //Should this be inlined?
        virtual ~Player() = default;                    //Should this be implemented? Why does Player have destructor? if because of board, wouldnt board use its own destructor?
        const std::string& getName() const { return playerName; }
        virtual Move getMove() = 0;                   //Pure virtual //! doesnt work with = 0; removed and added {} for compilation
        Board& getBoard() { return playerBoard; }
    private:
        std::string playerName;
        Board playerBoard;
};

#endif