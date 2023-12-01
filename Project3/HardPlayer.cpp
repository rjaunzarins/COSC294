#include "HardPlayer.h"


Move HardPlayer::getMove() {
    //Seed Generator
    std::random_device randomGenerator;
    //Mersenne Twister
    std::mt19937_64 rand(randomGenerator());
    return mediumMove(rand);
}

Move HardPlayer::easyMove(std::mt19937_64& rand) {
    Move move;
    move.row = rand() % 10;
    move.col = rand() % 10 + 'A';
    return move;
}

//Same Implementation as MediumPlayer for now
Move HardPlayer::mediumMove(std::mt19937_64& rand) {
    Move move;
    int count = 0;  
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            char currentElement = 'A' + j;
            if (getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::HIT) {
                char hit = 'A' + j;
                //Left / Right / Up / Down
                if(i > 0 && i < 9 && j > 0 && j < 9) {
                    int direction = rand() % 4;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 2) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                    }
                    else if(direction == 3) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Down
                else if(i == 0 && j == 0) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up
                else if(i == 9 && j == 9) {
                    int direction = rand() % 2;
                    if(direction == 0) {            //Left
                        move.row = i;               
                        move.col = j - 1 + 'A';
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Down
                else if(i == 0 && j == 9) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
            
                    }
                    else if(direction == 1) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                } 
                //Right / Up
                else if(i == 9 && j == 0) {
                    int direction = rand() % 2;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';        
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                } 
                //Left / Right / Down
                else if(i == 0 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Right / Up / Down
                else if(i > 0 && i < 9 && j == 0) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';            
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Right / Up
                else if(i == 9 && j > 0 && j < 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if(direction == 1) {
                        move.row = i;               
                        move.col = j + 1 + 'A';     //Right
                    }
                    else if(direction == 2) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                        
                    }
                    else { std::cout << "Error in direction selection!\n"; }
                }
                //Left / Up / Down
                else if(i > 0 && i < 9 && j == 9) {
                    int direction = rand() % 3;
                    if(direction == 0) {
                        move.row = i;               
                        move.col = j - 1 + 'A';     //Left
                    }
                    else if(direction == 1) {
                        move.row = i - 1;           //Up
                        move.col = j + 'A';         
                    }
                    else if(direction == 2) {
                        move.row = i + 1;           //Down
                        move.col = j + 'A';         
                    }
                    else { std::cerr << "Error in direction selection!\n"; }
                }
                else {
                    std::cerr << "Error in mediumMove row selection!\n";
                }
                //If the element selected is empty, return the move
                if(getBoard().getEnemyBoard()[(10 * move.row) + (move.col - 65)] == EnemyPiece::EMPTY) {
                    return move;
                }
            }
            count = count + 1;
        }
    }
    //If all elements have been checked for a hit and none have been found, call easymove()
    if(count >= 99) {
        move = easyMove(rand);
    }
    return move;
}

// //TODO: Implement hardMove
// Move HardPlayer::hardMove(std::mt19937_64& rand) {
//     Move move;
//     int count = 0;
//     for(size_t i = 0; i < 10; ++i) {
//         for(size_t j = 0; j < 10; ++j) {
//             char currentElement = 'A' + j;
//             if (getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::HIT) {
//                 char hit = 'A' + j;
//                 //Left / Right / Up / Down
//                 if(i > 0 && i < 9 && j > 0 && j < 9) {
//                     int direction = rand() % 4;
//                     if(direction == 0) {            //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
//                     }
//                     else if(direction == 1) {       //Right
//                         move.row = i;               
//                         moveRight(move, i, j);     
//                     }
//                     else if(direction == 2) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);         
//                     }
//                     else if(direction == 3) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Right / Down
//                 else if(i == 0 && j == 0) {
//                     int direction = rand() % 2;
//                     if(direction == 0) {            //Right
//                         move.row = i;               
//                         moveRight(move, i, j);     
//                     }
//                     else if(direction == 1) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Left / Up
//                 else if(i == 9 && j == 9) {
//                     int direction = rand() % 2;
//                     if(direction == 0) {            //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
//                     }
//                     else if(direction == 1) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Left / Down
//                 else if(i == 0 && j == 9) {
//                     int direction = rand() % 2;     
//                     if(direction == 0) {            //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
            
