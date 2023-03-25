#pragma once
#include "../chessPiece/chessPiece.h"
#include "../tableSquares/tableSquares.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class movementHandler
{
	public:

		int selected_X;
		int selected_Y;
		int* matchWinner;
		int * currentRound;
		bool clicked = false;

		bool* possibleMoves[8][8];
		chessPiece* piece;
		chessPiece* selectedPiece = nullptr;
		tableSquares* tableSquare[8][8];

		//Main action functions
		void mainLoop(chessPiece* piecePtr, bool(&possibleMovesPtr)[8][8], tableSquares(&tableSquarePtr)[8][8], int * round, int * winner);
		void resetMovement();
		void setPossibleMoves();
		bool isMovementPossible();
		void paintActions();
		void unpaintActions();
		void checkWinner();

		//Piece movement
		void movePiece();
		void pawnMoves();
		void pawnToQueen();
		void rookMoves();
		void bishopMoves();
		void knightMoves();
		void kingMoves();
		void queenMoves();

};

