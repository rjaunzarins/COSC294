/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Declaration of Board. Each Player has a Board, and each Board includes a representation of the Player's
player board (where their own ships are placed) and enemy board (a grid representing the enemy's player board space),
which accumulates 'hit's and 'miss'es after the Player makes Moves against their enemy.
*/

#ifndef BOARD_H
#define BOARD_H
#include "Move.h" 
#include <random>
#include <iostream>

enum class EnemyPiece {HIT, MISS, EMPTY};														//representation of the result of Player's Moves against the enemy

enum class PlayerPiece {AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY, DAMAGE};		//representation of status of Player's player board

class Board {
	public:
		/*
		Precondition: A Player object must be initialized.
		Postcondition: The Board has been initialized, via reset().
		*/
		Board();

		/*
		Precondition: A Board must be initialized.
		Postcondtion: Memory allocated for the Board object was freed.
		*/
		~Board();

		/*
		Precondition: A Player object must be initialized.
		Returns: Player's representation of their enemy board.
		*/
		EnemyPiece* getEnemyArr() const noexcept { return enemyArrPtr; }

		/*
		Precondition: A Player object must be initialized.
		Returns: Player's representation of their player board.
		*/
		PlayerPiece* getPlayerArr() const noexcept { return playerArrPtr; }
		
		/*
		Precondition: A Board object must exist.
		Postcondition: Current Board was reset to empty, then 5 ships
		types have been randomly placed within Player's pieces' array.
		*/
		void reset();

		/*
		Precondition: A Game must be in play.
		Postcondition: The player's or enemy's Move has been indicated.
		*/
		void makeMove(Move, Board&);

		/*
		Precondition: A Game must be in play.
		Returns: False if play is out of bounds or if Move has already been
		done on enemy's board. Otherwise true.
		*/
		bool isLegal(Move) const;

		/*
		Precondition: A Board object must have been initialized.
		Returns: Ostream with data representing a Board, for output.
		*/
		friend std::ostream& operator<<(std::ostream&, const Board&);

	private:
		PlayerPiece *playerArrPtr;																	//Player's representation of their own ship placement
		EnemyPiece *enemyArrPtr;																	//Player's representation of where they've hit or missed on enemy board

		/*
		Precondtion: reset() must have been called (helper function).
		Postcondition: A random number has been generate for ship placement.
		*/
		void initializePlayerBoard();

		/*
		Precondition: reset() must have been called (helper function).
		Postcondition: Ships have been placed on the board.
		*/
		void placeShips(size_t, std::mt19937_64);

		/*
		Precondition: reset() must have been called (helper function).
		Postcondition: The type of ship has been determined for all ships.
		*/
		void setBoatType(size_t, size_t&, PlayerPiece&);
		
		/*
		Precondition: reset() must have been called (helper function).
		Returns: Validity of whether or not a ship can fit on the board,
		given its size and board boundaries.
		*/
		bool isShipPlacementLegal(Move&, bool, int, int);

		/*
		Precondition: isShipPlacementLegal() helper function.
		Returns: Validity of whether or not the ship will be out of bounds.
		*/
		bool isLegalPlacement(Move);

		/*
		Precondition: reset() must have been called (helper function).
		Postcondition: The ships have been legally placed on the board.
		*/
		void makePlacement(PlayerPiece&, bool, int, int);
};
#endif
