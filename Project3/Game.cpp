#include "Game.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

void Game::selectPlayers() {
    //Prompts the user for each of the two players for the type (human/computer) of the player.
    //For a human player the function also asks for the player's name. The function then creates
    //the objects for the players dynamically
    std::string name;
    char type;
    
    std::cout << "Enter player1 type [C,H]: ";              //! make helper function and use counter to dertermine play1 or 2
    std::cin >> type;
    if(type == 'H' || type == 'h') {    
        std::cout << "Player1 name: ";
        std::cin >> name;
        player1 = std::make_unique<Player>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player1 = std::make_unique<Player>(RandomPlayer());
    }
    std::cout << "\nPlayer1 is: " << player1->getName() << "\n";

    std::cout << "Enter player2 type [C,H]: ";              
    std::cin >> type;
    if(type == 'H' || type == 'h') {    
        std::cout << "Player2 name: ";
        std::cin >> name;
        player2 = std::make_unique<Player>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player2 = std::make_unique<Player>(RandomPlayer());
    }
    std::cout << "\nPlayer2 is: " << player1->getName() << "\n";
}

Player* Game::nextPlayer() const {    //! changed the return from Player* to uniqueptr
    Player* temp1 = player1.get();
    Player* temp2 = player2.get();
    return temp1;
    //std::unique_ptr<Player>
    //return std::move(player1);
}

bool Game::isRunning() const {
    return false;                                       //!default setting to compile
}

void Game::play() {

}

void Game::announceWinner() {

}