//                     }
//                     else if(direction == 1) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 } 
//                 //Right / Up
//                 else if(i == 9 && j == 0) {
//                     int direction = rand() % 2;
//                     if(direction == 0) {            //Right
//                         move.row = i;               
//                         moveRight(move, i, j);    
//                     }
//                     else if(direction == 1) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);        
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 } 
//                 //Left / Right / Down
//                 else if(i == 0 && j > 0 && j < 9) {
//                     int direction = rand() % 3;
//                     if(direction == 0) {            //Right
//                         move.row = i;               
//                         moveRight(move, i, j);     
//                     }
//                     else if(direction == 1) {       //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
//                     }
//                     else if(direction == 2) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Right / Up / Down
//                 else if(i > 0 && i < 9 && j == 0) {
//                     int direction = rand() % 3;
//                     if(direction == 0) {            //Right
//                         move.row = i;               
//                         moveRight(move, i, j);     
//                     }
//                     else if(direction == 1) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);            
//                     }
//                     else if(direction == 2) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Left / Right / Up
//                 else if(i == 9 && j > 0 && j < 9) {
//                     int direction = rand() % 3;
//                     if(direction == 0) {            //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
//                     }
//                     else if(direction == 1) {       //Right
//                         move.row = i;               
//                         moveRight(move, i, j);     
//                     }
//                     else if(direction == 2) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);         
                        
//                     }
//                     else { std::cout << "Error in direction selection!\n"; }
//                 }
//                 //Left / Up / Down
//                 else if(i > 0 && i < 9 && j == 9) {
//                     int direction = rand() % 3;
//                     if(direction == 0) {            //Left
//                         move.row = i;               
//                         moveLeft(move, i, j);
//                     }
//                     else if(direction == 1) {       //Up
//                         move.row = i - 1;           
//                         moveUp(move, i, j);         
//                     }
//                     else if(direction == 2) {       //Down
//                         move.row = i + 1;           
//                         moveDown(move, i, j);         
//                     }
//                     else { std::cerr << "Error in direction selection!\n"; }
//                 }
//                 else {
//                     std::cerr << "Error in mediumMove row selection!\n";
//                 }
//                 //If the element selected is empty, return the move
//                 if(getBoard().getEnemyBoard()[(10 * move.row) + (move.col - 65)] == EnemyPiece::EMPTY) {
//                     return move;
//                 }
//             }
//             count = count + 1;
//         }
//     }
//     //If all elements have been checked for a hit and none have been found, call easymove()
//     if(count >= 99) {
//         move = easyMove(rand);
//     }
//     return move;
// }

// void HardPlayer::moveLeft(Move &move, size_t i, size_t &j) {
//     bool endOfHits = false;
//     while(!endOfHits) {
//         if(getBoard().getEnemyBoard()[(10 * i) + j] != EnemyPiece::EMPTY) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10 * i) + j] != EnemyPiece::MISS) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10*i) + j] == EnemyPiece::HIT) {
//             --j;
//         }
//         else {
//             endOfHits = true;
//         }
//     }
//     move.col = j - 1 + 'A';     //Left
// }

// void HardPlayer::moveRight(Move &move, size_t i, size_t &j) {
//     bool endOfHits = false;
//     while(!endOfHits) {
//         if(getBoard().getEnemyBoard()[(10 * i) + j] != EnemyPiece::EMPTY) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10 * i) + j] != EnemyPiece::MISS) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10*i) + j] == EnemyPiece::HIT) {
//             ++j;
//         }
//         else {
//             endOfHits = true;
//         }
//     }
//     move.col = j + 1 + 'A';     //Right
// }

// void HardPlayer::moveUp(Move &move, size_t &i, size_t j) {
//     bool endOfHits = false;
//     while(!endOfHits) {
//         if(getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::EMPTY) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::MISS) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10*i) + j] == EnemyPiece::HIT) {
//             --i;
//         }
//         else {
//             endOfHits = true;
//         }
//     }
//     move.row = i - 1;           //Up
// }

// void HardPlayer::moveDown(Move &move, size_t &i, size_t j) {
//     bool endOfHits = false;
//     while(!endOfHits) {
//         if(getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::EMPTY) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10 * i) + j] == EnemyPiece::MISS) {
//             endOfHits = true;
//         }
//         else if(getBoard().getEnemyBoard()[(10*i) + j] == EnemyPiece::HIT) {
//             ++i;
//         }
//         else {
//             endOfHits = true;
//         }
//     }
//     move.row = i + 1;           //Down
// }