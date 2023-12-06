/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Computer Player, derived from Player.
*/

#include "ComputerPlayer.h"
char ComputerPlayer::sharedCounter = 'A';


ComputerPlayer::ComputerPlayer() : Player(generateName()) {
	if (sharedCounter == 'Z') {
		sharedCounter = 'A';
	}
	else {
		++sharedCounter;
	}																
}


std::string ComputerPlayer::generateName() {
	return "Computer " + std::string(1, sharedCounter);							//set Computer Player name to "Computer" and current increment of the shared counter
}