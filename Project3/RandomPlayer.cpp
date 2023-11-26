#include "RandomPlayer.h"


Move RandomPlayer::getMove() {
    return getMove(Difficulty::EASY);
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

Move RandomPlayer::mediumMove(std::mt19937_64& rand) {
    Move move;
    //TODO: Implement mediumMove
    //TODO: search through array, if no hits, call getMove()
    //TODO: if hit is found, move = -1, +1, -10, or +10
    return move;
}

Move RandomPlayer::hardMove(std::mt19937_64& rand) {
    Move move;
    //TODO: Implement hardMove
    //TODO: search through array, if no hits, call getMove()
    //TODO: if his is found, search to see if there are more than one hits in a row
    //TODO: it there are, continue in +ve or -ve direction
    return move;
}

// move.row = rand() % 10 + 1;
//     int colNum = rand() % 10 + 1;
//     switch(colNum) {
//         case 1:
//             move.col = 'A';
//             break;
//         case 2:
//             move.col = 'B';
//             break;
//         case 3:
//             move.col = 'C';
//             break;
//         case 4:
//             move.col = 'D';
//             break;
//         case 5:
//             move.col = 'E';
//             break;
//         case 6:
//             move.col = 'F';
//             break;
//         case 7:
//             move.col = 'G';
//             break;
//         case 8:
//             move.col = 'H';
//             break;
//         case 9:
//             move.col = 'I';
//             break;
//         case 10:
//             move.col = 'J';
//             break;
//         default:
//             move.col = 'A';
//             std::cerr << "Error in random conversion!\n";
//     }
//     //return Move(row,colChar); //!cannot do this becuase construct doesnt exist like this
//     return move;