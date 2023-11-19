#include "HumanPlayer.h"
#include <string>

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

Move HumanPlayer::getMove() {
    Move move;
    std::cout << "Enter row [0-9]: ";
    std::cin >> move.row;
    std::cout << "Enter column [A-J]: ";
    std::cin >> move.col;
    return move;      //! cannot use constructor with int and char Move(int,char) because constructor doesnt exist
}
