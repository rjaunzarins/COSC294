/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Medium Player, derived from Computer Player.
*/

#ifndef MEDIUMPLAYER_H
#define MEDIUMPLAYER_H
#include "ComputerPlayer.h"
#include <random>
#include <memory>

class MediumPlayer : public ComputerPlayer {
    public:

        /*
        Precondition: None.
        Returns: Move of Medium Player.
        */
        Move getMove() override;

    private:

        /*
        Precondition: None.
        Returns: Easy Move (when no Hits detectable)
        */
        Move easyMove(std::mt19937_64&);

        /*
        Precondition: None.
        Returns: Medium Move.
        */
        Move mediumMove(std::mt19937_64&);
};
#endif
