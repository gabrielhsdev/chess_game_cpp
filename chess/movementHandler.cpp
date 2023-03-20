#include "movementHandler.h"

movementHandler::movementHandler() {
	resetMovement();
}

//pawn = 0; knight = 16; rook = 32; nbishop = 48; queen = 64; king = 80;
string movementHandler::getPieceName(chessPiece* piece) {
	string str = "";

	if (piece->status == 1)
		str = "pawn_black";
	if (piece->status == 7)
		str = "pawn_white";

	if (piece->status == 2)
		str = "knight_black";
	if (piece->status == 8)
		str = "knight_white";
	
	if (piece->status == 3)
		str = "rook_black";
	if(piece->status == 9)
		str = "rook_white";

	if (piece->status == 4)
		str = "bishop_black";
	if (piece->status == 10)
		str = "bishop_white";

	if (piece->status == 5)
		str = "queen_black";
	if (piece->status == 11)
		str = "queen_white";

	if (piece->status == 6)
		str = "king_black";
	if (piece->status == 12)
		str = "king_white";

	if (str.empty() == true && piece->status != 0)
		cerr << "Wrong piece id status movementHandler";


	return str;
}

void movementHandler::resetMovement() {
	for (int i = 0; i < 8-1; i++) {
		for (int j = 0; j < 8 - 1; j++) {
			possibleMoves[i][j] = false;
		}
	}
}

void movementHandler::setPossibleMoves(chessPiece* piece) {
	//resetMovement();
	string str = getPieceName(piece);
	int x = 0, y = 0;
	if (str == "pawn_white") {
		x = piece->posX - 1;
		y = piece->posY;
		if (x > 0 && x < 8 && y > 0 && y < 8) {
			possibleMoves[x][y] = true;
		}
	}
}