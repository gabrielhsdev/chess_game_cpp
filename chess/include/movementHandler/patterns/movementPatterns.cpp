#include "../movementHandler/movementHandler.h"

void movementHandler::pawnMoves() {

	resetMovement();

	//Get pawn movement direction
	int add;
	string str = piece->getPieceStatus("color");
	if (piece->getPieceStatus("color") == "white")
		add = -1;
	else
		add = 1;

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

void movementHandler::rookMoves() {

	resetMovement();
	
	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			if (tableSquare[nx][ny]->piece.status == 0) {
				*possibleMoves[nx][ny] = true;
			}
			else if (tableSquare[nx][ny]->piece.getPieceStatus("color") != str) {
				*possibleMoves[nx][ny] = true;
				break;
			}
			else {
				break;
			}
			nx += dx[i];
			ny += dy[i];
		}
	}

}

void movementHandler::bishopMoves() {

	resetMovement();

	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");

	int dx[4] = { 1, -1,  1, -1 };
	int dy[4] = { 1, -1, -1,  1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			if (tableSquare[nx][ny]->piece.status == 0) {
				*possibleMoves[nx][ny] = true;
			}
			else if (tableSquare[nx][ny]->piece.getPieceStatus("color") != str) {
				*possibleMoves[nx][ny] = true;
				break;
			}
			else {
				break;
			}
			nx += dx[i];
			ny += dy[i];
		}
	}

}

void movementHandler::knightMoves() {

	resetMovement();

	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");
		
	int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2 };
	int dy[8] = { 1,  2, 2, 1, -1, -2, -2, -1 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			if (tableSquare[nx][ny]->piece.status == 0) {
				*possibleMoves[nx][ny] = true;
			}
			else if (tableSquare[nx][ny]->piece.getPieceStatus("color") != str) {
				*possibleMoves[nx][ny] = true;
			}
		}
	}

}

void movementHandler::queenMoves(){
	
	resetMovement();

	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");

	int dx[8] = { 1, -1,  1, -1 , 0, 0, 1, -1 };
	int dy[8] = { 1, -1, -1,  1 , 1, -1, 0, 0 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			if (tableSquare[nx][ny]->piece.status == 0) {
				*possibleMoves[nx][ny] = true;
			}
			else if (tableSquare[nx][ny]->piece.getPieceStatus("color") != str) {
				*possibleMoves[nx][ny] = true;
				break;
			}
			else {
				break;
			}
			nx += dx[i];
			ny += dy[i];
		}
	}

}

void movementHandler::kingMoves() {

	resetMovement();

	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");

	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
			if (tableSquare[nx][ny]->piece.status == 0) {
				*possibleMoves[nx][ny] = true;
			}
			else if (tableSquare[nx][ny]->piece.getPieceStatus("color") != str) {
				*possibleMoves[nx][ny] = true;
			}
		}
	}

}