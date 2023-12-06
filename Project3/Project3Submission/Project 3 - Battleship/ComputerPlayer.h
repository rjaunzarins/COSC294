/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of Computer Player, derived from Player. The user may select Computer Player as one
of the Players. Its Moves during gameplay are "automatic".
*/

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include <string>
#include "Player.h"

class ComputerPlayer : public Player {
	public:
		ComputerPlayer();
	
	private:
		std::string generateName();
		static char sharedCounter;						//increments letters for Computer Players' names
};
#endif