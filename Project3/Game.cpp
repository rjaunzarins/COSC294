#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "RandomPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"


void Game::selectPlayers() {
    //Prompts the user for each of the two players for the type (human/computer) of the player.
    //For a human player the function also asks for the player's name. The function then creates
    //the objects for the players dynamically
    std::string name;
    char type;
    
    //Player1
    char userSelect = 'a';
    while(userSelect != 'c' && userSelect != 'C' && userSelect != 'h' && userSelect != 'H') {
        std::cout << "Enter Player1 type [C/H]: ";
        std::cin >> userSelect;
        if(userSelect == 'H' || userSelect == 'h') {    
            std::cout << "Player1 name: ";
            createHumanPlayer(player1);
        }
        else if(userSelect == 'c' || userSelect == 'C') {
            getDifficulty(player1);
        }
    }
    //Player2
    char userSelect = 'a';
    while(userSelect != 'c' && userSelect != 'C' && userSelect != 'h' && userSelect != 'H') {
        std::cout << "Enter Player1 type [C/H]: ";
        std::cin >> userSelect;
        if(userSelect == 'H' || userSelect == 'h') {    
            std::cout << "Player2 name: ";
            createHumanPlayer(player2);
        }
        else if(userSelect == 'c' || userSelect == 'C') {
            getDifficulty(player2);
        }
    }
    announcePlayers(player1, player2);  

    //Assign first player to player1
    currentPlayer = player2.get();     
}

void Game::announcePlayers(const std::unique_ptr<Player>& player1, const std::unique_ptr<Player>& player2) {
    std::cout << "Player1 is: " << player1->getName() << "\n";
    std::cout << "Player2 is: " << player2->getName() << "\n"; 
}

void Game::createHumanPlayer(std::unique_ptr<Player>& currentPlayer) {
    std::string playerName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, playerName);
    currentPlayer = std::make_unique<HumanPlayer>(playerName);
}

void Game::getDifficulty(std::unique_ptr<Player>& currentPlayer) {
    char difficulty;
    bool isValid = false;
    while(!isValid) {
        std::cout << "\nEnter Difficulty [E,M,H]: ";
        if(std::cin >> difficulty) {
            if(difficulty == 'E' || difficulty == 'e') {
                isValid = true;
                currentPlayer = std::make_unique<RandomPlayer>();
            }
            else if(difficulty == 'M' || difficulty == 'm') {
                isValid = true;
                currentPlayer = std::make_unique<MediumPlayer>();
            }
            else if(difficulty == 'H' || difficulty == 'h') {
                isValid = true;
                currentPlayer = std::make_unique<HardPlayer>();
            }
            else {
                std::cout << "Selection is not valid\n";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
        }
        else {
            std::cout << "Selection is not valid\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
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


bool Game::isHumanPlayer(Player* currentPlayer) {
    if (currentPlayer == dynamic_cast<HumanPlayer*>(currentPlayer)) {
            return true;
    }
    return false;
}


void Game::play() {
    while(isRunning()) {
        currentPlayer = nextPlayer();
        std::cout << "\n" << currentPlayer->getName() << "'s board\n";
        std::cout << currentPlayer->getBoard() << "\n";      

        if (isHumanPlayer(currentPlayer)) {                                         
            std::cout << "\n" << currentPlayer->getName() << ", ";
        }
        else {
            std::cout << "\n" << currentPlayer->getName() << " has made its move\n";
        }

        //Get move from player and check if it is legal
        Move playerMove = currentPlayer->getMove();  
        //While not a legal move      
        while(!currentPlayer->getBoard().isLegal(playerMove)) {      
            //If HumanPlayer, print invalid move
            if (isHumanPlayer(currentPlayer)) {                                     
                std::cout << "Invalid Move\n";
            }
            playerMove = currentPlayer->getMove(); 
        }
        //If currentPlayer is Player1
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
    std::cout << "\n\nThe winner is: " << currentPlayer->getName();    
    std::cout << currentPlayer->getBoard() << "\n"; 
    currentPlayer = nullptr;
}