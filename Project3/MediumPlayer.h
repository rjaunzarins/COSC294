#ifndef MEDIUMPLAYER_H
#define MEDIUMPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

class MediumPlayer : public ComputerPlayer {
    public:
        Move getMove() override;
        Move easyMove(std::mt19937_64&);
        Move mediumMove(std::mt19937_64&);
    private:
};

#endif