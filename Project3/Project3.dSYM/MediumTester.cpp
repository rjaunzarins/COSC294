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

//TODO: Implement mediumMove
//TODO: search through array, if no hits, call getMove()
//TODO: if hit is found, move = -1, +1, -10, or +10
//It gets a move but it wont return the move. it will continue in the for loop.
//If i were to do a break it would start the loop all over again
Move MediumPlayer::mediumMove(std::mt19937_64& rand) {
    Move move;
    int count = 0;  
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            char currentElement = 'A' + j;
            //std::cout << "Current Elem: " << i << ", " << currentElement << "\n";
            if (getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::HIT) {
                char hit = 'A' + j;
                //std::cout << "Previous Hit: " << i << ", " << hit << "\n";
                //Left / Right / Up / Down
                if(i > 0 && i < 9 && j > 0 && j < 9) {
                    int direction = rand() % 4;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                        //std::cout << "Hit Left1: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right1: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 2) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        //std::cout << "Hit Up1: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 3) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down1: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Down
                else if(i == 0 && j == 0) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right2: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down2: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up
                else if(i == 9 && j == 9) {
                    int direction = rand() % 2;
                    if(direction == 0) {            //Left
                        move.row = i;               
                        move.col = j - 1 + 'A';
                        //std::cout << "Hit Left3: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        //std::cout << "Hit Up3: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Down
                else if(i == 0 && j == 9) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                        //std::cout << "Hit Left4: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down4: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                } 
                //Right / Up
                else if(i == 9 && j == 0) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right5: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        //std::cout << "Hit Up5: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                } 
                //Left / Right / Down
                else if(i == 0 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right6: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                        //std::cout << "Hit Left6: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down6: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Up / Down
                else if(i > 0 && i < 9 && j == 0) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right7: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';            
                        //std::cout << "Hit Up7: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down7: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Right / Up
                else if(i == 9 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                        //std::cout << "Hit Left8: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                        //std::cout << "Hit Right8: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 2) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        //std::cout << "Hit Up8: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up / Down
                else if(i > 0 && i < 9 && j == 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                        //std::cout << "Hit Left9: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        //std::cout << "Hit Up9: " << move.row << ", " << move.col << "\n";
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                        //std::cout << "Hit Down9: " << move.row << ", " << move.col << "\n";
                    }
                    else { std::cerr << "Error in direction selection!\n"; }
                }
                else {
                    std::cerr << "Error in mediumMove row selection!\n";
                }
                //If the element selected is empty, return the move
                if(getBoard().getEnemyBoard()[(10 * move.row) + (move.col - 65)] == EnemyPiece::EMPTY) {
                    //std::cout << "Return Move: " << move.row << ", " << move.col << "\n";
                    return move;
                }
            }
            count = count + 1;
        }
        //std::cout << "Count: " << count << "\n";
    }
    ///std::cout << "Hit Attempt: " << move.row << ", " << move.col << "\n";
    if(count >= 99) {
        //std::cout << "No hits found, calling easyMove()\n";
        move = easyMove(rand);
    }
    //std::cout << "Hit: " << move.row << ", " << move.col << "\n";
    return move;
}