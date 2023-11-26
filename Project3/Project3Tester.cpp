#include "Board.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Move.h"
#include "Player.h"
#include "RandomPlayer.h"

bool playAgain();


int main() {
    // do {
    //     // Board b;
    //     // std::cout << b << "\n";
    Game g;
    std::cout << "Point a\n";
    g.selectPlayers();
    std::cout << "Point b\n";
    g.play();
    std::cout << "Point c\n";
    // } while(playAgain());
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