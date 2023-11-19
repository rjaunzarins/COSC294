#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"

class ComputerPlayer : public Player {
    public:
        ComputerPlayer();
    private:
        static char sharedCounter;
        std::string name = "Computer ";
};

#endif