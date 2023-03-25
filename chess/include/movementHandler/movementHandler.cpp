#include "../movementHandler/movementHandler.h"

void movementHandler::mainLoop(chessPiece* piecePtr, bool(&possibleMovesPtr)[8][8], tableSquares(&tableSquarePtr)[8][8], int * round, int * winner){

	matchWinner = winner;
	currentRound = round;
	piece = piecePtr;
	selected_X = piece->posX;
	selected_Y = piece->posY;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			possibleMoves[i][j] = &possibleMovesPtr[i][j];
			tableSquare[i][j] = &tableSquarePtr[i][j];
		}
	}

	setPossibleMoves();
}

void movementHandler::setPossibleMoves() {

	//Color round
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
			if (str == "rook") {
				rookMoves();
				paintActions();
			}
			if (str == "bishop") {
				bishopMoves();
				paintActions();
			}
			if (str == "knight") {
				knightMoves();
				paintActions();
			}
			if (str == "queen") {
				queenMoves();
				paintActions();
			} 
			if (str == "king") {
				kingMoves();
				paintActions();
			}
		}
		//If tile is clicked AFTER piece is selected
		else if (isMovementPossible() && roundOf == selectedPiece->getPieceStatus("color") && *possibleMoves[selected_X][selected_Y] == true) {
			movePiece();
			*currentRound = *currentRound + 1;
		}
	}
	else
		clicked = false;
}

void movementHandler::movePiece() {

	if (*possibleMoves[selected_X][selected_Y] == true && selectedPiece != nullptr) {

		tableSquare[selected_X][selected_Y]->piece.status = selectedPiece->status;

		//Check if upgrade is avaliable
		pawnToQueen();

		selectedPiece->status = 0;

	}
	else
		selectedPiece = nullptr;

	resetMovement();
}

void movementHandler::checkWinner() {
	
	bool blackKing = false;
	bool whiteKing = false;
	//6 black 12 white
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tableSquare[i][j]->piece.status == 6) {
				blackKing = true;
			}
			if (tableSquare[i][j]->piece.status == 12) {
				whiteKing = true;
			}
		}
	}

	if (blackKing == false) {
		*matchWinner = 1;
	}
	if (whiteKing == true ) {
		*matchWinner = 2;
	}

}

void movementHandler::pawnToQueen() {

	string pieceColor = selectedPiece->getPieceStatus("color");
	string pieceName = selectedPiece->getPieceStatus("name");
	
	if (pieceName == "pawn") {
		if (pieceColor == "white" && selected_X == 0) {
			tableSquare[selected_X][selected_Y]->piece.status = 11;
		}
		else if (pieceColor == "black" && selected_X == 7) {
			tableSquare[selected_X][selected_Y]->piece.status = 5;
		}
	}

}

void movementHandler::resetMovement() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			*possibleMoves[i][j] = false;
		}
	}

	unpaintActions();

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