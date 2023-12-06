/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Random Player, derived from Computer Player.
*/

#include "RandomPlayer.h"

Move RandomPlayer::getMove() {
	std::random_device randomGenerator;
	std::mt19937_64 rand(randomGenerator());
	Move move;
	move.row = rand() % 10;
	move.col = rand() % 10 + 'A';
	return move;											//return random move	
}

