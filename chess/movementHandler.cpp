#include "movementHandler.h"

movementHandler::movementHandler() {
	resetMovement();
}

void movementHandler::resetMovement() {
	for (int i = 0; i < 8-1; i++) {
		for (int j = 0; j < 8 - 1; j++) {
			possibleMoves[i][j] = false;
		}
	}
}

void movementHandler::setPossibleMoves(chessPiece* piece) {
	resetMovement();
	string str = piece->getPieceStatus("name");
	if (str == "pawn") {
		pawnMoves(piece);
	}
}

void movementHandler::pawnMoves(chessPiece* piece) {
	resetMovement();
	string str = piece->getPieceStatus("color");
	int x = 0, y = 0;
	//Black
	if (piece->getPieceStatus("color") == "black") {
		x = piece->posX - 1;
		y = piece->posY;
		if (x > 0 && x < 8 && y > 0 && y < 8) {
			possibleMoves[x][y] = true;
			cout << "can move to" << x << y;
		}
	}
}