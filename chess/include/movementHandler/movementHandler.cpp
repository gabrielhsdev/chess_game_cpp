#include "../movementHandler/movementHandler.h"

void movementHandler::mainLoop(chessPiece* piecePtr, bool(&possibleMovesPtr)[8][8], tableSquares(&tableSquarePtr)[8][8], int * round){

	piece = piecePtr;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			possibleMoves[i][j] = &possibleMovesPtr[i][j];
			tableSquare[i][j] = &tableSquarePtr[i][j];
		}
	}

	selected_X = piece->posX;
	selected_Y = piece->posY;

	currentRound = round;

	setPossibleMoves();
}

void movementHandler::setPossibleMoves() {

	string roundOf = "black";
	if (*currentRound % 2 == 0)
		roundOf = "white";

	string str = piece->getPieceStatus("name");
	string color = piece->getPieceStatus("color");

	//Mouse click logic here
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked == false) {
		clicked = true;
		//If piece is clicked
		if (piece->status != 0 && roundOf == piece->getPieceStatus("color")) {
			selectedPiece = piece;
			unpaintActions();
			if (str == "pawn") {
				pawnMoves();
				paintActions();
			}
		}
		//If tile is clicked AFTER piece is selected
		else if (isMovementPossible() && roundOf == selectedPiece->getPieceStatus("color") && *possibleMoves[selected_X][selected_Y] == true) {
			cout << piece->getPieceStatus("name");
			movePiece();
			*currentRound = *currentRound + 1;
		}
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clicked = false;
	}
}

void movementHandler::movePiece() {
	if (*possibleMoves[selected_X][selected_Y] == true && selectedPiece != nullptr) {
		tableSquare[selected_X][selected_Y]->piece.status = selectedPiece->status;
		selectedPiece->status = 0;
	}
	else {
		selectedPiece = nullptr;
	}
	resetMovement();
	unpaintActions();
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
			if (tableSquare[x][y_cord]->piece.status != 0 && tableSquare[x][y_cord]->piece.getPieceStatus("color") != str) {
				*possibleMoves[x][y_cord] = true;
			}
		}
	}
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

void movementHandler::paintActions() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (*possibleMoves[i][j] == true) {
				tableSquare[i][j]->color_active = tableSquare[i][j]->color_action;
			}
		}
	}
}

void movementHandler::unpaintActions() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tableSquare[i][j]->color_active = tableSquare[i][j]->color_default;
		}
	}
}