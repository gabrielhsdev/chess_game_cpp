#pragma once
#include "chessPiece.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class movementHandler
{
	public:
		movementHandler();
		void resetMovement(bool(&possibleMoves)[8][8]);
		void setPossibleMoves(chessPiece* piece, bool(&possibleMoves)[8][8]);
		void pawnMoves(chessPiece* piece, bool(&possibleMoves)[8][8]);
};

