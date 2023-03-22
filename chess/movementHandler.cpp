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

	//Cancel function if we cannot move foward, pawn becomes queen ? (create pawn_to_queen function)
	if (x > 7 || x < 0)
		return;

	//Check if we can move to the next square
	if (x >= 0 && x <= 7 && tableSquares[x][y].piece.status == 0) {
		possibleMoves[x][y] = true;
	}

	//Check for possible attack moves on left and right
	for (int add = -1; add <= 1; add += 2) {
		int y_cord = y + add;
		if (y_cord >= 0 && y_cord <= 7) {
			if (tableSquares[x][y_cord].piece.status != 0) {
				possibleMoves[x][y_cord] = true;
			}
		}

	}



}