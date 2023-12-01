#ifndef HARDPLAYER_H
#define HARDPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

class HardPlayer : public ComputerPlayer {
    public:
        Move getMove() override;
        Move easyMove(std::mt19937_64&);
        Move mediumMove(std::mt19937_64&);
        Move hardMove(std::mt19937_64&);
    private:
};

#endif