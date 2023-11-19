#include "ComputerPlayer.h"

char ComputerPlayer::sharedCounter = 'A';

ComputerPlayer::ComputerPlayer() : Player(name += sharedCounter) { 
    ++sharedCounter;
}