/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Medium Player, derived from Computer Player.
*/

#include "MediumPlayer.h"


Move MediumPlayer::getMove() {
    //Seed Generator
    std::random_device randomGenerator;
    //Mersenne Twister
    std::mt19937_64 rand(randomGenerator());
    return mediumMove(rand);
}


Move MediumPlayer::easyMove(std::mt19937_64& rand) {
    Move move;
    move.row = rand() % 10;
    move.col = rand() % 10 + 'A';
    return move;
}


//search through array, if no hits, call getMove()
//if hit is found, move = -1, +1, -10, or +10
Move MediumPlayer::mediumMove(std::mt19937_64& rand) {                      //Note: because not required for project, we didn't break it down
    Move move;                                                              //into smaller functions/optimize it
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            char currentElement = 'A' + j;
            if (getBoard().getEnemyArr()[(10 * i) + j] == EnemyPiece::HIT) {
                char hit = 'A' + j;
                //Left / Right / Up / Down
                if (i > 0 && i < 9 && j > 0 && j < 9) {
                    int direction = rand() % 4;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if (direction == 1) {
                        move.row = i;
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if (direction == 2) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';
                    }
                    else if (direction == 3) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Down
                else if (i == 0 && j == 0) {
                    int direction = rand() % 2;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if (direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up
                else if (i == 9 && j == 9) {
                    int direction = rand() % 2;
                    if (direction == 0) {            //Left
                        move.row = i;
                        move.col = j - 1 + 'A';
                    }
                    else if (direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Down
                else if (i == 0 && j == 9) {
                    int direction = rand() % 2;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j - 1 + 'A';     //Left

                    }
                    else if (direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Up
                else if (i == 9 && j == 0) {
                    int direction = rand() % 2;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if (direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Right / Down
                else if (i == 0 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if (direction == 1) {
                        move.row = i;
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if (direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Up / Down
                else if (i > 0 && i < 9 && j == 0) {
                    int direction = rand() % 3;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if (direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';
                    }
                    else if (direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Right / Up
                else if (i == 9 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j - 1 + 'A';                                                         //left
                    }
                    else if (direction == 1) {
                        move.row = i;
                        move.col = j + 1 + 'A';                                                         //right
                    }
                    else if (direction == 2) {
                        move.row = i - 1;                                                               //up
                        move.col = j + 'A';

                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up / Down
                else if (i > 0 && i < 9 && j == 9) {
                    int direction = rand() % 3;
                    if (direction == 0) {
                        move.row = i;
                        move.col = j - 1 + 'A';                                                         //left
                    }
                    else if (direction == 1) {
                        move.row = i - 1;                                                               //up
                        move.col = j + 'A';
                    }
                    else if (direction == 2) {
                        move.row = i + 1;                                                               //down
                        move.col = j + 'A';
                    }
                    else { std::cerr << "Error in direction selection!\n"; }
                }
                else {
                    std::cerr << "Error in mediumMove row selection!\n";
                }
                
                if (getBoard().getEnemyArr()[(10 * move.row) + (move.col - 65)] == EnemyPiece::EMPTY) { //if the element selected is empty, return the move
                    return move;
                }
            }
            count = count + 1;
        }
    }
    if (count >= 99) {
        move = easyMove(rand);                                                                          //if all elements have been checked for a hit and none have been found, call easymove()
    }
    return move;
}