#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include "Move.h"
#include <string>

class Player {
    public:
        Player(const std::string&);
        virtual ~Player() { delete &playerBoard; }    //Why does Player have destructor? if because of board, wouldnt board use its own destructor?
        const std::string& getName() const;
        virtual Move getMove() = 0;
        Board& getBoard();
    private:
        std::string playerName;
        Board& playerBoard;
};

#endif