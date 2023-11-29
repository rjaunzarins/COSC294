#include "HumanPlayer.h"
#include <string>

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

Move HumanPlayer::getMove() {
    Move move;
    bool validInput = false;
    while(!validInput) {
        std::cout << "Enter row and col [0-9][A-J]: ";
        if(std::cin >> move) {
            validInput = true;
        }
        else {
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return move;
}

// std::ostream& operator>>(std::ostream& os, HumanPlayer& player) {
//     os >> player.Player::setName();
//     return os;
// }