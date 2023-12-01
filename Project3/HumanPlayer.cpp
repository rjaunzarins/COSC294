#include "HumanPlayer.h"
#include <string>

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

Move HumanPlayer::getMove() {
    Move move;
    bool validInput = false;
    while(!validInput) {
        std::cout << "Enter row and col [0-9][A-J]: ";
        if(std::cin >> move) {
            if((move.row >= 0 && move.row <= 9) && (move.col >= 65 && move.col <= 74)) { 
                validInput = true;
            }
            else{
                std::cout << "\nInvalid input. Try again.\n";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
        }
        else {
        std::cout << "\nInvalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return move;
}
