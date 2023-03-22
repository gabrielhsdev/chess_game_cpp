#include "movementHandler.h"

movementHandler::movementHandler() {

}

void movementHandler::resetMovement(bool(&possibleMoves)[8][8]) {
	for (int i = 0; i < 8-1; i++) {
		for (int j = 0; j < 8 - 1; j++) {
			possibleMoves[i][j] = false;
		}
	}
}

void movementHandler::setPossibleMoves(chessPiece* piece, bool(&possibleMoves)[8][8], tableSquares(&tableSquares)[8][8]) {
	resetMovement(possibleMoves);
	string str = piece->getPieceStatus("name");
	if (str == "pawn") {
		pawnMoves(piece, possibleMoves, tableSquares);
	}
}

void movementHandler::pawnMoves(chessPiece* piece, bool(&possibleMoves)[8][8], tableSquares(&tableSquares)[8][8]) {
	resetMovement(possibleMoves);
	string str = piece->getPieceStatus("color");
	int x = 0, y = 0;
	//Black
	int add = 1;

	if (piece->getPieceStatus("color") == "white") {
		add = -1;
	}

	x = piece->posX + add;
	y = piece->posY;

	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		possibleMoves[x][y] = true;
		cout << "\ncan move to" << x << "," << y;
	}

	//Check for possible attack moves on left and right
	if ( (y+1)>=0 && (y-1)<= 7) {
		if (tableSquares[x][y].piece.status != 0) {
			cout << "can attack 1";
		}
		else {
			cout << "cant attack 1";
		}
	}

}