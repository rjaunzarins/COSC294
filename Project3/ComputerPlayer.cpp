#include "ComputerPlayer.h"

char ComputerPlayer::sharedCounter = 'A';

ComputerPlayer::ComputerPlayer() : Player("Computer " + sharedCounter) { 
    ++sharedCounter;
}