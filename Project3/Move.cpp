#include "Move.h"
#include <iostream>

int Move::getIndex() {
    int conversion;
    switch(col) {
        case 'A':
            conversion = 0;
            break;
        case 'B':
            conversion = 10;
            break;
        case 'C':
            conversion = 20;
            break;
        case 'D':
            conversion = 30;
            break;
        case 'E':
            conversion = 40;
            break;
        case 'F':
            conversion = 50;
            break;
        case 'G':
            conversion = 60;
            break;
        case 'H':
            conversion = 70;
            break;
        case 'I':
            conversion = 80;
            break;
        case 'J':
            conversion = 90;
            break;   
        default:
            conversion = 0;
            std::cerr << "Error in conversion!" << "\n";                                                                  
    }
    return row + conversion;
}

char convertToChar(int numToConvert) {
    return static_cast<char>(numToConvert);
}