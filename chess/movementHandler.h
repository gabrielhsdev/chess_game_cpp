#pragma once
#include "chessPiece.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class movementHandler
{
	public:
		bool possibleMoves[8][8];
		movementHandler();
		void resetMovement();
		string getPieceName(chessPiece* piece);
		void setPossibleMoves(chessPiece* piece);
};

