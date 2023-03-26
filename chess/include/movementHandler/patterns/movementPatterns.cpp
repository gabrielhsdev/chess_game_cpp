#include "../movementHandler/movementHandler.h"

void movementHandler::pawnMoves() {

	resetMovement();

	//Default variables
	int x = selected_X;
	int y = selected_Y;
	string str = piece->getPieceStatus("color");

	//Get pawn movement direction
	int dir = (str == "white") ? -1 : 1;

	//Checkl if pawn can move foward
	if (tableSquare[x + dir][y]->piece.status == 0) {
		*possibleMoves[x + dir][y] = true;
		//Check if +2 is avaliable for pawn
		if ((str == "white" && x == 6) || (str == "black" && x == 1)) {
			if (tableSquare[x + (2 * dir)][y]->piece.status == 0) {
				*possibleMoves[x + (2 * dir)][y] = true;
			}
		}
	}

	//Check for possible attack moves on left and right
	int xAdd = (str == "white") ? -1 : 1;
	x = x + xAdd;
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