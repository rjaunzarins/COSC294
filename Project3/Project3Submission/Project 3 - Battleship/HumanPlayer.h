/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Human Player, derived from Player. The user may choose a Human Player as a Player during gameplay.
The user must make the moves for the Human Player.
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <string>
#include "Player.h"

class HumanPlayer : public Player {
	public:
		/*
		Precondition: None.
		Postcondition: A Human Player has been created and initialized.
		*/
		HumanPlayer(const std::string&); 
		
		/*
		Precondition: A Player must be initialized.
		Returns: Desired Move of Human Player.
		*/
		Move getMove() override;
};
#endif
