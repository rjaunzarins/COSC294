#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

class RandomPlayer : public ComputerPlayer {
    public:
        Move getMove() override;
    private:
};

#endif