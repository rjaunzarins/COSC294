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
        player1 = std::make_unique<HumanPlayer>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player1 = std::make_unique<RandomPlayer>(RandomPlayer());
    }
    std::cout << "\nPlayer1 is: " << player1->getName() << "\n";
    //std::cout << player1->getBoard() << "\n";   //!

    std::cout << "Enter player2 type [C,H]: ";              
    std::cin >> type;
    if(type == 'H' || type == 'h') {    
        std::cout << "Player2 name: ";
        std::cin >> name;
        player2 = std::make_unique<HumanPlayer>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player2 = std::make_unique<RandomPlayer>(RandomPlayer());
    }
    std::cout << "\nPlayer2 is: " << player2->getName() << "\n";        //!
    //std::cout << player1->getBoard() << "\n";   //!
}

Player* Game::nextPlayer() const { 
    return (currentPlayer == player1.get()) ? player2.get() : player1.get();
}


//Check players boards to see if there is a winner
//Loop through EnemyPiece board to see if there are 17 hits on the board (this means all ships have been hit)
bool Game::isRunning() const {
    std::cout << "isRunning - 1\n";
    size_t count = 0;
    for (size_t i = 0; i < 100; i++) {
        
        std::cout << "isRunning - 2\n";

        if(player1->getBoard().getEnemyBoard()[i] == EnemyPiece::HIT) {           //!! This is causing the error // Was set to EnemyPiece::EMPTY
            
            std::cout << "isRunning - 3\n";

            ++count;
            std::cout << "Count: " << count << "\n";
        }
        std::cout << "isRunning - 4\n";
    }  

    std::cout << "isRunning - 5\n";
    return (count < 17) ? true : false; //! changed
}

// EnemyPiece& Game::getEnemyPiece(std::unique_ptr<Player> player, size_t index) {
//     return player->getBoard().getEnemyBoard()[index];
// }


void Game::play() {
    std::cout << "Play - 1\n";
    while(isRunning()) {
        std::cout << "Play - 2\n";

        //Display board
        std::cout << player1->getBoard() << "\n";       //!Changed to player1
        
        std::cout << "Play - 3\n";
        //pass to function
        if(currentPlayer == player1.get()) {
            std::cout << "Player 1: \n";
            player1->getBoard().makeMove(currentPlayer->getMove(), player2->getBoard());      //!Removed .get() changed to player1
        
        std::cout << "Play - 4\n";

        }
        else {
            std::cout << "Player 2: \n";
            player2->getBoard().makeMove(currentPlayer->getMove(), player1->getBoard());      //!Removed .get() changed to player2
        
        std::cout << "Play - 5\n";
        }
        std::cout << "Play - 6\n";
        currentPlayer = nextPlayer();
        std::cout << "Play - 7\n";
    }
}


void Game::announceWinner() {
    //Print the winner
    if(!isRunning()) {
        std::cout << "The winner is: " << currentPlayer->getName();     //!
        currentPlayer = nullptr;
    }
}