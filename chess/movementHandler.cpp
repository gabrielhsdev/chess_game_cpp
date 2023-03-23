#include "movementHandler.h"

movementHandler::movementHandler() {

}

void movementHandler::resetMovement(bool(&possibleMoves)[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			possibleMoves[i][j] = false;
		}
	}
}

bool  movementHandler::isMovementPossible(bool(&possibleMoves)[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (possibleMoves[i][j] == true) {
				return true;
			}
		}
	}
	return false;
}

void movementHandler::setPossibleMoves(chessPiece* piece, bool(&possibleMoves)[8][8], tableSquares(&tableSquares)[8][8]) {
	string str = piece->getPieceStatus("name");
	string color = piece->getPieceStatus("color");
	
	//One click function
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked == false) {
		clicked = true;
		lastSelected = nullptr;
	} else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked == true) {
		clicked = false;
		lastSelected = nullptr;
	}
	if (clicked == true) {
		cout << "\nClicked on: " << color << " " << str;
		if (str == "pawn") {
			pawnMoves(piece, possibleMoves, tableSquares);
			setMovementColors(possibleMoves, tableSquares);
		}
		lastSelected = piece;
	}
	else {
		resetColors(tableSquares);
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

void movementHandler::setMovementColors(bool(&possibleMoves)[8][8], tableSquares(&tableSquares)[8][8]) 
{
	resetColors(tableSquares);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (possibleMoves[i][j] == true) {
				tableSquares[i][j].color_active = tableSquares[i][j].color_action;
			}
		}
	}
}

void movementHandler::resetColors(tableSquares(&tableSquares)[8][8]){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tableSquares[i][j].color_active = tableSquares[i][j].color_default;
		}
	}
}