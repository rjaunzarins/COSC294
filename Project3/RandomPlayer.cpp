#include "RandomPlayer.h"

Move RandomPlayer::getMove() {
    std::mt19937_64 randomGenerator; // ( std::random_device().operator()() );
    int row = randomGenerator() % 10 + 1;
    int colNum = randomGenerator() % 10 + 1;
    char colChar;
    
    switch(colNum) {
        case 1:
            colChar = 'A';
            break;
        case 2:
            colChar = 'B';
            break;
        case 3:
            colChar = 'C';
            break;
        case 4:
            colChar = 'D';
            break;
        case 5:
            colChar = 'E';
            break;
        case 6:
            colChar = 'F';
            break;
        case 7:
            colChar = 'G';
            break;
        case 8:
            colChar = 'H';
            break;
        case 9:
            colChar = 'I';
            break;
        case 10:
            colChar = 'J';
            break;
        default:
            colChar = 'A';
            std::cerr << "Error in random conversion!\n";
    }
    return Move(row,colChar);
}