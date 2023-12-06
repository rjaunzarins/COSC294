/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of a Move. Each Player can make Moves against their enemy, to try to sink all of their ships.
These moves are reflected during gameplay, on the player board of the Player's enemy. They are also shown as
'hit's and 'miss'es on the Player's enemy board.
*/

#ifndef MOVE_H
#define MOVE_H
#include <iostream>

struct Move {
	int row;
	char col;

	/*
	Precondition: None.
	Postcondition: A Move has been created and initialized.
	*/
	Move(int row, char col);

	/*
	Precondition: None.
	Postcondition: A Move has been created.
	*/
	Move() = default;

	/*
	 Precondition: User must supply a valid row and col combination.
	 Returns: Index covnersion of int/char supplied.
	*/
	int getIndex();

	/*
	Precondition: A valid Move should be supplied.
	Returns: Istream which reads input directly to a Move.
	*/
	friend std::istream& operator>>(std::istream&, Move&);
};
#endif
