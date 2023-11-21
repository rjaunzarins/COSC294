#include <iostream>
#include "Board.h"
#include "Move.h"
#include <random>

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
                        exit(1);
                }
                elementsLegal = true;
                for(targetElement; targetElement < targetElement + numElements; ++targetElement) {
                    Move move;
                    move.row = row;
                    move.col = move.convertToChar(col);         //! made this function for conversion (move.cpp)
                    if(!Board::isLegal(move)) {
                        elementsLegal = false;
                    }
                }
                if(elementsLegal) {
                    for(targetElement; targetElement < targetElement + numElements; ++targetElement) {
                        playerBoard[targetElement] = currentPiece;
                    }
                }
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
    if(move.row >= 0 && move.row <= 9 && move.col >= 'A' && move.col <= 'J') {
        return true;
    }
    return false;
}

//Displays both the boards to the specified stream
std::ostream& operator <<(std::ostream& outStream, const Board& board) {
    outStream << "-- PLAYER BOARD --";
    for(size_t i = 0; i < 10; ++i) { 
        outStream << "\n-------------------------------------------------\n";
        for(size_t j = 0; j < 10; ++j) {
            switch(board.playerBoard[(10*i)+j]) {
                case PlayerPiece::AIRCRAFT:
                    outStream << "| A ";
                    break;
                case PlayerPiece::BATTLESHIP:
                    outStream << "| B ";
                    break;
                case PlayerPiece::CRUISER:
                    outStream << "| C ";
                    break;
                case PlayerPiece::SUBMARINE:
                    outStream << "| S ";
                    break;
                case PlayerPiece::PATROL:
                    outStream << "| P ";
                    break;
                case PlayerPiece::EMPTY:
                    outStream << "| E ";
                    break;
                default:
                    std::cerr << "Error in Enum PlayerBoard";
                    exit(1);
            }
        }
    }
    outStream << "\n";

    outStream << "-- ENEMY BOARD --";
    for(size_t i = 0; i < 10; ++i) { 
        outStream << "\n-------------------------------------------------\n";
        for(size_t j = 0; j < 10; ++j) {
            switch(board.enemyBoard[(10*i)+j]) {
                case EnemyPiece::HIT:
                    outStream << "| H ";
                    break;
                case EnemyPiece::MISS:
                    outStream << "| M ";
                    break;
                case EnemyPiece::EMPTY:
                    outStream << "| E ";
                    break;
                default:
                    std::cerr << "Error in Enum EnemyBoard";
                    exit(1);
            }
        }
    }
    outStream << "\n";
    return outStream;
}