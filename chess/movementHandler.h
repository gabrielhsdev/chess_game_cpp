#pragma once
#include "chessPiece.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class movementHandler
{
	public:
		//This is always changing
		bool possibleMoves[8][8];
		movementHandler();
		void resetMovement();
		void setPossibleMoves(chessPiece* piece);
		void pawnMoves(chessPiece* piece);

};

