#include "Board.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Move.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"
#include "GameColour.h"

bool playAgain();
void printBattleship();

int main() {
    do {
        Game g;
        printBattleship();
        g.selectPlayers();
        g.play();
        g.announceWinner();
    } while(playAgain());
    //Player* h = new HumanPlayer("adsfasdf");
    //std::cout << "Name: " << h->getName() << "\n" << h->getBoard();
    // RandomPlayer r;
    // std::cout << r.getName();

}


bool playAgain() {
    char playAgain;
    std::cout << "Would you like to play again? (Y/N): ";
    std::cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y') {
        return true;
    }
    else {
        return false;
    }
}

void printBattleship() {
std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
std::cout << "      BattleShip Game\n";
std::cout << "                                         # #  ( )\n";
std::cout << "                                  ___#_#___|__\n";
std::cout << "                              _  |____________|  _\n";
std::cout << "                       _=====| | |            | | |==== _\n";
std::cout << "                 =====| |.---------------------------. | |====\n";
std::cout << "   <--------------------'   .  .  .  .  .  .  .  .   '--------------/\n";
std::cout << "    \\                                                             /\n";
std::cout << "     \\___________________________________________________________/\n";
std::cout << "  wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
std::cout << "   wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
}