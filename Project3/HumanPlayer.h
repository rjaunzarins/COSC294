#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include <string>

class HumanPlayer : public Player {
    public:
        HumanPlayer(const std::string&);
        const std::string& getName() const;
        Move getMove() override;
        friend std::ostream& operator>>(std::ostream& os, HumanPlayer& player);
    private:
};

#endif 