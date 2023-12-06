/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Human Player, derived from Player.
*/

#include "HumanPlayer.h"
#include <string>
#include <iostream>


HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}


Move HumanPlayer::getMove() {
	Move move;
	bool isValid = false;

	while (!isValid) {
		std::cout << "enter row [0-9], followed by col [A-J] to make your move: ";				//prompt Human for move and check if it's legal

		if (std::cin >> move) {
			if ((move.row >= 0 && move.row <= 9) && (move.col >= 65 && move.col <= 74)) {
				isValid = true;
			}
			else {
				std::cout << "\nInvalid input, ";
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return move;
}