#include "RandomPlayer.h"


Move RandomPlayer::getMove() {
    //Seed Generator
    std::random_device randomGenerator;
    //Mersenne Twister
    std::mt19937_64 rand(randomGenerator());
    Move move;
    move.row = rand() % 10;
    move.col = rand() % 10 + 'A';
    return move;
}
