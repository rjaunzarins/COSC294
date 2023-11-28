#include "Game.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"


void Game::selectPlayers() {
    //Prompts the user for each of the two players for the type (human/computer) of the player.
    //For a human player the function also asks for the player's name. The function then creates
    //the objects for the players dynamically
    std::string name;
    char type;
    
    //Player1
    std::cout << "\nEnter player1 type [C,H]: ";              //! make helper function and use counter to dertermine play1 or 2
    std::cin >> type;
    if(type == 'H' || type == 'h') {    
        std::cout << "Player1 name: ";
        std::cin >> name;
        player1 = std::make_unique<HumanPlayer>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player1 = std::make_unique<RandomPlayer>(RandomPlayer());
    }
    std::cout << "Player1 is: " << player1->getName() << "\n";


    //Player2
    std::cout << "\nEnter player2 type [C,H]: ";              
    std::cin >> type;
    if(type == 'H' || type == 'h') {    
        std::cout << "Player2 name: ";
        std::cin >> name;
        player2 = std::make_unique<HumanPlayer>(HumanPlayer(name));
    }
    else if(type == 'C' || type == 'c') {    
        player2 = std::make_unique<RandomPlayer>(RandomPlayer());
    }
    std::cout << "Player2 is: " << player2->getName() << "\n";        


    currentPlayer = player2.get();     //Assign first player to player1    
}

Player* Game::nextPlayer() const { 
    return (currentPlayer == player1.get()) ? player2.get() : player1.get();
}


//Check players boards to see if there is a winner
//Loop through EnemyPiece board to see if there are 17 hits on the board (this means all ships have been hit)
bool Game::isRunning() const {
    size_t count = 0;
    for (size_t i = 0; i < 100; ++i) {
        if(currentPlayer->getBoard().getEnemyBoard()[i] == EnemyPiece::HIT) {         
            ++count;
        }
    }  
    return (count < 17) ? true : false; 
}


void Game::play() {
    while(isRunning()) {
        currentPlayer = nextPlayer();
        std::cout << "\n" << currentPlayer->getName() << "'s board\n";
        std::cout << currentPlayer->getBoard() << "\n";      
        std::cout << "\n" << currentPlayer->getName() << "'s move\n";

        //Get move from player and check if it is legal
        Move playerMove = currentPlayer->getMove();        
        while(!currentPlayer->getBoard().isLegal(playerMove)) {      
            playerMove = currentPlayer->getMove(); 
        }
        if(currentPlayer == player1.get()) {
            currentPlayer->getBoard().makeMove(playerMove, player2->getBoard()); 
        }
        else {
            currentPlayer->getBoard().makeMove(playerMove, player1->getBoard()); 
        }
    }
}


void Game::announceWinner() {
    //Print the winner
    std::cout << "The winner is: " << currentPlayer->getName();    
    std::cout << currentPlayer->getBoard() << "\n"; 
    currentPlayer = nullptr;
}