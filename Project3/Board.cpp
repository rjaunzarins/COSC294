#include <iostream>
#include "Board.h"
#include "Move.h"
#include <random>
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
    delete [] playerBoard;
    playerBoard = nullptr;
    delete [] enemyBoard;
    enemyBoard = nullptr;
}

//Erases all pieces from the board (i.e. sets them to Empty); then randomly 
//places the 5 ship types within the player pieces' array
void Board::reset() {
    for(size_t i = 0; i < 100; ++i) {    //! Change 100 to size
        playerBoard[i] = PlayerPiece::EMPTY;
        enemyBoard[i] = EnemyPiece::EMPTY;
    }

    //Seed Generator
    std::random_device randomGenerator;
    //Mersenne Twister
    std::mt19937_64 rand(randomGenerator());

    size_t boatType;
    size_t numElements;
    PlayerPiece currentPiece;

    for(boatType = 0; boatType < 5; ++boatType) {   
        bool elementsLegal = false;
        while(!elementsLegal) {    
            //Place Ships . . .
            size_t row = rand() % 10;
            size_t col = rand() % 10;
            size_t verticalPlacement = rand() % 2;
            std::cout << "Vertical Placement: " << verticalPlacement << "\n";
            size_t targetElement = (10 * row) + col;
            if(playerBoard[targetElement] == PlayerPiece::EMPTY) {
                switch(boatType) {
                    case 0:
                        numElements = 5;
                        currentPiece = PlayerPiece::AIRCRAFT;
                        break;
                    case 1:
                        numElements = 4;
                        currentPiece = PlayerPiece::BATTLESHIP;
                        break;
                    case 2:
                        numElements = 3;
                        currentPiece = PlayerPiece::CRUISER;
                        break;
                    case 3:
                        numElements = 3;
                        currentPiece = PlayerPiece::SUBMARINE;
                        break;
                    case 4:
                        numElements = 2;
                        currentPiece = PlayerPiece::PATROL;
                        break;
                    default:
                        std::cerr << "Error in assigning boat type!\n";
                        currentPiece = PlayerPiece::EMPTY;
                        exit(1);
                }
                elementsLegal = true;
                Move move;
                size_t finalElement = targetElement + numElements;
                for(size_t i = targetElement ; i < finalElement; ++i) {
                    move.row = row;
                    move.col = static_cast<char>('A' + col);
                    std::cout << "Check - target element: " << targetElement << "\n";
                    if(!Board::isLegal(move)) {
                        elementsLegal = false;
                        break;  //! break if cannot continue
                    }
                    if(verticalPlacement) {
                        ++row;
                    }
                    else {
                        ++col;
                    }
                }
                if(elementsLegal) {
                    move.col = move.col - numElements;
                    col = col - numElements;
                    if(verticalPlacement) {    
                        for(size_t i = targetElement ; i < finalElement; ++i) {                            
                            std::cout << "Vertical - target element: " << i << "\n";
                            playerBoard[targetElement] = currentPiece;
                            targetElement = targetElement + 10;
                        }
                    }
                    else {
                        for(size_t i = targetElement ; i < finalElement; ++i) {
                            std::cout << "Horizontal - target element: " << i << "\n";
                            playerBoard[i] = currentPiece;
                        }
                    }
                }
                std::cout << "----------------------\n";
            }
        }
    }
}

//Executes the move indicated by the first function parameter; the second is true 
//if it is the player's move, and false if it was the enemy's move (i.e., this 
//parameter indicates which array to update).
void Board::makeMove(Move move, bool isPlayer) {

}

//Retuns false if out of bounds of the board, or if the Move has already been done 
//by checking the enemy's board.
bool Board::isLegal(Move move) {
    std::cout << "Element " << (move.row * 10) + (static_cast<int>(move.col) - 65) << " is ";
    if(move.row >= 0 && move.row <= 9 && move.col >= 'A' && move.col <= 'J') {
        if(playerBoard[(move.row * 10) + (static_cast<int>(move.col) - 65)] == PlayerPiece::EMPTY) {
            std::cout << "legal\n";
            return true;
        }    
    }
    std::cout << "not legal\n";
    return false;
}

//Displays both the boards to the specified stream
std::ostream& operator <<(std::ostream& outStream, const Board& board) {
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
    

    // outStream << "\n-- ENEMY BOARD --";
    // for(size_t i = 0; i < 10; ++i) { 
    //     outStream << "\n-----------------------------------------\n";
    //     for(size_t j = 0; j < 10; ++j) {
    //         switch(board.enemyBoard[(10*i)+j]) {
    //             case EnemyPiece::HIT:
    //                 outStream << "| H ";
    //                 break;
    //             case EnemyPiece::MISS:
    //                 outStream << "| M ";
    //                 break;
    //             case EnemyPiece::EMPTY:
    //                 outStream << "| E ";
    //                 break;
    //             default:
    //                 std::cerr << "Error in Enum EnemyBoard";
    //                 exit(1);
    //         }
    //         if(j == 9) {
    //             std::cout << "|";
    //         }
    //     }
    // }
    // outStream << "\n-----------------------------------------\n";
    return outStream;
}