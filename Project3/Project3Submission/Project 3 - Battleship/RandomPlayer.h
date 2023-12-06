/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Random Player, dervied from Computer Player. A Random Player's Moves
are easy.
*/

#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include <random>
#include <memory>
#include "ComputerPlayer.h"


class RandomPlayer : public ComputerPlayer {
	public:

		/*
		Precondition: None.
		Returns: Move of Random Player.
		*/
		Move getMove() override;
};
#endif
