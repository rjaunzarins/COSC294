/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of Game. Each Game has 2 Players, and functions which control the flow of the Game.
*/

#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game {
	public:
		/*
		Precondition: None
		Postcondition: Both types of Players (human/computer) have been set. If human, 
		name has also been set.
		*/
		void selectPlayers();

		/*
		Precondition: isRunning() is True
		Returns: Which Player's turn it is
		*/
		Player* nextPlayer();

		/*
		Precondition: isRunning() is True
		Postcondition: The board is displayed and getMove()
		of player whose move it is in invoked
		*/
		void play();

		/*
		Precondition: None
		Postcondition: The name of the winning Player (or tie) is displayed
		at the end of the game.
		*/
		void announceWinner();
		
	private:
		std::unique_ptr<Player> player1;
		std::unique_ptr<Player> player2;
		Player* currentPlayer;													//raw pointer toggles between player1 and player2
		
		/*
		Precondition: None.
		Returns: Validity of whether or not a Player is a Human Player.
		*/
		bool isHumanPlayer(Player*);

		/*
		Precondition: None.
		Returns: True if currently no winner based on currentPlayer's Board.
		*/
		bool isRunning() const;

		/*
		Precondition: User selects 'H' for Player type.
		Postcondition: A Human Player has been created and initialized.
		*/
		void createHumanPlayer(std::unique_ptr<Player>& playerIn);

		/*
		Precondition: User selects 'H' for Player type.
		Postcondition: A computer opponent has been created and initialized, with desired difficulty level set.
		*/
		void createComputerPlayer(std::unique_ptr<Player>&);

		/*
		Precondition: isRunning() is true.
		Postcondition: The winner of the game has been output to screen.
		*/
		void announceMatch(const std::unique_ptr<Player>& player1, const std::unique_ptr<Player>& player2);
};
#endif