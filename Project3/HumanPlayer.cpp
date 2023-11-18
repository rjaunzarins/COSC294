#include "HumanPlayer.h"
#include <string>

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

Move HumanPlayer::getMove() {

    
    return Move(row,col);
}
