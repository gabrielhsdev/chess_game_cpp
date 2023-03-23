#include "movementHandler.h"

movementHandler::movementHandler() {

}

void movementHandler::mainLoop(chessPiece* piecePtr, bool(&possibleMovesPtr)[8][8], tableSquares(&tableSquarePtr)[8][8]){

	piece = piecePtr;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			possibleMoves[i][j] = &possibleMovesPtr[i][j];
			tableSquare[i][j] = &tableSquarePtr[8][8];
		}
	}

	selected_X = piece->posX;
	selected_Y = piece->posY;

	setPossibleMoves();
}

void movementHandler::resetMovement() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			*possibleMoves[i][j] = false;
		}
	}
}

bool  movementHandler::isMovementPossible() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (*possibleMoves[i][j] == true) {
				return true;
			}
		}
	}
	return false;
}

void movementHandler::setPossibleMoves() {

	string str = piece->getPieceStatus("name");
	string color = piece->getPieceStatus("color");

	if (str == "pawn") {
		pawnMoves();
		cout << "calculate pawn\n";
	}
}

void movementHandler::pawnMoves() {
	resetMovement();

	string str = piece->getPieceStatus("color");

	//Black
	int add = 1;

	if (piece->getPieceStatus("color") == "white") {
		add = -1;
	}

	int x = selected_X + add;
	int y = selected_Y;

	//Cancel function if we cannot move foward, pawn becomes queen ? (create pawn_to_queen function)
	if (x > 7 || x < 0)
		return;

	//Check if we can move to the next square
	if (x >= 0 && x <= 7 && tableSquare[x][y]->piece.status == 0) {
		*possibleMoves[x][y] = true;
	}

	//Check for possible attack moves on left and right
	for (int add = -1; add <= 1; add += 2) {
		int y_cord = y + add;
		if (y_cord >= 0 && y_cord <= 7) {
			if (tableSquare[x][y_cord]->piece.status != 0) {
				*possibleMoves[x][y_cord] = true;
			}
		}
	}
}