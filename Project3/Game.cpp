#include "Game.h"
#include "HumanPlayer.h"

void Game::selectPlayers() {
    //Prompts the user for each of the two players for the type (human/computer) of the player.
    //For a human player the function also asks for the player's name. The function then creates
    //the objects for the players dynamically
    std::string name;
    char type;
    std::cout << "Enter player type [C,H]: ";
    std::cin >> type;
    if(type == 'H') {    
        std::cout << "Name: ";
        std::cin >> name;
        player1 = std::make_unique<Player>(HumanPlayer(name));
    }
}

std::unique_ptr<Player> Game::nextPlayer() const {  //! changed the return from Player* to uniqueptr
    return std::move(player1);
}

bool Game::isRunning() const {
    return false; //!default setting to compile
}

void Game::play() {

}

void Game::announceWinner() {

}