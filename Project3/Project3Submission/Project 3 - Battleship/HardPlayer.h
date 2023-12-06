/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Hard Player, derived from Computer Player.
*/
#ifndef HARDPLAYER_H
#define HARDPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

class HardPlayer : public ComputerPlayer {
    public:
        /*
        Precondition: None.
        Returns: Move of Hard Player.
        */
        Move getMove() override;
        
    private:
        /*
       Precondition: None.
       Returns: Easy difficulty Move.
       */
        Move easyMove(std::mt19937_64&);

        /*
       Precondition: None.
       Returns: Medium difficulty Move.
       */
        Move mediumMove(std::mt19937_64&);
};
#endif
