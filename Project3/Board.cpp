#include <iostream>
#include "Board.h"
#include "Move.h"
#include "Player.h"

//ANSI escape codes for text color
#define RESET   "\033[0m"       
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define GREY    "\033[2m" 


//Default constructor that initializes the board by calling the member 
//function reset(). 
Board::Board() : playerBoard(new PlayerPiece[100]), enemyBoard(new EnemyPiece[100]) {
    reset();
}

Board::~Board() {
    // if(playerBoard != nullptr) {
    //     delete [] playerBoard;
    // }
    // if(enemyBoard != nullptr) {
    //     delete [] enemyBoard;
    // }
}

EnemyPiece* Board::getEnemyBoard() const noexcept{ 
    return enemyBoard; 
}

PlayerPiece* Board::getPlayerBoard() const noexcept{ 
    return playerBoard; 
}


//Erases all pieces from the board (i.e. sets them to Empty); then randomly 
//places the 5 ship types within the player pieces' array
void Board::reset() {
    //Reset boards to empty
    for(size_t i = 0; i < 100; ++i) {    //! Change 100 to size
        playerBoard[i] = PlayerPiece::EMPTY;
        enemyBoard[i] = EnemyPiece::EMPTY;
    }
    initializePlayerboard();                 //initialize elements in playerBoard
}


void Board::initializePlayerboard() {
    //Seed Generator & Mersenne Twister for random
    std::random_device randomGenerator;
    std::mt19937_64 rand(randomGenerator());

    for(size_t boatType = 0; boatType < 5; ++boatType) {                            //Iterate through the 5 types of boats
        placeShips(boatType, rand);
    }
}


void Board::placeShips(size_t boatType, std::mt19937_64& rand) {     
    bool elementsLegal = false;                                                         //Will the entire ship placement be legal

    while(!elementsLegal) {    
        size_t row = rand() % 10;                                                       //rand [0-9] for element in imaginary 2D array row
        size_t col = rand() % 10;                                                       //rand [0-9] for col in imaginary 2D array
        bool isVerticalPlacement = rand() % 2;                                          //vertical placement of piece (true/false)
        size_t targetElement = (10 * row) + col;                                        //Convert 2D array coordinates to 1D array element
        
        if(playerBoard[targetElement] == PlayerPiece::EMPTY) {
            size_t numElementsInShip;                                                   //numElementsInShip is number of elements boat will occupy
            PlayerPiece currentPiece;                                                   //currentPiece is the current type of ship (Cruiser, Aircraft, etc)                
            setBoatType(boatType, numElementsInShip, currentPiece);
            
            Move move(row, static_cast<char>('A' + col));
            size_t finalElement = targetElement + numElementsInShip;                    //finalElement = targetElement plus number of elements in ship type

            //Check if all elements will be legal given ship size and orientation
            elementsLegal = isShipPlacementLegal(move, isVerticalPlacement, targetElement, finalElement);

            //If elements legal place ship on the board
            if(elementsLegal) {
                makePlacement(currentPiece, isVerticalPlacement, targetElement, finalElement);
            }
        }
    }
}


void Board::setBoatType(size_t boatType, size_t &numElementsInShip, PlayerPiece &currentPiece) {
    switch(boatType) {
        case 0:
            numElementsInShip = 5;
            currentPiece = PlayerPiece::AIRCRAFT;
            break;
        case 1:
            numElementsInShip = 4;
            currentPiece = PlayerPiece::BATTLESHIP;
            break;
        case 2:
            numElementsInShip = 3;
            currentPiece = PlayerPiece::CRUISER;
            break;
        case 3:
            numElementsInShip = 3;
            currentPiece = PlayerPiece::SUBMARINE;
            break;
        case 4:
            numElementsInShip = 2;
            currentPiece = PlayerPiece::PATROL;
            break;
        default:
            std::cerr << "Error in assigning boat type!\n";
            currentPiece = PlayerPiece::EMPTY;
            exit(1);
    }
}


bool Board::isShipPlacementLegal(Move& move, bool isVerticalPlacement, size_t targetElement, size_t finalElement) {
    std::cout << "Target: " << targetElement << "\nFinal: " << finalElement << "\n";
    for(size_t i = targetElement ; i < finalElement; ++i) {                     //Iterate through elements from target to target + numElementsInShip in ship type
        if(!isLegalPlacement(move)) {
            return false;                                                 
        }
        if(isVerticalPlacement) {                                               //If elements are being searched vertically, increment row
            ++move.row;
        }
        else {
            ++move.col;                                                              //If elements are being searched horizontally, increment col
        }
    }
    return true;
}


