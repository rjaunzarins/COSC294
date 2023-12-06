/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Player's Board.
*/

#include "Board.h"
#include "Move.h"
#include "GameColours.h"
#include <iostream>

Board::Board() : playerArrPtr(new PlayerPiece[100]), enemyArrPtr(new EnemyPiece[100]) {
    reset();
}


Board::~Board() {
    delete[] playerArrPtr;                                       
    delete[] enemyArrPtr;
}


void Board::reset() {
    for (size_t i = 0; i < 100; ++i) {                                                                           //empty both boards
        playerArrPtr[i] = PlayerPiece::EMPTY;
        enemyArrPtr[i] = EnemyPiece::EMPTY;
    }
    initializePlayerBoard();                                                                                    //place 5 ships randomly on board
}
  

void Board::initializePlayerBoard() {
    std::random_device randomGenerator;
    std::mt19937_64 rand(randomGenerator());

    for (size_t boatType = 0; boatType < 5; ++boatType) {
        placeShips(boatType, rand);
    }
}


void Board::placeShips(size_t boatType, std::mt19937_64 rand) {
    bool elementsLegal = false;
    while (!elementsLegal) {
        int row = rand() % 10;
        int col = rand() % 10;
        bool isVerticalPlacement = rand() % 2;
        int targetElement = (10 * row) + col;

        if (playerArrPtr[targetElement] == PlayerPiece::EMPTY) {                                                //if there isn't already a ship there               
            size_t numElementsInShip;
            PlayerPiece currentPiece;
            setBoatType(boatType, numElementsInShip, currentPiece);                                             //set type of enum PlayerPiece to go on player board
            Move move(row, static_cast<char>('A' + col));
            int finalElement = targetElement + numElementsInShip;          
            elementsLegal = isShipPlacementLegal(move, isVerticalPlacement, targetElement, finalElement);       //check if all elements will be legal, given ship size & orientation
           
            if (elementsLegal) {
                makePlacement(currentPiece, isVerticalPlacement, targetElement, finalElement);                  //if all is legal, place ship on board
            }
        }
    }

}


void Board::setBoatType(size_t boatType, size_t& numElementsInShip, PlayerPiece& currentPiece) {
    switch (boatType) {
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
        std::cerr << "\nError in setting boat type.";
        currentPiece = PlayerPiece::EMPTY;
        exit(1);
    }

}


bool Board::isShipPlacementLegal(Move& moveIn, bool isVerticalPlacement, int targetElement, int finalElement) {
    for (int i = targetElement; i < finalElement; ++i) {
        if (!isLegalPlacement(moveIn)) {
            return false;
        }
        if (isVerticalPlacement) {
            ++moveIn.row;
        }
        else {
            ++moveIn.col;
        }
    }
    return true;
}


bool Board::isLegalPlacement(Move moveIn) {
    if (moveIn.row < 0 || moveIn.row > 9 || moveIn.col < 'A' || moveIn.col > 'J') {                             //check if ship would be out of bounds
        return false;
    }
    int moveIndex = moveIn.getIndex();
    if (playerArrPtr[moveIndex] != PlayerPiece::EMPTY) {                                                        //check if there's already a ship there
        return false;
    }
    return true;
}


void Board::makePlacement(PlayerPiece& currentPiece, bool isVerticalPlacement, int targetElement, int finalElement) {
    if (isVerticalPlacement) {
        for (int i = targetElement; i < finalElement; ++i) {
            playerArrPtr[targetElement] = currentPiece;
            targetElement += 10;
        }
    }
    else {
        for (int i = targetElement; i < finalElement; ++i) { 
            playerArrPtr[i] = currentPiece;
        }
    }

}


bool Board::isLegal(Move moveIn) const {
    if (moveIn.row < 0 || moveIn.row > 9 || moveIn.col < 'A' || moveIn.col > 'J') {
        return false;
    }
    int moveIndex = moveIn.getIndex();
    if (enemyArrPtr[moveIndex] != EnemyPiece::EMPTY) {
        return false;
    }
    return true;                                                                                                //if not out of bounds and nothing is already there
}


//Note: 2nd param changed from bool to Board&, in order to access enemy's Board [ you said this is okay :) ]
void Board::makeMove(Move moveToMake, Board& enemyPlayer) {                                                     
    if (isLegal(moveToMake)) {
        int moveIndex = moveToMake.getIndex();

        if (enemyPlayer.getPlayerArr()[moveIndex] != PlayerPiece::EMPTY) {
            enemyArrPtr[moveIndex] = EnemyPiece::HIT;                           
            enemyPlayer.playerArrPtr[moveIndex] = PlayerPiece::DAMAGE;                                          //if ship there, update Player's enemy board to Hit, & enemy's player board to Damage

        }
        else {
            enemyArrPtr[moveIndex] = EnemyPiece::MISS;
        }
    }
}


std::ostream& operator<<(std::ostream& outStream, const Board& boardIn) {
    outStream << GameColours::RESET << "\n-- ENEMY BOARD --";
    for (size_t i = 0; i < 10; ++i) {
        outStream << GameColours::RESET << "\n-----------------------------------------\n";
        for (size_t j = 0; j < 10; ++j) {
            switch (boardIn.enemyArrPtr[(10 * i) + j]) {
            case EnemyPiece::HIT:
                outStream << GameColours::RESET << "| " << GameColours::RED << "H ";
                break;
            case EnemyPiece::MISS:
                outStream << GameColours::RESET << "| " << GameColours::YELLOW << "M ";
                break;
            case EnemyPiece::EMPTY:
                outStream << GameColours::RESET  << "| " << "E ";
                break;
            default:
                std::cerr << "Error in Enum EnemyBoard";
                exit(1);
            }
            if (j == 9) {
                std::cout << GameColours::RESET << "|";
            }
        }
    }
    outStream << GameColours::RESET << "\n-----------------------------------------\n";

    outStream << "\n-- PLAYER BOARD --";
    for (size_t i = 0; i < 10; ++i) {
        outStream << "\n-----------------------------------------\n";
        for (size_t j = 0; j < 10; ++j) {
            switch (boardIn.playerArrPtr[(10 * i) + j]) {
            case PlayerPiece::AIRCRAFT:
                outStream << "| " << GameColours::RED << "A " << GameColours::RESET;
                break;
            case PlayerPiece::BATTLESHIP:
                outStream << "| " << GameColours::GREEN << "B " << GameColours::RESET;
                break;
            case PlayerPiece::CRUISER:
                outStream << "| " << GameColours::BLUE << "C " << GameColours::RESET;
                break;
            case PlayerPiece::SUBMARINE:
                outStream << "| " << GameColours::YELLOW << "S " << GameColours::RESET;
                break;
            case PlayerPiece::PATROL:
                outStream << "| " << GameColours::MAGENTA << "P " << GameColours::RESET;
                break;
            case PlayerPiece::EMPTY:
                outStream << "| " << GameColours::GREY << "O " << GameColours::RESET;
                break;
            case PlayerPiece::DAMAGE:
                outStream << "| " << GameColours::RED << "X " << GameColours::RESET;
                break;
            default:
                std::cerr << "\nError in Enum PlayerBoard";
                exit(1);
            }
            if (j == 9) {
                std::cout << "|";
            }
        }
    }
    outStream << "\n-----------------------------------------\n";
    return outStream;
}


