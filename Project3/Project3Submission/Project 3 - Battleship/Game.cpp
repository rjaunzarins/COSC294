/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Implementation of a Battleship Game.
*/

#include "Game.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"
#include <memory> 
#include <string>
#include <iostream>

void Game::selectPlayers() {
	char userSelection = 'a';
	while (userSelection != 'c' && userSelection != 'C' && userSelection != 'h' && userSelection != 'H') {
		std::cout << "\nEnter Player1 type [C/H]: ";
		std::cin >> userSelection;

		if (userSelection == 'h' || userSelection == 'H') {
			std::cout << "\nEnter Player1 name: ";
			createHumanPlayer(player1);
		}
		else if (userSelection == 'c' || userSelection == 'C') {
			createComputerPlayer(player1);
		}
	}

	userSelection = 'a';																		//code reuse, but can't really implement differently without changing the selectPlayers() header
	while (userSelection != 'c' && userSelection != 'C' && userSelection != 'h' && userSelection != 'H') {
		std::string playerName;
		std::cout << "\nEnter Player2 type [C/H]: ";
		std::cin >> userSelection;

		if (userSelection == 'h' || userSelection == 'H') {
			std::cout << "\nEnter Player2 name: ";
			createHumanPlayer(player2);
		}
		else if (userSelection == 'c' || userSelection == 'C') {
			createComputerPlayer(player2);
		}
	}
	announceMatch(player1, player2);
	currentPlayer = player2.get();																//set to player2 so it switches to player1 on first iteration of game loop
}


void Game::createHumanPlayer(std::unique_ptr<Player>& playerIn) {								//create Human Player
	std::string playerName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, playerName);
	playerIn = std::make_unique<HumanPlayer>(playerName);
}


void Game::createComputerPlayer(std::unique_ptr<Player>& currentPlayerSelection) {				//create Computer Player, with desired difficulty level
	char difficulty;
	bool isValid = false;

	while (!isValid) {
		std::cout << "\nEnter computer difficulty level [E/M/H]: ";

		if (std::cin >> difficulty) {
			if (difficulty == 'E' || difficulty == 'e') {
				isValid = true;
				currentPlayerSelection = std::make_unique<RandomPlayer>();
			}
			else if (difficulty == 'M' || difficulty == 'm') {
				isValid = true;
				currentPlayerSelection = std::make_unique<MediumPlayer>();
			}
			else if (difficulty == 'H' || difficulty == 'h') {
				isValid = true;
				currentPlayerSelection = std::make_unique<HardPlayer>();
			}
			else {
				std::cerr << "\nError in difficulty selection.";
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}


Player* Game::nextPlayer()  {
	return (currentPlayer == player1.get()) ? player2.get() : player1.get();
}


bool Game::isRunning() const {
	size_t count = 0;

	for (size_t i = 0; i < 100; ++i) {
		if (currentPlayer->getBoard().getEnemyArr()[i] == EnemyPiece::HIT) {
			++count;
		}
	}
	return (count < 17) ? true : false;																//17 is the total num of hits needed to sink all 5 ships
}


bool Game::isHumanPlayer(Player* currentPlayer) {
	if (currentPlayer == dynamic_cast<HumanPlayer*>(currentPlayer)) {
		return true;
	}
	return false;
}


void Game::play() {
	while (isRunning()) {
		currentPlayer = nextPlayer();																//switch to player1 for first play
		std::cout << "\n\n" << currentPlayer->getName() << "'s Enemy Board & Player Board:\n";
		std::cout << currentPlayer->getBoard();														//display board
		
		if (isHumanPlayer(currentPlayer)) {
			std::cout << "\n" << currentPlayer->getName() << ", ";
		}
		else {
			std::cout << "\n" << currentPlayer->getName() << " has made its move.";					//announce Computer player made its move
		}

		Move playerMove = currentPlayer->getMove();
		while (!currentPlayer->getBoard().isLegal(playerMove)) {									//if move isn't legal
			if (isHumanPlayer(currentPlayer)) {
				std::cout << "\nInvalid move, ";
			}
			playerMove = currentPlayer->getMove();
		}
		if (currentPlayer == player1.get()) {
			currentPlayer->getBoard().makeMove(playerMove, player2->getBoard());
		}
		else {
			currentPlayer->getBoard().makeMove(playerMove, player1->getBoard());					//make the move on the correct board
		}
	}
}


void Game::announceMatch(const std::unique_ptr<Player>& player1, const std::unique_ptr<Player>& player2) {
	std::cout << "\n-----------------------------------------";
	std::cout << "\n     " << player1->getName() << " vs. " << player2->getName() << "" << "     \n";
	std::cout << "-----------------------------------------\n";
}


void Game::announceWinner() {
	if (!isRunning()) {
		std::cout << "\n\nThe winner is " << currentPlayer->getName() << ", with winning board: \n" << currentPlayer->getBoard();
		currentPlayer = nullptr;																	//avoid dangling pointer
	}
}
