#include "ComputerPlayer.h"

char ComputerPlayer::sharedCounter = 'A';

ComputerPlayer::ComputerPlayer() : Player(generateName()) {
    ++sharedCounter;
}

std::string ComputerPlayer::generateName() {
    return "Computer " + std::string(1, sharedCounter);
}