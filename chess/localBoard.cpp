#include "localBoard.h"
#include "boardStats.h"

void localBoard::movementHandle(int i, int j, bool selected) {
	//Check if a tile is selected
	if (selected == true && squares[i][j].piece.getPieceStatus("name") != "empty") {
		movement.mainLoop(&squares[i][j].piece, possibleMoves, squares);
	}
}