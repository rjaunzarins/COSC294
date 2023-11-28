#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

enum class Difficulty { EASY, MEDIUM, HARD };

class RandomPlayer : public ComputerPlayer {
    public:
        //RandomPlayer() : ComputerPlayer() {}
        Move getMove() override;
        Move getMove(Difficulty);
    private:
        Move easyMove(std::mt19937_64&);
        Move mediumMove(std::mt19937_64&);
        Move hardMove(std::mt19937_64&);
};

#endif