void Board::makePlacement(PlayerPiece& currentPiece, bool isVerticalPlacement, size_t targetElement, size_t finalElement) { 
   if(isVerticalPlacement) {    
        for(size_t i = targetElement; i < finalElement; ++i) {                            
            playerBoard[targetElement] = currentPiece;
            targetElement += 10;
        }
    }
    else {
        for(size_t i = targetElement ; i < finalElement; ++i) {
            playerBoard[i] = currentPiece;
        }
    }
    
    // size_t step = isVerticalPlacement ? 10 : 1;                          //if we can figure this out it would be cleaner
    // for (size_t i = targetElement; i <= finalElement; i += step) {
    //     playerBoard[i] = currentPiece;
    // }
}

//!leave comment that this is fine!
//Executes the move indicated by the first function parameter; the second is true 
//if it is the player's move, and false if it was the enemy's move (i.e., this 
//parameter indicates which array to update).
void Board::makeMove(Move move, Board& enemyPlayer) {                           //! bool isPlayer was changed to const Board& enemyPlayer -> This will need to be changed to not const to make changes to enemyPlayer's playerBoard
    if(isLegal(move)) {
        size_t moveIndex = move.getIndex();
        if(enemyPlayer.getPlayerBoard()[moveIndex] != PlayerPiece::EMPTY) {             
            enemyBoard[moveIndex] = EnemyPiece::HIT;                                    //If enemies board is a ship then move is a hit
            enemyPlayer.playerBoard[moveIndex] = PlayerPiece::DAMAGED;                  //If enemies board is a ship then move is a hit
        }
        else {
            enemyBoard[moveIndex] = EnemyPiece::MISS;                                   //If enemies board is empty then move is a miss
        }
    }
}


//Retuns false if out of bounds of the board, or if the Move has already been done 
//by checking the enemy's board.
bool Board::isLegal(Move move) {                                                      
    int index = move.getIndex();
    if(move.row < 0 || move.row > 9 && move.col < 'A' && move.col > 'J') {
        std::cout << "Out of bounds!\n";
        return false;  
    }
    if(enemyBoard[index] != EnemyPiece::EMPTY) {
        std::cout << "Move already made!\n";
        return false;
    }
    return true;  
}

//The placement of an entire ship is legal
bool Board::isLegalPlacement(Move move) {
    int index = move.getIndex();
    if(move.row < 0 || move.row > 9 || move.col < 'A' || move.col > 'J') {
        return false;  
    }
    if(playerBoard[index] != PlayerPiece::EMPTY) {
        return false;
    }
    return true; 
}


//Displays both the boards to the specified stream
std::ostream& operator <<(std::ostream& outStream, const Board& board) {      
    //Print EnemyPiece Board
    outStream << "\n-- ENEMY BOARD --";
    for(size_t i = 0; i < 10; ++i) { 
        outStream << "\n-----------------------------------------\n";
        for(size_t j = 0; j < 10; ++j) {
            switch(board.enemyBoard[(10*i)+j]) {
                case EnemyPiece::HIT:
                    outStream << "| " << RED << "H " << RESET;
                    break;
                case EnemyPiece::MISS:
                    outStream << "| " << MAGENTA << "M " << RESET;
                    break;
                case EnemyPiece::EMPTY:
                    outStream << "| " << GREY << "E " << RESET;;
                    break;
                default:
                    std::cerr << "Error in Enum EnemyBoard";
                    exit(1);
            }
            if(j == 9) {
                std::cout << "|";
            }
        }
    }
    outStream << "\n-----------------------------------------\n";

    //Print PlayerPiece Board
    outStream << "\n-- PLAYER BOARD --";
    for(size_t i = 0; i < 10; ++i) { 
        outStream << "\n-----------------------------------------\n";
        for(size_t j = 0; j < 10; ++j) {
            switch(board.playerBoard[(10*i)+j]) {
                case PlayerPiece::AIRCRAFT:
                    outStream << "| " << RED << "A " << RESET;
                    break;
                case PlayerPiece::BATTLESHIP:
                    outStream << "| " << GREEN << "B " << RESET;
                    break;
                case PlayerPiece::CRUISER:
                    outStream << "| " << BLUE << "C " << RESET;
                    break;
                case PlayerPiece::SUBMARINE:
                    outStream << "| " << MAGENTA << "S " << RESET;
                    break;
                case PlayerPiece::PATROL:
                    outStream << "| " << YELLOW << "P " << RESET;
                    break;
                case PlayerPiece::EMPTY:
                    outStream << "| " << GREY << "O " << RESET;
                    break;
                case PlayerPiece::DAMAGED:
                    outStream << "| " << RED << "X " << RESET;
                    break;
                default:
                    std::cerr << "Error in Enum PlayerBoard";
                    exit(1);
            }
            if(j == 9) {
                std::cout << "|";
            }
            
        }
    }
    outStream << "\n-----------------------------------------\n";
    
    return outStream;
}
