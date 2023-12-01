#include "ComputerPlayer.h"

char ComputerPlayer::sharedCounter = 'A';

ComputerPlayer::ComputerPlayer() : Player(generateName()) {
    if(sharedCounter == 'Z') {                                      
        sharedCounter = 'A';
    }    
    else {
        ++sharedCounter;
    }
}

std::string ComputerPlayer::generateName() {
    return "Computer " + std::string(1, sharedCounter);
}