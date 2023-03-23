#pragma once
#include "chessPiece.h"
#include "tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class movementHandler
{
	public:

		int selected_X;
		int selected_Y;

		chessPiece* piece;
		bool* possibleMoves[8][8];
		tableSquares* tableSquare[8][8];

		movementHandler();
		void mainLoop(chessPiece* piecePtr, bool(&possibleMovesPtr)[8][8], tableSquares(&tableSquarePtr)[8][8]);
		void resetMovement();
		void setPossibleMoves();
		void pawnMoves();
		bool isMovementPossible();
};

