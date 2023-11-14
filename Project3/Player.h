#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include <string>

class Player {
    public:
        Player(const std::string&);
        virtual ~Player() { delete &board; }    //Why does Player have destructor? if because of board, wouldnt board have its own destructor?
        const std::string& getName() const;
        Move getMove();
        Board& getBoard();
    private:
        std::string name;
        Board& board;
};

#endif