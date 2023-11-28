#include "RandomPlayer.h"


Move RandomPlayer::getMove() {
    return getMove(Difficulty::MEDIUM);
}

Move RandomPlayer::getMove(Difficulty difficulty) {
    Move move;
    //Seed Generator
    std::random_device randomGenerator;
    //Mersenne Twister
    std::mt19937_64 rand(randomGenerator());
    
    if(difficulty == Difficulty::EASY) {
        move = easyMove(rand);
    }
    else if(difficulty == Difficulty::MEDIUM) {
        move = mediumMove(rand);
    }
    else if(difficulty == Difficulty::HARD) {
        move = hardMove(rand);
    }
    else {
        std::cerr << "Error in difficulty selection!\n";
    }
    return move;   
}

Move RandomPlayer::easyMove(std::mt19937_64& rand) {
    Move move;
    move.row = rand() % 10;
    move.col = rand() % 10 + 'A';
    return move;
}

//TODO: Implement mediumMove
//TODO: search through array, if no hits, call getMove()
//TODO: if hit is found, move = -1, +1, -10, or +10
Move RandomPlayer::mediumMove(std::mt19937_64& rand) {
    Move move;
    int count = 0;  
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if (getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::HIT) {
                //if(i > 0 && i < 9 && j > 0 && j < 9) {
                    int direction = rand() % 4;
                    if(direction == 0) {
                        move.row = i - 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i + 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 2) {
                        move.row = i;
                        move.col = j - 10 + 'A';
                    }
                    else if(direction == 3) {
                        move.row = i;
                        move.col = j + 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                // else if(i == 0 && j == 0) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i + 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i;
                        move.col = j + 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                // else if(i == 9 && j == 9) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i - 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i;
                        move.col = j - 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }  
                // else if(i == 0 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i + 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i;
                        move.col = j - 10 + 'A';
                    }
                    else if(direction == 2) {
                        move.row = i;
                        move.col = j + 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                // else if(i > 0 && i < 9 && j == 0) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i - 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i + 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 2) {
                        move.row = i;
                        move.col = j + 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                // else if(i == 9 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i - 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i;
                        move.col = j - 10 + 'A';
                    }
                    else if(direction == 2) {
                        move.row = i;
                        move.col = j + 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                // else if(i > 0 && i < 9 && j == 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i - 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i + 1;
                        move.col = j + 'A';
                    }
                    else if(direction == 2) {
                        move.row = i;
                        move.col = j - 10 + 'A';
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                else {
                    std::cerr << "Error in mediumMove row selection!\n";
                }
            }
        }
        count = count + 10;
    }
    if(count >= 99) {
        std::cout << "No hits found, calling easyMove()\n";
        move = easyMove(rand);
    }
    return move;
}

Move getDirectionFromHit(std::mt19937_64 rand, int i, int j) {
    int direction;
    if(i > 0 && i < 9 && j > 0 && j < 9) {
        direction = rand() % 4;
    }
    else if(i == 0 && j == 0) {
        direction = rand() % 2
    }
    else if(i == 9 && j == 9) {
        direction = rand() % 2;
    }
    else if(i == 0 && j > 0 && j < 9) {
        direction = rand() % 3;
    }
    else if(i > 0 && i < 9 && j == 0) {
        direction = rand() % 3;
    }
    else if(i == 9 && j > 0 && j < 9) {
        direction = rand() % 3;
    }
    else if(i > 0 && i < 9 && j == 9) {
        direction = rand() % 3;
    }
    else {
        std::cerr << "Error in mediumMove row selection\n";
        return move;
    }
    return getElementFromHit(int direction, int i, int j) {
        Move move;
        switch(direction) {
            case 0:
                move.row = i - 1;
                move.col = j + 'A';
                break;
            case 1:
                move.row = i + 1;
                move.col = j + 'A';
                break;
            case 2:
                move.row = i;
                move.col = j - 10 + 'A';
                break;
            case 3:
                move.row = i;
                move.col = j + 10 + 'A';
                break;
            default:
                std::cerr << "Error in direction selection\n";
                break;
        }
    }
}

//TODO: Implement hardMove
//TODO: search through array, if no hits, call getMove()
//TODO: if his is found, search to see if there are more than one hits in a row
//TODO: it there are, continue in +ve or -ve direction
Move RandomPlayer::hardMove(std::mt19937_64& rand) {
    Move move;
    return move;
}
