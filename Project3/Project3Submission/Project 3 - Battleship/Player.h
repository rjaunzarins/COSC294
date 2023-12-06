/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Player. This is an abstract base class for specific Player types.
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Move.h"
#include "Board.h"

class Player {
	public:
		
		/*
		Precondition: None.
		Postcondition: A (type of) Player has been created and initialized.
		*/
		Player(const std::string&);
		
		/*
		Precondition: A Player must be created and initialized.
		Returns: The name of a Player.
		*/
		const std::string& getName() const { return playerName; }

		/*
		Precondition: A Player must be created.
		Postcondition: The name of a Player has been set.
		*/
		//void setName(const std::string& nameIn) { playerName = nameIn; }
		
		/*
		Precondition: None.
		Postcondition: Virtual function declaration for derived classes.
		*/
		virtual Move getMove() = 0;														//pure virtual function
	
		/*
		Precondition: None.
		Returns: Player's Board.
		*/
		Board& getBoard() { return playerBoard; }

		/*
		Precondition: A Player must have been created.
		Postcondition: The memory allocated for Player has been freed.
		*/
		virtual ~Player() = default;

	private:
		std::string playerName;
		Board playerBoard;
};
#endif
