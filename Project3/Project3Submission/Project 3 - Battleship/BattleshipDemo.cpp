/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

This is a demo of the game Battleship. It starts a game, prompts for 2 players (computer or human), then
runs until there is a winner. Once a game finishes, it prompts the user to play again.
*/

#include "Board.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Move.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"
#include <iostream>
void printBattleship();
bool playAgain();


int main() {
	do {
		printBattleship();
		Game battleShipGame;
		battleShipGame.selectPlayers();
		battleShipGame.play();
		battleShipGame.announceWinner();
	} while (playAgain());
}

void printBattleship() {
	std::cout << "\n\n\n\n";
	std::cout << "      BattleShip Game\n";
	std::cout << "                                         # #  ( )\n";
	std::cout << "                                  ___#_#___|__\n";
	std::cout << "                              _  |____________|  _\n";
	std::cout << "                       _=====| | |            | | |==== _\n";
	std::cout << "                 =====| |.---------------------------. | |====\n";
	std::cout << "   <--------------------'   .  .  .  .  .  .  .  .   '--------------/\n";
	std::cout << "    \\                                                              /\n";
	std::cout << "     \\____________________________________________________________/\n";
	std::cout << "  wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
	std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
	std::cout << "   wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
}

bool playAgain() {
	char playChoice;
	std::cout << "\nPlay again (y/n)? : ";
	std::cin >> playChoice;
	if (playChoice == 'y' || playChoice == 'Y') {
		return true;
	}
	return false;
}
