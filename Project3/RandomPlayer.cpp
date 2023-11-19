#include "RandomPlayer.h"

Move RandomPlayer::getMove() {
    std::mt19937_64 randomGenerator; // ( std::random_device().operator()() );
    Move move;
    move.row = randomGenerator() % 10 + 1;
    int colNum = randomGenerator() % 10 + 1;
    switch(colNum) {
        case 1:
            move.col = 'A';
            break;
        case 2:
            move.col = 'B';
            break;
        case 3:
            move.col = 'C';
            break;
        case 4:
            move.col = 'D';
            break;
        case 5:
            move.col = 'E';
            break;
        case 6:
            move.col = 'F';
            break;
        case 7:
            move.col = 'G';
            break;
        case 8:
            move.col = 'H';
            break;
        case 9:
            move.col = 'I';
            break;
        case 10:
            move.col = 'J';
            break;
        default:
            move.col = 'A';
            std::cerr << "Error in random conversion!\n";
    }
    //return Move(row,colChar); //!cannot do this becuase construct doesnt exist like this
    return move;
}