#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"

class ComputerPlayer : public Player {
    public:
        ComputerPlayer();
    private:
        std::string generateName();
        static char sharedCounter;
        
};

#endif