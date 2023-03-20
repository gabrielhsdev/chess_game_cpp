#include "localBoard.h"
#include "boardStats.h"

void localBoard::movementHandle(int i, int j, bool selected) {
	//Check if a tile is selected
	if (selected == true && movement.getPieceName(&squares[i][j].piece) != "") {
		//cout << "\nMouse on: " << i << "," << j << " -- " << squares[i][j].piece.status;
		//cout << movement->getPieceName(&squares[i][j].piece) << "\n";
		movement.setPossibleMoves(&squares[i][j].piece);
	}
}