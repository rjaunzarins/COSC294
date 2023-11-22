#include "ComputerPlayer.h"

char ComputerPlayer::sharedCounter = 'A';

ComputerPlayer::ComputerPlayer() : name("Computer " + std::string(1, sharedCounter)), Player(name) { 
    ++sharedCounter;
}